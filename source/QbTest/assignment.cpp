#include "assignment.h"

QString Assignment::CLASSNAME = "Assignment";
QString Assignment::ID = "ID";
QString Assignment::DEPARTMENT = "DEPARTMENT";
QString Assignment::EMPLOYEE = "EMPLOYEE";
bool Assignment::isRegistered = false;

Assignment::Assignment(const Assignment &other)
{
    id = other.id;
    departmentPtr = other.departmentPtr;
    employeePtr = other.employeePtr;
}

Assignment::Assignment(Department *departmentPtr, Employee *employeePtr)
{

    if(!isRegistered)
    {
        qRegisterMetaType<Assignment>("Assignment");
        isRegistered = true;
    }
    this->id = -1;
    this->departmentPtr = departmentPtr;
    this->employeePtr = employeePtr;

}

Assignment::Assignment(int id, Department *departmentPtr, Employee *employeePtr)
{
    if(!isRegistered)
    {
        qRegisterMetaType<Assignment>("Assignment");
        isRegistered = true;
    }
    this->id = id;
    this->departmentPtr = departmentPtr;
    this->employeePtr = employeePtr;
}

QList<QbPersistable*> Assignment::getPointers()
{
    return QList<QbPersistable*>() << employeePtr << departmentPtr;
}
