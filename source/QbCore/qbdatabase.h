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
#include <QbUtilities/qbpersistencehelper.h>
#include <QbCore/qbpersistable.h>
#include <QbCore/qbproperties.h>
#include <QsLog.h>

class QbDatabase
{
public:
    static QbDatabase* getInstance();
    static void deleteInstance();
    int store(QbPersistable& object);
    void update(QbPersistable &object);
    void remove(QbPersistable& object);
    QList<QbPersistable*> load(QbPersistable& object, int id = -1);

private:
    QbDatabase();
    ~QbDatabase();
    static QbDatabase* instance;

};

#endif // QBDATABASE_H
