#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <QString>
#include <QObject>
#include <Qubic/Qubic.h>
#include <department.h>
#include <employee.h>

class Assignment : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Assignment() {}
    Q_INVOKABLE Assignment(const Assignment& other);
    Q_INVOKABLE Assignment(Department* departmentPtr, Employee* employeePtr);
    Q_INVOKABLE Assignment(int id, Department* departmentPtr, Employee* employeePtr);
    Q_INVOKABLE Department* getDepartmentPtr() {return departmentPtr;}
    Q_INVOKABLE Department* setDepartmentPtr(Department* departmentPtr) {this->departmentPtr = departmentPtr;}
    Q_INVOKABLE Employee* getEmployeePtr() {return employeePtr;}
    Q_INVOKABLE Employee* setEmployeePtr(Employee* employeePtr) {this->employeePtr = employeePtr;}
    QList<QbPersistable*> getPointers();
    static QString CLASSNAME;
    static QString ID;
    static QString DEPARTMENT;
    static QString EMPLOYEE;

private:
    Q_INVOKABLE void setDepartmentPtr(QbPersistable* departmentPtr) {this->departmentPtr = (Department*) departmentPtr;}
    Q_INVOKABLE void setEmployeePtr(QbPersistable* employeePtr) {this->employeePtr = (Employee*) employeePtr;}
    Department* departmentPtr;
    Employee* employeePtr;
    static bool isRegistered;
};

Q_DECLARE_METATYPE(Assignment)

#endif // ASSIGNMENT_H
