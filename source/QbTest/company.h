#ifndef COMPANY_H
#define COMPANY_H

#include <QString>
#include <QObject>
#include <QbCore/qbpersistable.h>
#include <QbUtilities/qbadvancedqueryhelper.h>

class Company : public QbPersistable
{
    Q_OBJECT

public:
    Q_INVOKABLE Company() {}
    Q_INVOKABLE Company(const Company& other);
    Q_INVOKABLE Company(QString companyname);
    Q_INVOKABLE Company(int id, QString companyname);
    Q_INVOKABLE QString getCompanyname() {return companyname;}
    Q_INVOKABLE void setCompanyname(QString companyname) {this->companyname = companyname;}
    QList<QbPersistable*> getPointers();
    QList<QbPersistable*> getEmployees();
    static QString CLASSNAME;
    static QString ID;
    static QString COMPANYNAME;

private:
    QString companyname;
    static bool isRegistered;
};

Q_DECLARE_METATYPE(Company)

#endif // COMPANY_H
