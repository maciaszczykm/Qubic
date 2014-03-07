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

    //read
    Employee empty;
    QList<QbPersistable*> list = db->load(empty);
    for(int i = 0; i < list.size(); i++) qDebug() << list.at(i)->getObjectString();
    qDebug() << list.size() << list.at(0)->metaObject()->className() << " objects loaded";

    //delete
    db->remove(employee);

    return app.exec();
}
