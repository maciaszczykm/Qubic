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
#include <QbUtilities/qbmappinghelper.h>
#include <QbUtilities/qbloggerhelper.h>
#include <QbCore/qbpersistable.h>
#include <QbCore/qbproperties.h>
#include <QsLog.h>

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
    void initializeDatabase();
    void initializeTransactions();
    void loadProperties();
    int updateObjectIdentifier(QbPersistable& object);
    static QbDatabase* instance;
    QSqlDatabase db;
    QString gettersPrefix;
    QString settersPrefix;
    QString ptrGettersSuffix;
    QString tableIdentifier;
    bool transactionsEnabled;
};

#endif // QBDATABASE_H
