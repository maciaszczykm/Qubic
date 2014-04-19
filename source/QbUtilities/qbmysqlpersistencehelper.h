#ifndef QBMYSQLPERSISTENCEHELPER_H
#define QBMYSQLPERSISTENCEHELPER_H

#include <QbUtilities/qbmysqlmappinghelper.h>
#include <QbUtilities/qbpersistencehelper.h>

class QbMySQLPersistenceHelper : public QbPersistenceHelper
{
public:
    static int store(QbPersistable& object);
    static void update(QbPersistable &object);
    static void remove(QbPersistable& object);
    static QList<QbPersistable*> load(QbPersistable& object, int id);

private:
    static int updateObjectIdentifier(QbPersistable& object);
    static void removeObjectIdentifier(QbPersistable& object);
};

#endif // QBMYSQLPERSISTENCEHELPER_H
