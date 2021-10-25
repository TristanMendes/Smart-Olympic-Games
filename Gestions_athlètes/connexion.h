#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class Connexion
{
private:
    QSqlDatabase db;
public:
    Connexion();
    bool createconnect();
    void closeconnect();
};

#endif // CONNEXION_H
