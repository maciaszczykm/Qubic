#include <QCoreApplication>
#include <qbdatabase.h>
#include <qblogger.h>
#include <employee.h>
#include <qbpersistable.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);


    QbDatabase* db = QbDatabase::getInstance();
    db->connect();

    Employee employee ("1953-09-02", "Jan", "Kowalski", "M", "1986-06-26");
    db->store(employee);

    employee.setFirstname("Zenon");
    db->update(employee);

    Employee empty;
    QList<QbPersistable*> list = db->load(empty);
    Employee* sample = (Employee*) list.at(list.size() - 1);
    qDebug() << sample->getObjectString();
    qDebug() << list.size() << sample->metaObject()->className() << " objects loaded";

    db->remove(employee);

    return app.exec();
}
