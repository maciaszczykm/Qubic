#include "qbdatabase.h"

QbDatabase* QbDatabase::instance = NULL;

QbDatabase::QbDatabase()
{
    this->properties = QbProperties(QDir::currentPath()+"/qb.properties");

    QbLogger::getInstance()->info(QDir::currentPath()+"/qb.properties");

    this->driver = properties.getProperty("qubic.database.driver");
    this->hostname = properties.getProperty("qubic.database.hostname");
    this->dbname = properties.getProperty("qubic.database.dbname");
    this->username = properties.getProperty("qubic.database.username");
    this->password = properties.getProperty("qubic.database.password");
    this->db = QSqlDatabase::addDatabase(driver);
    db.setHostName(hostname);
    db.setDatabaseName(dbname);
    db.setUserName(username);
    db.setPassword(password);
    QbLogger::getInstance()->info("Database successfully initialized");
}

QbDatabase *QbDatabase::getInstance()
{
    if (instance == NULL) instance = new QbDatabase();
    return instance;
}

void QbDatabase::connect()
{
    if(db.open()) {
        QbLogger::getInstance()->info("Connected to database");
    } else {
        QbLogger::getInstance()->fatal("Cannot connect to database");
    }
}

void QbDatabase::store(QbPersistable& object)
{
    QbLogger::getInstance()->debug("Trying to store object");

    qDebug() << object.inherits("Employee");
    qDebug() << object.inherits("QbPersistable");
    qDebug() << object.inherits("QObject");

    qDebug() << object.metaObject()->className();
    qDebug() << object.metaObject()->superClass()->className();
    qDebug() << object.metaObject()->propertyCount();
    qDebug() << object.metaObject()->methodCount() << endl;
}



