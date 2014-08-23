#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QString>
#include <QObject>
#include <QDate>
#include <Qubic/Qubic.h>
#include <company.h>

class Employee : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Employee() {}
    Q_INVOKABLE Employee(const Employee& other);
    Q_INVOKABLE Employee(QDate birthday, QString firstname, QString lastname, QString gender, Company* companyPtr, QDateTime hiredate, double salary, int children);
    Q_INVOKABLE Employee(int id, QDate birthday, QString firstname, QString lastname, QString gender, Company* companyPtr, QDateTime hiredate, double salary, int children);
    Q_INVOKABLE QDate getBirthday() {return birthday;}
    Q_INVOKABLE QString getFirstname() {return firstname;}
    Q_INVOKABLE QString getLastname() {return lastname;}
    Q_INVOKABLE QString getGender() {return gender;}
    Q_INVOKABLE Company* getCompanyPtr() {return companyPtr;}
    Q_INVOKABLE QDateTime getHiredate() {return hiredate;}
    Q_INVOKABLE double getSalary() {return salary;}
    Q_INVOKABLE int getChildren() {return children;}
    Q_INVOKABLE void setBirthday(QDate birthday) {this->birthday = birthday;}
    Q_INVOKABLE void setFirstname(QString firstname) {this->firstname = firstname;}
    Q_INVOKABLE void setLastname(QString lastname) {this->lastname = lastname;}
    Q_INVOKABLE void setGender(QString gender) {this->gender = gender;}
    Q_INVOKABLE void setCompanyPtr(Company* companyPtr) {this->companyPtr = companyPtr;}
    Q_INVOKABLE void setHiredate(QDateTime hiredate) {this->hiredate = hiredate;}
    Q_INVOKABLE void setSalary(double salary) {this->salary = salary;}
    Q_INVOKABLE void setChildren(int children) {this->children = children;}
    QList<QbPersistable*> getPointers();
    QList<QbPersistable*> getDepartments();
    static QString CLASSNAME;
    static QString ID;
    static QString BIRTHDAY;
    static QString FIRSTNAME;
    static QString LASTNAME;
    static QString GENDER;
    static QString COMPANY;
    static QString HIREDATE;
    static QString SALARY;
    static QString CHILDREN;

private:
    Q_INVOKABLE void setCompanyPtr(QbPersistable* companyPtr) {this->companyPtr = (Company*) companyPtr;}
    QDate birthday;
    QString firstname;
    QString lastname;
    QString gender;
    Company* companyPtr;
    QDateTime hiredate;
    double salary;
    int children;
    static bool isRegistered;
};

Q_DECLARE_METATYPE(Employee)


#endif // EMPLOYEES_H
