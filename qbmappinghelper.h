#ifndef QBMAPPINGHELPER_H
#define QBMAPPINGHELPER_H

#include <QString>
#include <QObject>
#include <QMetaMethod>
#include <QDebug>
#include <QDate>
#include <QDateTime>

#include <qbpersistable.h>
#include <qblogger.h>

class QbMappingHelper
{
public:
    QbMappingHelper() {}
    static QString getStringValue(QbPersistable &object, QMetaMethod method);
    static void setStringValue(QbPersistable *object, QMetaMethod method, QString value);

};

#endif // QBMAPPINGHELPER_H
