#include "athletes.h"
#include <QSqlQuery>
#include <QtDebug>

Athletes::Athletes()
{
    ID=0;
    age=0;
    Nom="";
    Prenom="";
    nationalite="";
    sexe="";
    specialite="";
    mail="";
}

Athletes::Athletes(int ID,int age, QString Nom, QString Prenom, QString nationalite, QString sexe, QString specialite, QString mail)
{
    this->ID=ID;
    this->age=age;
    this->Nom=Nom;
    this->Prenom=Prenom;
    this->nationalite=nationalite;
    this->sexe=sexe;
    this->specialite=specialite;
    this->mail=mail;

}
int Athletes::get_ID(){return ID;}
int Athletes::get_age(){return age;}
QString Athletes::get_Nom(){return Nom;}
QString Athletes::get_Prenom(){return Prenom;}
QString Athletes::get_nationalite(){return nationalite;}
QString Athletes::get_sexe(){return sexe;}
QString Athletes::get_specialite(){return specialite;}
QString Athletes::get_mail(){return mail;}
void Athletes::set_ID(int ID){this->ID=ID;}
void Athletes::set_age(int age){this->age=age;}
void Athletes::set_Nom(QString Nom){this->Nom=Nom;}
void Athletes::set_Prenom(QString Prenom){this->Prenom=Prenom;}
void Athletes::set_nationalite(QString nationalite){this->nationalite=nationalite;}
void Athletes::set_sexe(QString sexe){this->sexe=sexe;}
void Athletes::set_specialite(QString specialite){this->specialite=specialite;}
void Athletes::set_mail(QString mail){this->mail=mail;}

bool Athletes::ajouter()
{
    QSqlQuery querry;
    QString res=QString::number(ID);
    querry.prepare("INSERT INTO Athlete (ID, age, Nom, Prenom, nationalite, sexe, specialite, mail)""VALUES(:ID, :age, :Nom, :Prenom, :nationalite, :sexe, :specialite, :Email)");
    querry.bindValue(":ID",res);
    querry.bindValue(":Nom",Nom);
    querry.bindValue(":Prenom",Prenom);
    querry.bindValue(":nationalite",nationalite);
    querry.bindValue(":sexe",sexe);
    querry.bindValue(":specialite",specialite);
    querry.bindValue(":mail",mail);

    return querry.exec();
}


