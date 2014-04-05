#ifndef QBDATABASE_H
#define QBDATABASE_H

#include <QMetaMethod>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QMetaObject>
#include <QMetaType>
#include <QDebug>
#include <QList>
#include <QSqlDriver>
#include <QSqlError>

#include <qbmappinghelper.h>
#include <qblogger.h>
#include <qbpersistable.h>
#include <qbproperties.h>

class QbDatabase
{
public:
    void connect();
    QList<QbPersistable*> load(QbPersistable& object, int id = -1);
    int store(QbPersistable& object);
    void update(QbPersistable &object);
    void remove(QbPersistable& object);
    static QbDatabase* getInstance();

private:
    QbDatabase();
    void initTransactions();
    int updateObjectIdentifier(QbPersistable& object);
    static QbDatabase* instance;
    QbProperties properties;
    QSqlDatabase db;
    QString driver;
    QString hostname;
    QString dbname;
    QString username;
    QString password;
    QString gettersPrefix;
    QString settersPrefix;
    QString ptrGettersSuffix;
    QString tableIdentifier;
    bool transactionsEnabled;
};

#endif // QBDATABASE_H
