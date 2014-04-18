#include "qbdatabase.h"

QbDatabase* QbDatabase::instance = NULL;

QbDatabase::QbDatabase()
{
    QbLoggerHelper::initialize();
    QbPersistenceHelper::initializeDatabase();
    QbPersistenceHelper::initializeTransactions();
    QbPersistenceHelper::connect();
}

QbDatabase::~QbDatabase()
{
    QbPersistenceHelper::disconnect();
}

QbDatabase *QbDatabase::getInstance()
{
    if (instance == NULL) instance = new QbDatabase();
    return instance;
}

void QbDatabase::deleteInstance()
{
    delete instance;
    instance = NULL;
}

int QbDatabase::store(QbPersistable& object)
{
    return QbPersistenceHelper::store(object);
}

void QbDatabase::update(QbPersistable& object)
{
    QbPersistenceHelper::update(object);
}

void QbDatabase::remove(QbPersistable& object)
{
    QbPersistenceHelper::remove(object);
}

QList<QbPersistable*> QbDatabase::load(QbPersistable& object, int id)
{
    return QbPersistenceHelper::load(object, id);
}
