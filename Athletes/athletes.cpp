#include "athletes.h"
#include <QSqlQuery>
#include <QtDebug>

Athletes::Athletes()
{
    Id=0;
    Age=0;
    Nom="";
    Prenom="";
    Nationalite="";
    Sexe="";
    Specialite="";
    Mail="";

}

Athletes::Athletes(int Id,int Age, QString Nom, QString Prenom, QString Nationalite, QString Sexe, QString Specialite, QString Mail)
{
    this->Id=Id;
    this->Age=Age;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->Nationalite=Nationalite;
    this->Sexe=Sexe;
    this->Specialite=Specialite;
    this->Mail=Mail;

}
int Athletes::get_Id(){return Id;}
int Athletes::get_Age(){return Age;}
QString Athletes::get_Nom(){return Nom;}
QString Athletes::get_Prenom(){return Prenom;}
QString Athletes::get_Nationalite(){return Nationalite;}
QString Athletes::get_Sexe(){return Sexe;}
QString Athletes::get_Specialite(){return Specialite;}
QString Athletes::get_Mail(){return Mail;}
void Athletes::set_Id(int Id){this->Id=Id;}
void Athletes::set_Age(int Age){this->Age=Age;}
void Athletes::set_Nom(QString Nom){this->Nom=Nom;}
void Athletes::set_Prenom(QString Prenom){this->Prenom=Prenom;}
void Athletes::set_Nationalite(QString Nationalite){this->Nationalite=Nationalite;}
void Athletes::set_Sexe(QString Sexe){this->Sexe=Sexe;}
void Athletes::set_Specialite(QString Specialite){this->Specialite=Specialite;}
void Athletes::set_Mail(QString Mail){this->Mail=Mail;}

bool Athletes::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(Id);
    QString Age_string=QString::number(Age);
    query.prepare("insert into ahtlete (ID,Nom,Prenom,Nationalite,Sexe,Age,Specialite,Mail)""values(:ID, :NOM, :PRENOM, :NATIONALITE, :SEXE, :AGE, :SPECIALITE, :MAIL)");
    query.bindValue(":Id",id_string);
    query.bindValue(":Age",Age_string);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Prenom",Prenom);
    query.bindValue(":nationalite",Nationalite);
    query.bindValue(":sexe",Sexe);
    query.bindValue(":specialite",Specialite);
    query.bindValue(":mail",Mail);

    return query.exec();
}

