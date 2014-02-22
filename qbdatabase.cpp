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
    this->db = QSqlDatabase::addDatabase(driver);
    db.setHostName(hostname);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);
    QbLogger::getInstance()->info("Database " + hostname + ":" + dbname + " successfully initialized");
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
    QbLogger::getInstance()->debug("Reading object metadata");
    QMap<QString, QString> objectMembers;
    for(int i = 0; i < object.metaObject()->methodCount(); i++) {
        QMetaMethod method = object.metaObject()->method(i);
        if(method.name().startsWith(gettersPrefix.toStdString().c_str())) {
            QString memberName = method.name().right(method.name().length() - gettersPrefix.length());
            memberName = memberName.toUpper();
            QString memberValue;

            // ----------------------- test area ----------------------- //

            QGenericReturnArgument returnValue;
            qDebug() << method.invoke(&object,  Qt::DirectConnection, returnValue);

            objectMembers[memberName] = "";
        }
    }
    qDebug() << objectMembers;
    QbLogger::getInstance()->debug("Trying to store object");

    // ----------------------- test area ----------------------- //
}



