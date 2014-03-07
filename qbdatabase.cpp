#include "qbdatabase.h"
#include <QSqlDriver>

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

void QbDatabase::store(QbPersistable& object)
{
    QString objectName = object.getObjectName();
    QbLogger::getInstance()->debug("Reading metadata of object " + objectName);
    QMap<QString, QString> objectMembers;
    for(int i = 0; i < object.metaObject()->methodCount(); i++)
    {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(gettersPrefix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - gettersPrefix.length());
            memberName = memberName.toUpper();
            QString memberValue;
            QMetaObject::invokeMethod(&object,method.name(), Q_RETURN_ARG(QString, memberValue));
            objectMembers[memberName] = memberValue;
        }
    }
    QbLogger::getInstance()->debug("Trying to store object " + objectName + " [" + object.getObjectString() + "]");
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
    }
    else
    {
        if(transactionsEnabled) db.rollback();
        QbLogger::getInstance()->error("Store operation failed");
    }
}

void QbDatabase::remove(QbPersistable& object, bool removeAllEntries)
{
    QString objectName = object.getObjectName();
    QbLogger::getInstance()->debug("Reading metadata of object " + objectName);
    QMap<QString, QString> objectMembers;
    for(int i = 0; i < object.metaObject()->methodCount(); i++)
    {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(gettersPrefix.toStdString().c_str()))
        {
            QString memberName = method.name().right(method.name().length() - gettersPrefix.length());
            memberName = memberName.toUpper();
            QString memberValue;
            QMetaObject::invokeMethod(&object,method.name(), Q_RETURN_ARG(QString, memberValue));
            objectMembers[memberName] = memberValue;
        }
    }
    QbLogger::getInstance()->debug("Trying to remove object " + objectName + " [" + object.getObjectString() + "]");
    QString removeStatement = "DELETE FROM " + objectName + " WHERE ";
    for(auto e : objectMembers.toStdMap()) {
        removeStatement.append(e.first + "='" + e.second + "' AND ");
    }
    removeStatement = removeStatement.left(removeStatement.length() - 5);
    if(removeAllEntries) removeStatement.append(";");
    else removeStatement.append(" LIMIT 1;");
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
    }
}

void QbDatabase::update(QbPersistable& object)
{

}

QList<QbPersistable*> QbDatabase::load(QbPersistable& object)
{
    QString objectName = object.getObjectName();
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
                QbLogger::getInstance()->debug("Object " + className + " ready to fill with data");
                for(int i = 0; i < ptr->metaObject()->methodCount(); i++)
                {
                    QMetaMethod method = ptr->metaObject()->method(i);
                    if(method.name().startsWith(settersPrefix.toStdString().c_str()))
                    {
                        QString memberName = method.name().right(method.name().length() - settersPrefix.length());
                        memberName = memberName.toUpper();
                        QString memberValue = selectQuery.value(memberName).toString();
                        QMetaObject::invokeMethod(&object,method.name(), Q_ARG(QString, memberValue));
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
        return result;
    }
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
