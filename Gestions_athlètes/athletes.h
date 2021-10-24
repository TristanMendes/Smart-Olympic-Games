#ifndef ATHLETES_H
#define ATHLETES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Athletes
{
public:
    Athletes();
    Athletes(int,int, QString, QString, QString, QString, QString);
    int get_ID(){return ID;}
    int get_age(){return age;}
    QString get_Nom(){return Nom;}
    QString get_Prenom(){return Prenom;}
    QString get_nationalite(){return nationalite;}
    QString get_sexe(){return sexe;}
    bool ajouter();
    bool supprimer(int);
    bool Modifier(int);
    QSqlQueryModel* afficher();

private:
    int ID;
    int age;
    QString Nom, Prenom,nationalite,sexe,specialite;
};

#endif // ATHLETES_H
