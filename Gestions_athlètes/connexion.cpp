#include "connexion.h"

Connexion::Connexion()
{

}

bool Connexion::createconnect()
{
    bool test= false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("test-bd");
    db.setUserName("system");
    db.setPassword("Esprit7*tunis");

    if(db.open())
        test=true;
    return test;
}
