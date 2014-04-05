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
    Employee employee1 (birthday, "Jan", "Kowalski", "M", &company1, hiredate, 2790.5, 2);
    Employee employee2 (birthday, "Piotr", "Pawłowski", "M", &company1, hiredate, 2290.5, 0);
    db->store(employee1);
    db->store(employee2);

    Company company2 ("Facebook");
    employee1.setFirstname("Zenon");
    employee2.setCompanyPtr(&company2);
    db->update(employee2);

    //Employee empty;
    //QList<QbPersistable*> list = db->load(empty);
    //Employee* sample = (Employee*) list.at(list.size() - 1);
    //qDebug() << sample->getObjectString();
    //qDebug() << list.size() << sample->metaObject()->className() << " objects loaded";

    //db->remove(employee1);
    //db->remove(employee2);
    //db->remove(company1);
    //db->remove(company2);

    return app.exec();
}
