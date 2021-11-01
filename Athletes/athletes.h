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
    void set_Id(int Id);
    void set_Age(int Age);
    void set_Nom(QString Nom);
    void set_Prenom(QString Prenom);
    void set_Nationalite(QString Nationalite);
    void set_Sexe(QString Sexe);
    void set_Specialite(QString Specialite);
    void set_Mail(QString Mail);
    //getters
    int get_Id();
    int get_Age();
    QString get_Nom();
    QString get_Prenom();
    QString get_Nationalite();
    QString get_Specialite();
    QString get_Sexe();
    QString get_Mail();
    //fonctions de bases de l'entite athlètes.
    bool ajouter();
    //QSqlQueryModel* afficher();
   // bool Modifier(int);
    //bool supprimer(int);


private:
    int Id;
    int Age;
    QString Nom, Prenom,Nationalite,Sexe,Specialite,Mail;
};

#endif // ATHLETES_H
