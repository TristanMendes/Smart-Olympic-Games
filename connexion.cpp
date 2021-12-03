#include "connexion.h"
#include <QDebug>


Connection::Connection()
{}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("smart_olympic_games_g6");//inserer le nom de la source de données ODBC
db.setUserName("Mariem");//inserer nom de l'utilisateur
db.setPassword("esprit2A19G6");//inserer mot de passe de cet utilisateur
if (db.open())
test=true;
else qDebug()<< db.lastError().text();
return  test;}

void closeconnection()
{QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.close();}
