#include "connection.h"

connection::connection()
{

}

bool connection::createConnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("");
    db.setPassword("");

    if(db.open())
        test = true;

   return test;
}
