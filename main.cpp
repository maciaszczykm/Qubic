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

    QDate birthday(1995, 5, 17);
    QDateTime hiredate = QDateTime::currentDateTime();
    Employee employee (birthday, "Jan", "Kowalski", "M", hiredate, 2790.5, 2);
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
