
#include "connection.h"

connection::connection()
{

}

bool connection::createConnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("soussi");
    db.setPassword("soussi");

    if(db.open())
        test = true;

   return test;
}
