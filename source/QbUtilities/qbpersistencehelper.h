#ifndef QBPERSISTENCEHELPER_H
#define QBPERSISTENCEHELPER_H

#include <QsLog.h>
#include <QString>
#include <QSqlDriver>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QbCore/qbproperties.h>
#include <QbCore/qbpersistable.h>
#include <QbUtilities/qbmappinghelper.h>

class QbPersistenceHelper
{
public:
    static int store(QbPersistable& object);
    static void update(QbPersistable &object);
    static void remove(QbPersistable& object);
    static QList<QbPersistable*> load(QbPersistable& object, int id);
    static void initializeTransactions();
    static int updateObjectIdentifier(QbPersistable& object);
    static void removeObjectIdentifier(QbPersistable& object);
    static void initializeDatabase();
    static void connect();
    static void disconnect();

private:
    static bool transactionsEnabled;
    static QSqlDatabase db;
};

#endif // QBPERSISTENCEHELPER_H
