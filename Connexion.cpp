#include "Connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirConnexion()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Gestion_Stades");//inserer le nom de la source de données ODBC
db.setUserName("adam");//inserer nom de l'utilisateur
db.setPassword("system");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





   return  test;
}
