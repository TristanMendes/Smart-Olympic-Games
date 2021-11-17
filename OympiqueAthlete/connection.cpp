#include "connection.h"

connection::connection()
{

}

bool connection::createconnection()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("ProjetOlympique");//inserer le nom de la source de données ODBC
db.setUserName("mendes");//inserer nom de l'utilisateur
db.setPassword("esprit");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}

void connection::closeconnection()
{
    db.close();
}
