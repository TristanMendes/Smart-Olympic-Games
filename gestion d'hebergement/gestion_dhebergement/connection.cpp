#include "connection.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

//Test Tutoriel Git

connection::connection()
{

}

bool connection::createconnection()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("gestion_hebergement");//inserer le nom de la source de données ODBC
db.setUserName("fakhri");//inserer nom de l'utilisateur
db.setPassword("fakhri");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
