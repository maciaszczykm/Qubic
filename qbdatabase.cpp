#include "qbdatabase.h"

QbDatabase* QbDatabase::instance = NULL;

QbDatabase::QbDatabase()
{
    this->properties = QbProperties(QDir::currentPath()+"/qb.properties");
    this->driver = properties.getProperty("qubic.database.driver");
    this->hostname = properties.getProperty("qubic.database.hostname");
    this->dbname = properties.getProperty("qubic.database.dbname");
    this->username = properties.getProperty("qubic.database.username");
    this->password = properties.getProperty("qubic.database.password");
    this->gettersPrefix = properties.getProperty("qubic.configuration.getters.prefix");
    this->settersPrefix = properties.getProperty("qubic.configuration.setters.prefix");
    this->tableIdentifier = properties.getProperty("qubic.configuration.table.identifier");
    this->ptrGettersSuffix = properties.getProperty("qubic.configuration.pointer.getters.suffix");
    this->db = QSqlDatabase::addDatabase(driver);
    db.setHostName(hostname);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);
    QbLogger::getInstance()->info("Database " + hostname + ":" + dbname + " successfully initialized");
    initTransactions();
}

QbDatabase *QbDatabase::getInstance()
{
    if (instance == NULL) instance = new QbDatabase();
    return instance;
}

void QbDatabase::connect()
{
    if(db.open()) QbLogger::getInstance()->info("Connected to database");
    else QbLogger::getInstance()->fatal("Cannot connect to database");
}

int QbDatabase::store(QbPersistable& object)
{
    QString objectName = object.getObjectUpperName();
    QString objectID = QString::number(object.getID());
    QString objectString = objectName + ":" + objectID;
    QbLogger::getInstance()->debug("Reading metadata of object " + objectString);
    if(object.getID() >= 0)
    {
        QbLogger::getInstance()->error("Object " + objectString + " is already stored, to update it use update method");
        return -1;
    }
    QbLogger::getInstance()->debug("Checking references of object " + objectString);
    QMap<QString, QString> objectMembers;
    QList<QbPersistable*> pointers = object.getPointers();
    QbLogger::getInstance()->debug(QString::number(pointers.size()) + " references to " + objectString + " found");
    for(int i = 0; i < pointers.size(); i++)
    {
        QbPersistable* ptr = pointers.at(i);
        int ptrId = ptr->getID();
        if(ptrId <= 0)
        {
            ptrId = store(*ptr);
        }
        objectMembers[ptr->getObjectUpperName()] = QString::number(ptrId);
    }
    QbLogger::getInstance()->info("Storing object " + objectString);
    for(int i = 0; i < object.metaObject()->methodCount(); i++)
    {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(gettersPrefix.toStdString().c_str()) && !method.name().endsWith(ptrGettersSuffix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - gettersPrefix.length());
            memberName = memberName.toUpper();
            if(memberName != tableIdentifier.toUpper())
            {
                objectMembers[memberName] = QbMappingHelper::getStringValue(object, method);
            }
        }
    }
    QbLogger::getInstance()->debug("Trying to store object " + objectString + " [" + object.getObjectString() + "]");
    QString columns = "(";
    QString values = "(";
    for(auto e : objectMembers.toStdMap()) {
        columns.append(e.first + ", ");
        values.append("'" + e.second + "', ");
    }
    columns = columns.left(columns.length() - 2) + ")";
    values = values.left(values.length() - 2) + ")";
    QString insertStatement = "INSERT INTO " + objectName + " " + columns + " VALUES " + values + ";";
    QbLogger::getInstance()->debug("SQL statement is ready " + insertStatement);
    if(transactionsEnabled) db.transaction();
    QSqlQuery insertQuery;
    if(insertQuery.exec(insertStatement))
    {
        if(transactionsEnabled) db.commit();
        QbLogger::getInstance()->debug("Store operation successfully completed");
        return updateObjectIdentifier(object);
    }
    else
    {
        if(transactionsEnabled) db.rollback();
        QbLogger::getInstance()->error("Store operation failed");
        QbLogger::getInstance()->error(insertQuery.lastError().text());
        return -1;
    }
}

int QbDatabase::updateObjectIdentifier(QbPersistable& object)
{
    int id = object.getID();
    QString idStatement = "SELECT MAX(" + tableIdentifier + ") FROM " + object.getObjectUpperName() + ";";
    QSqlQuery idQuery;
    if(idQuery.exec(idStatement))
    {
        if(idQuery.next())
        {
            id = idQuery.value(0).toInt();
        }
        QString idSetter = settersPrefix + tableIdentifier.toUpper();
        QMetaObject::invokeMethod(&object, idSetter.toStdString().c_str(), Q_ARG(int, id));
        QbLogger::getInstance()->debug("Object identifier updated to " + QString::number(id));
    }
    else
    {
        QbLogger::getInstance()->error("Cannot update object identifier");
        QbLogger::getInstance()->error(idQuery.lastError().text());
    }
    return id;
}

void QbDatabase::update(QbPersistable& object)
{
    QString objectName = object.getObjectUpperName();
    QString objectID = QString::number(object.getID());
    QString objectString = objectName + ":" + objectID;
    QbLogger::getInstance()->debug("Trying to update object " + objectString);
    if(objectID == "-1")
    {
        QbLogger::getInstance()->error("Update operation failed, object " + objectString + " is not stored yet");
        return;
    }
    QString objectMembers;
    QList<QbPersistable*> pointers = object.getPointers();
    QbLogger::getInstance()->debug(QString::number(pointers.size()) + " references to " + objectString + " found");
    for(int i = 0; i < pointers.size(); i++)
    {
        QbPersistable* ptr = pointers.at(i);
        int ptrId = ptr->getID();
        if(ptrId <= 0)
        {
            ptrId = store(*ptr);
        }
        objectMembers += ptr->getObjectUpperName() + "='" + QString::number(ptrId) + "', ";
    }
    QbLogger::getInstance()->info("Updating object " + objectString);
    for(int i = 0; i < object.metaObject()->methodCount(); i++)
    {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(gettersPrefix.toStdString().c_str()) && !method.name().endsWith(ptrGettersSuffix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - gettersPrefix.length());
            memberName = memberName.toUpper();
            if(memberName != tableIdentifier.toUpper())
            {
                objectMembers += memberName + "='" + QbMappingHelper::getStringValue(object, method) + "', ";
            }
        }
    }
    QbLogger::getInstance()->debug("Trying to update object " + objectString + " [" + object.getObjectString() + "]");
    objectMembers = objectMembers.left(objectMembers.length() - 2);
    QString updateStatement = "UPDATE " + objectName + " SET " + objectMembers + " WHERE ID = " + object.getID() + ";";
    QbLogger::getInstance()->debug("SQL statement is ready " + updateStatement);
    if(transactionsEnabled) db.transaction();
    QSqlQuery updateQuery;
    if(updateQuery.exec(updateStatement))
    {
        if(transactionsEnabled) db.commit();
        QbLogger::getInstance()->debug("Update operation successfully completed");
    }
    else
    {
        if(transactionsEnabled) db.rollback();
        QbLogger::getInstance()->error("Update operation failed");
        QbLogger::getInstance()->error(updateQuery.lastError().text());
    }
}

void QbDatabase::remove(QbPersistable& object)
{
    QString objectName = object.getObjectUpperName();
    QString objectID = QString::number(object.getID());
    QString objectString = objectName + ":" + objectID;
    QbLogger::getInstance()->info("Trying to remove object " + objectString);
    if(objectID == "-1")
    {
        QbLogger::getInstance()->error("Remove operation failed, object " + objectString + " is not stored yet");
        return;
    }
    QbLogger::getInstance()->debug("Trying to remove object " + objectString + " [" + object.getObjectString() + "]");
    QString removeStatement = "DELETE FROM " + objectName + " WHERE " + tableIdentifier.toUpper() + "=" + objectID + ";";
    QbLogger::getInstance()->debug("SQL statement is ready " + removeStatement);
    if(transactionsEnabled) db.transaction();
    QSqlQuery removeQuery;
    if(removeQuery.exec(removeStatement))
    {
        if(transactionsEnabled) db.commit();
        QbLogger::getInstance()->debug("Remove operation successfully completed");
    }
    else
    {
        if(transactionsEnabled) db.rollback();
        QbLogger::getInstance()->error("Remove operation failed");
        QbLogger::getInstance()->error(removeQuery.lastError().text());
    }
}

QList<QbPersistable*> QbDatabase::load(QbPersistable& object)
{
    /*QString objectName = object.getObjectUpperName();
    QbLogger::getInstance()->debug("Reading metadata of object " + objectName);
    QString selectStatement = "SELECT ";
    QMap<QString, QString> objectMembers;
    for(int i = 0; i < object.metaObject()->methodCount(); i++)
    {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(settersPrefix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - settersPrefix.length());
            memberName = memberName.toUpper();
            objectMembers[memberName] = "";
            selectStatement.append(memberName + ", ");
        }
    }
    QbLogger::getInstance()->debug("Trying to load objects " + objectName + " from database");
    selectStatement = selectStatement.left(selectStatement.length() - 2) + " FROM " + objectName + ";";
    QbLogger::getInstance()->debug("SQL statement is ready " + selectStatement);
    QSqlQuery selectQuery;
    QList<QbPersistable*> result = QList<QbPersistable*>();
    if(selectQuery.exec(selectStatement))
    {
        QString className = object.metaObject()->className();
        QByteArray byteArray = className.toLocal8Bit();
        int classId = QMetaType::type(byteArray.constData());
        if(classId > 0)
        {
            while(selectQuery.next())
            {
                void *classPtr = QMetaType::create(classId);
                if (classPtr == 0)
                {
                    QbLogger::getInstance()->error("Load operation failed, cannot initialize " + className + " object");
                    return result;
                }
                QbPersistable *ptr = (QbPersistable*) classPtr;
                for(int i = 0; i < ptr->metaObject()->methodCount(); i++)
                {
                    QMetaMethod method = ptr->metaObject()->method(i);
                    if(method.name().startsWith(settersPrefix.toStdString().c_str()))
                    {
                        QString memberName = method.name().right(method.name().length() - settersPrefix.length());
                        memberName = memberName.toUpper();
                        QString memberValue = selectQuery.value(memberName).toString();
                        QbMappingHelper::setStringValue(ptr, method, memberValue);
                    }
                }
                result.append(ptr);
            }
            QbLogger::getInstance()->debug("Load operation successfully completed");
            return result;
        }
        else
        {
            QbLogger::getInstance()->error("Load operation failed, class " + className + " is not registered as Qt meta type");
            return result;
        }
    }
    else
    {
        QbLogger::getInstance()->error("Load operation failed");
        QbLogger::getInstance()->error(selectQuery.lastError().text());
        return result;
    }*/
}

void QbDatabase::initTransactions()
{
    bool transactionsEnabledProperty = (properties.getProperty("qubic.transactions.enabled").toStdString() == "true");
    if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions) && transactionsEnabledProperty)
    {
        QbLogger::getInstance()->info("Transactions successfully enabled");
        transactionsEnabled = true;
    }
    else
    {
        if(QSqlDatabase::database().driver()->hasFeature(QSqlDriver::Transactions))
        {
            QbLogger::getInstance()->info("Transactions disabled");
            transactionsEnabled = false;
        }
        else
        {
            QbLogger::getInstance()->info("Transactions disabled, your database does not support them");
            transactionsEnabled = false;
        }
    }
}
