#ifndef EXAMEN_MEDICAL_H
#define EXAMEN_MEDICAL_H



#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class examen_medical
{private:
int id, tranche_age;
QString nom, type, etat_sante, coordonnees_athletes;

public:
examen_medical();
examen_medical(int,QString,QString,int,QString,QString);
int getid();
QString getnom();
QString gettype();
int gettranche_age();
QString getetat_sante();
QString getcoordonnees_athletes();
void setid(int);
void setnom(QString);
void settype(QString);
void settranche_age(int);
void setetat_sante(QString);
void setcoordonnees_athletes(QString);
bool ajouter_examen();
QSqlQueryModel* afficher();
bool supprimer_examen(int);
bool modifier_examen(int, QString, QString, int, QString, QString);
};




#endif // EXAMEN_MEDICAL_H
