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
    QSqlQuery insertQuery;
    if(insertQuery.exec(insertStatement)) QbLogger::getInstance()->debug("Store operation successfully completed");
    else QbLogger::getInstance()->debug("Store operation failed");
}

#include <QSqlDriver>

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
    QSqlQuery removeQuery;
    if(removeQuery.exec(removeStatement)) QbLogger::getInstance()->debug("Remove operation successfully completed");
    else QbLogger::getInstance()->debug("Remove operation failed");
}

void QbDatabase::update(QbPersistable& object)
{

}

QbPersistable QbDatabase::load(QbPersistable& object)
{

}

void QbDatabase::initTransactions()
{
    bool transactionsEnabledProperty = (properties.getProperty("qubic.transactions.enabled").toStdString().c_str() == "true");
    if(db.driver()->hasFeature(QSqlDriver::Transactions) && transactionsEnabledProperty)
    {
        QbLogger::getInstance()->info("Transactions successfully enabled");
        transactionsEnabled = true;
    }
    else
    {
        if(db.driver()->hasFeature(QSqlDriver::Transactions))
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
