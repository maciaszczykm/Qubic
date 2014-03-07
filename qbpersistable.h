#ifndef QBPERSISTABLE_H
#define QBPERSISTABLE_H

#include <QObject>
#include <QMetaMethod>

#include <qbproperties.h>

class QbPersistable : public QObject
{
    Q_OBJECT

public:
    QbPersistable() {}
    QbPersistable(const QbPersistable&) {}
    QString getObjectName();
    QString getObjectString();
};

#endif // QBPERSISTABLE_H
