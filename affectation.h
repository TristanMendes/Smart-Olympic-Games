#ifndef AFFECTATION_H
#define AFFECTATION_H
#include <QSqlQueryModel>
#include <QString>


class Affectation
{
public:
    Affectation();
    Affectation(int,int,QString);
    //Getters
    int getid_aff();
    int getnum_evenement();
    QString getspecialite_aff();
    //Setters
    void setid_aff(int);
    void setnum_evenement(int);
    void setspecialite_aff(QString);
    //Fonctionnalités de Base relatives à l'entite Stade
    bool ajouter_aff();
    QSqlQueryModel* afficher_aff();
    bool supprimer_aff(int id_aff);
    bool modifier_aff(int id_aff,int num_evenement,QString specialite_aff);
private:
 int id_aff,num_evenement  ;
 QString specialite_aff ;
 };

#endif // AFFECTATION_H
