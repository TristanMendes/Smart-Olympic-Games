#include "Connexion.h"

Connexion::Connexion()
{

}

bool Connexion::ouvrirConnexion()
{
    bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");//L’attribut db sera initialisé dans la méthode createconnection() qui établie la connexion à la BD
db.setDatabaseName("Gestion stades");//inserer le nom de la source de données ODBC
db.setUserName("adam");//inserer nom de l'utilisateur
db.setPassword("adam");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





   return  test;
}
void Connexion::fermerConnexion(){db.close();}
