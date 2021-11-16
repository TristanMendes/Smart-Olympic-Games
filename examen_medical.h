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
//metiers
QSqlQueryModel * chercher_id(QString q);
QSqlQueryModel * chercher_nom(QString q);
QSqlQueryModel * chercher_type(QString q);
QSqlQueryModel * chercher_age(QString q);
QSqlQueryModel * chercher_etat(QString q);
QSqlQueryModel * chercher_coordonnees(QString q);
QSqlQueryModel * tri_id();
QSqlQueryModel * tri_nom();
QSqlQueryModel * tri_type();
QSqlQueryModel * tri_age();
QSqlQueryModel * tri_etat();
QSqlQueryModel * tri_coordonnees();
//antecedants_medicaux
bool ajouter_antecedants(int, QString, QString, QString, QString);
QSqlQueryModel* afficher_antecedants();
bool supprimer_antecedants(int);
//resultats_examens
//QSqlQueryModel * afficher_resultats();
QSqlQueryModel* chercher_resultats(QString q);

//statistiques
void statistique(QVector<double>* ticks,QVector<QString> *labels);
void statistiques(QString, QString, int, int, QString);
};




#endif // EXAMEN_MEDICAL_H
