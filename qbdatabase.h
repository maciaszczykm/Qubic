#ifndef QBDATABASE_H
#define QBDATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDir>
#include <QMetaObject>

#include <qblogger.h>
#include <qbpersistable.h>
#include <qbproperties.h>

class QbDatabase
{
public:
    void connect();
    void store(QbPersistable& object);
    static QbDatabase* getInstance();
private:
    QbDatabase();
    static QbDatabase* instance;
    QbProperties properties;
    QSqlDatabase db;
    QString driver;
    QString hostname;
    QString dbname;
    QString username;
    QString password;
};

#endif // QBDATABASE_H
