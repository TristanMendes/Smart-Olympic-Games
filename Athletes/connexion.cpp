#include "connexion.h"

connexion::connexion()
{

}

bool connexion::createconnect()
{
    bool test= false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");//inserer le nom de la source de données ODBC
    db.setUserName("system");//inserer nom de l'utilisateur
    db.setPassword("Esprit7*tunis");//inserer le mot de passe de cet utilisateur

    if(db.open())
        test=true;
    return test;
}

void connexion::closeconnect(){db.close();}
