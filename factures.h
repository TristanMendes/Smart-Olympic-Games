#ifndef FACTURES_H
#define FACTURES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDateTime>

class factures
{
private:
    QString reference;
    //Variable nombre de service
    // 1 pour transport seulement
    // 2 - pour hebergement seulement
    // 3 - pour transoport et hebergement
    QString nbService;
    //Statut 1(payee) ou 2(non payee)
    QString statut;
    float montant;
    QString dateCreation;
    QString dateModification;


public:
    factures();
    factures(QString,QString,QString,float,QString,QString);

    void set_reference(QString ref);
    void set_NbServices(QString nb);
    void set_Statut(QString st);
    void set_Montant(float x);
    void set_DateCreation(QString date);
    void set_DateModification(QString date);

    QString get_reference();
    QString get_NbServices();
    QString get_Statut();
    float get_Montant();
    QString get_DateCreation();
    QString get_DateModification();
    bool ajouterFacture();
    bool modifierFacture(QString reference,int montant);
    bool supprimerFacture(QString reference);
    bool payerFactures(QString reference);
    QSqlQueryModel * consulterFacture();
    QSqlQueryModel * afficherFacturesNonPayee();
    QSqlQueryModel * triReference();
    QSqlQueryModel * triDateCreation();
    QSqlQueryModel * triDateModification();
    QSqlQueryModel * triStatut();
    QSqlQueryModel * triNbServ();
    QSqlQueryModel * triMontant();
};

#endif // FACTURES_H
