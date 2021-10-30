#ifndef STADE_H
#define STADE_H

#include <QString>
class Stade
{
public:
    Stade();
     Stade(int,int,int,float,QString,QString,QString);
     int getid();
     int getcapacite();
     int getnbre_evenement();
     float getdimension();
     QString getnom();
     QString getadresse();
     QString getspecialite();
     void setid(int);
     void setcapacite(int);
     void setnbre_evenement(int);
     void setdimension(float);
     void setnom(QString);
     void setadresse(QString);
     void setspecialite(QString);
     bool ajouter();

private:
 int id,capacite,nbre_evenement  ;
 float dimension ;
 QString nom, adresse , specialite ;


};

#endif // STADE_H
