#ifndef ATHLETES_H
#define ATHLETES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Athletes
{
public:
    //constructeurs
    Athletes();
    Athletes(int,int, QString, QString, QString, QString, QString,QString);
    //setters
    void set_ID(int ID);
    void set_age(int age);
    void set_Nom(QString Nom);
    void set_Prenom(QString Prenom);
    void set_nationalite(QString nationalite);
    void set_sexe(QString sexe);
    void set_specialite(QString specialite);
    void set_mail(QString mail);
    //getters
    int get_ID();
    int get_age();
    QString get_Nom();
    QString get_Prenom();
    QString get_nationalite();
    QString get_specialite();
    QString get_sexe();
    QString get_mail();
    //fonctions de bases de l'entite athlètes.
    bool ajouter();
    QSqlQueryModel* afficher();
    bool Modifier(int);
    bool supprimer(int);


private:
    int ID;
    int age;
    QString Nom, Prenom,nationalite,sexe,specialite,mail;
};

#endif // ATHLETES_H
