#include <QCoreApplication>
#include <QbCore/qbdatabase.h>
#include <QbCore/qbpersistable.h>
#include <QbTest/employee.h>
#include <QbTest/company.h>
#include <QsLog/QsLog.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    Company company1 ("Google");
    QDate birthday(1995, 5, 17);
    QDateTime hiredate = QDateTime::currentDateTime();
    Employee employee1 (birthday, "Lee", "Jones", "M", &company1, hiredate, 2790.5, 2);
    Employee employee2 (birthday, "Joe", "Smith", "M", &company1, hiredate, 2290.5, 0);
    QbDatabase::getInstance()->store(employee1);
    QbDatabase::getInstance()->store(employee2);

    Company company2 ("Facebook");
    employee2.setFirstname("Ryo");
    employee2.setCompanyPtr(&company2);
    QbDatabase::getInstance()->update(employee2);

    Employee empty;
    QList<QbPersistable*> list = QbDatabase::getInstance()->load(empty);
    for(int i=0; i<list.size(); i++)
    {
        Employee* loaded = (Employee*) list.at(i);
        qDebug() << loaded->getID() << "\t" << loaded->getFirstname() << "\t" << loaded->getLastname() << "\t" << loaded->getCompanyPtr()->getCompanyname();
    }

    QbDatabase::getInstance()->remove(employee1);
    QbDatabase::getInstance()->remove(employee2);
    QbDatabase::getInstance()->remove(company1);
    QbDatabase::getInstance()->remove(company2);

    QbDatabase::deleteInstance();

    return app.exec();
}
