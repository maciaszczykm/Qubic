#include "employee.h"

Employee::Employee(QString birthday, QString firstname, QString lastname, QString gender, QString hiredate)
{
    this->id = "-1";
    this->birthday = birthday;
    this->firstname = firstname;
    this->lastname = lastname;
    this->gender = gender;
    this->hiredate = hiredate;
}

Employee::Employee(QString id, QString birthday, QString firstname, QString lastname, QString gender, QString hiredate)
{
    this->id = id;
    this->birthday = birthday;
    this->firstname = firstname;
    this->lastname = lastname;
    this->gender = gender;
    this->hiredate = hiredate;
}

Employee::Employee(const Employee& other)
{
    id = other.id;
    birthday = other.birthday;
    firstname = other.firstname;
    lastname = other.lastname;
    gender = other.gender;
    hiredate = other.hiredate;
}
