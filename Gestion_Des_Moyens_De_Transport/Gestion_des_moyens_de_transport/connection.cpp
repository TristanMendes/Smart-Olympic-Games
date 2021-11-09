#include "connection.h"
#include <QtDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Smart_Olympic_Games");//inserer le nom de la source de données ODBC
db.setUserName("Nada");//inserer nom de l'utilisateur
db.setPassword("Esprit23");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;
else
    qDebug()<< db.lastError().text();




    return  test;





}
