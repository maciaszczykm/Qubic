#include "department.h"
#include <QbTest/employee.h>
#include <QbTest/assignment.h>

QString Department::CLASSNAME = "Department";
QString Department::ID = "ID";
QString Department::DEPARTMENTNAME = "DEPARTMENTNAME";
bool Department::isRegistered = false;

Department::Department(QString departmentname)
{
    if(!isRegistered)
    {
        qRegisterMetaType<Department>("Department");
        isRegistered = true;
    }
    this->id = -1;
    this->departmentname = departmentname;
}

Department::Department(int id, QString departmentname)
{
    if(!isRegistered)
    {
        qRegisterMetaType<Department>("Department");
        isRegistered = true;
    }
    this->id = id;
    this->departmentname = departmentname;
}

Department::Department(const Department& other)
{
    id = other.id;
    departmentname = other.departmentname;
}

QList<QbPersistable*> Department::getPointers() {
    return QList<QbPersistable*>();
}

QList<QbPersistable*> Department::getEmployees() {
    return QbAdvancedQueryHelper::queryManyToMany(Employee::CLASSNAME, CLASSNAME, Assignment::CLASSNAME, id);
}
