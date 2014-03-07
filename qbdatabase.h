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

#include <qblogger.h>
#include <qbpersistable.h>
#include <qbproperties.h>

class QbDatabase
{
public:
    void connect();
    QList<QbPersistable*> load(QbPersistable& object);
    void store(QbPersistable& object);
    void update(QbPersistable& oldObject, QbPersistable &newObject, bool removeAllEntries = false);
    void remove(QbPersistable& object, bool removeAllEntries = false);
    static QbDatabase* getInstance();

private:
    QbDatabase();
    void initTransactions();
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
    bool transactionsEnabled;
};

#endif // QBDATABASE_H
