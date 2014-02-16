#ifndef QBPROPERTIES_H
#define QBPROPERTIES_H

#include <QMap>
#include <QFile>
#include <QString>
#include <QStringList>
#include <qblogger.h>
#include <QTextStream>

class QbProperties
{
public:
    QbProperties();
    QbProperties(QString path);
    QString getProperty(QString property);
    void setProperty(QString property, QString value);
    void store();
private:
    QMap<QString,QString> properties;
    QString path;
};

#endif // QBPROPERTIES_H
