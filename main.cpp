#include <QCoreApplication>
#include <qbproperties.h>
#include <qbdatabase.h>
#include <qblogger.h>
#include <employee.h>

int main(int argc, char *argv[])
{
    QCoreApplication app( argc, argv );
    QbDatabase* db = QbDatabase::getInstance();
    db->connect();

    // ----------------------- test area ----------------------- //
    Employee emp ("99999","1953-09-02","Marcin","Maciaszczyk","M","1986-06-26");


    db->store(emp);
    //cout << db->read(emp);
    //emp.firstname = "Piotr";
    //db->store(emp);
    //cout << db->read(emp);
    //db->remove(emp);

    // ----------------------- test area ----------------------- //

    return app.exec();
}
