#include "employee.h"

Employee::Employee(QString id, QString birthday, QString firstname, QString lastname, QString gender, QString hiredate)
{
    this->id = id;
    this->birthday = birthday;
    this->firstname = firstname;
    this->lastname = lastname;
    this->gender = gender;
    this->hiredate = hiredate;
}
