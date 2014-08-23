#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <QString>
#include <QObject>
#include <Qubic/Qubic.h>

class Department : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Department() {}
    Q_INVOKABLE Department(const Department& other);
    Q_INVOKABLE Department(QString departmentname);
    Q_INVOKABLE Department(int id, QString departmentname);
    Q_INVOKABLE QString getDepartmentname() {return departmentname;}
    Q_INVOKABLE void setDepartmentname(QString departmentname) {this->departmentname = departmentname;}
    QList<QbPersistable*> getPointers();
    QList<QbPersistable*> getEmployees();
    static QString CLASSNAME;
    static QString ID;
    static QString DEPARTMENTNAME;

private:
    QString departmentname;
    static bool isRegistered;
};

Q_DECLARE_METATYPE(Department)

#endif // DEPARTMENT_H
