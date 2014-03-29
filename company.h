#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QObject>

#include <qbpersistable.h>

class Company : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Company() {}
    Q_INVOKABLE Company(const Company& other);
    Q_INVOKABLE Company(QString companyname);
    Q_INVOKABLE Company(int id, QString companyname);
    Q_INVOKABLE int getID() {return id;}
    Q_INVOKABLE QString getCompanyname() {return companyname;}
    Q_INVOKABLE void setCompanyname(QString companyname) {this->companyname = companyname;}

private:
    Q_INVOKABLE void setID(int id) {this->id = id;}
    int id;
    QString companyname;
    static bool isRegistered;

};

Q_DECLARE_METATYPE(Company)

#endif // COMPANY_H
