#include "employee.h"

Employee::Employee(QString number, QString birthday, QString firstname, QString lastname, QString gender, QString hiredate)
{
    this->number = number;
    this->birthday = birthday;
    this->firstname = firstname;
    this->lastname = lastname;
    this->gender = gender;
    this->hiredate = hiredate;
}

Employee::Employee() {

}
