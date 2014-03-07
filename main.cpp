#include <QCoreApplication>
#include <qbdatabase.h>
#include <qblogger.h>
#include <employee.h>
#include <qbpersistable.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    //meta types registration
    qRegisterMetaType<Employee>("Employee");

    //connection with database
    QbDatabase* db = QbDatabase::getInstance();
    db->connect();

    //create
    Employee employee ("123", "1953-09-02", "Jan", "Kowalski", "M", "1986-06-26");
    db->store(employee);

    //update
    Employee updated = employee;
    updated.setFirstname("Zenon");
    updated.setID("52");
    db->update(employee, updated);

    //read
    Employee empty;
    QList<QbPersistable*> list = db->load(empty);
    Employee* sample = (Employee*) list.at(list.size() - 1);
    qDebug() << sample->getObjectString();
    qDebug() << list.size() << sample->metaObject()->className() << " objects loaded";

    //delete
    db->remove(employee);

    return app.exec();
}
