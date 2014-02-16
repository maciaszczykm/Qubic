#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QString>
#include <QObject>

#include <qbpersistable.h>

class Employee : public QbPersistable
{
    Q_OBJECT
public:
    Employee();
    Employee(QString number, QString birthday, QString firstname, QString lastname, QString gender, QString hiredate);
    QString number;
    QString birthday;
    QString firstname;
    QString lastname;
    QString gender;
    QString hiredate;
};

#endif // EMPLOYEES_H
