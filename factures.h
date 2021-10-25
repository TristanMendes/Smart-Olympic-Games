#ifndef FACTURES_H
#define FACTURES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class factures
{
private:
    struct date
    {
        int jour;
        int mois;
        int annee;
    };
    QString reference;
    //Variable nombre de service
    // 1 pour transport seulement
    // 2 - pour hebergement seulement
    // 3 - pour transoport et hebergement
    int nbService;
    //Statut 1(payee) ou 2(non payee)
    int statut;
    float montant;
    date dateCreation;
    date dateModification;

    bool ajouterFacture(QString);
    bool modifierFacture(QString);
    bool supprimerFacture(QString);

public:
    factures();
    factures(QString,int,int,float,date,date);

    QString get_reference(){return reference ;}
    int get_NbServices(){return nbService;}
    int get_Statut(){return statut;}
    float get_Montant(){return montant;}
    date get_DateCreation(){date d; return d;}
    date get_DateModification(){date d; return d;}

    bool payerFactures(QString);
    QSqlQueryModel * consulterFacture();
};

#endif // FACTURES_H
