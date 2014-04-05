#include <QCoreApplication>
#include <qbdatabase.h>
#include <qblogger.h>
#include <employee.h>
#include <company.h>
#include <qbpersistable.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QbDatabase* db = QbDatabase::getInstance();
    db->connect();

    Company company1 ("Google");
    QDate birthday(1995, 5, 17);
    QDateTime hiredate = QDateTime::currentDateTime();
    Employee employee1 (birthday, "Lee", "Jones", "M", &company1, hiredate, 2790.5, 2);
    Employee employee2 (birthday, "Joe", "Smith", "M", &company1, hiredate, 2290.5, 0);
    db->store(employee1);
    db->store(employee2);

    Company company2 ("Facebook");
    employee2.setFirstname("Ryo");
    employee2.setCompanyPtr(&company2);
    db->update(employee2);

    Employee empty;
    QList<QbPersistable*> list = db->load(empty);
    for(int i=0; i<list.size(); i++)
    {
        Employee* loaded = (Employee*) list.at(i);
        qDebug() << loaded->getID() << "\t" << loaded->getFirstname() << "\t" << loaded->getLastname() << "\t" << loaded->getCompanyPtr()->getCompanyname();
    }

    db->remove(employee1);
    db->remove(employee2);
    db->remove(company1);
    db->remove(company2);

    return app.exec();
}
