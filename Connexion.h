#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{
    QSqlDatabase db ; //db attribut de la classe Connexion
public:
    Connexion();
    bool ouvrirConnexion();
    void fermerConnexion();
};

#endif // CONNEXION_H
