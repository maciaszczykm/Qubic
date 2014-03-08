#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QString>
#include <QObject>

#include <qbpersistable.h>

class Employee : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Employee() {}
    Q_INVOKABLE Employee(const Employee& other);
    Q_INVOKABLE Employee(QString id, QString birthday, QString firstname, QString lastname, QString gender, QString hiredate);
    Q_INVOKABLE QString getID() {return id;}
    Q_INVOKABLE QString getBirthday() {return birthday;}
    Q_INVOKABLE QString getFirstname() {return firstname;}
    Q_INVOKABLE QString getLastname() {return lastname;}
    Q_INVOKABLE QString getGender() {return gender;}
    Q_INVOKABLE QString getHiredate() {return hiredate;}
    Q_INVOKABLE void setID(QString id) {this->id = id;}
    Q_INVOKABLE void setBirthday(QString birthday) {this->birthday = birthday;}
    Q_INVOKABLE void setFirstname(QString firstname) {this->firstname = firstname;}
    Q_INVOKABLE void setLastname(QString lastname) {this->lastname = lastname;}
    Q_INVOKABLE void setGender(QString gender) {this->gender = gender;}
    Q_INVOKABLE void setHiredate(QString hiredate) {this->hiredate = hiredate;}

private:
    QString id;
    QString birthday;
    QString firstname;
    QString lastname;
    QString gender;
    QString hiredate;
};

Q_DECLARE_METATYPE(Employee)


#endif // EMPLOYEES_H
