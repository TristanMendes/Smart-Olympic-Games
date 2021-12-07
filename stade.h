#ifndef STADE_H
#define STADE_H

#include <QSqlQueryModel>
#include <QString>


class Stade
{
public:
    //Constructeurs
    Stade();
     Stade(int,int,int,float,QString,QString,QString);
     //Getters
     int getid();
     int getcapacite();
     int getnbre_evenement();
     float getsurface();
     QString getnom();
     QString getadresse();
     QString getspecialite();
     //Setters
     void setid(int);
     void setcapacite(int);
     void setnbre_evenement(int);
     void setsurface(float);
     void setnom(QString);
     void setadresse(QString);
     void setspecialite(QString);
     //Fonctionnalités de Base relatives à l'entite Stade
     bool ajouter();
     QSqlQueryModel* afficher();
     bool supprimer(int);
     bool modifier(int id,int capacite,int nbre_evenement,float surface,QString nom,QString adresse,QString specialite);
     QSqlQueryModel * tri_id() ;
     QSqlQueryModel * tri_capacite() ;
     QSqlQueryModel * tri_nbre_evenement() ;
     QSqlQueryModel* rechercher(QString);
     QSqlQueryModel* rechercher_football(QString specialite );
     QSqlQueryModel* rechercher_athletisme(QString specialite );




private:
 int id,capacite,nbre_evenement  ;
 float surface ;
 QString nom, adresse , specialite ;
 };

#endif // STADE_H
