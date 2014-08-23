#include "company.h"
#include <employee.h>

QString Company::CLASSNAME = "Company";
QString Company::ID = "ID";
QString Company::COMPANYNAME = "COMPANYNAME";
bool Company::isRegistered = false;

Company::Company(QString companyname)
{
    if(!isRegistered)
    {
        qRegisterMetaType<Company>("Company");
        isRegistered = true;
    }
    this->id = -1;
    this->companyname = companyname;
}

Company::Company(int id, QString companyname)
{
    if(!isRegistered)
    {
        qRegisterMetaType<Company>("Company");
        isRegistered = true;
    }
    this->id = id;
    this->companyname = companyname;
}

Company::Company(const Company& other)
{
    id = other.id;
    companyname = other.companyname;
}

QList<QbPersistable*> Company::getPointers() {
    return QList<QbPersistable*>();
}

QList<QbPersistable*> Company::getEmployees() {
    return QbAdvancedQueryHelper::queryOneToMany(Employee::CLASSNAME, CLASSNAME, id);
}
