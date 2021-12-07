#ifndef HEBERGEMENT_H
#define HEBERGEMENT_H

#include <QString>
#include <QSqlQueryModel>


class Hebergement
{
public:
    Hebergement();
    Hebergement (int,QString,QString,int,int,int,int);
    int getidentifiant();
    QString getnom();
    QString getadresse();
    int getnombre_etoile();
    int getnombre_des_chambres();
    int getnote();
    int getprix();


    void setidentifiant(int);
    void setnom(QString);
    void setadresse(QString);
    void setnombre_etoile(int);
    void setnombre_des_chambres(int);
    void setnote(int);
    void setprix(int);

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int,int,int,int,int) ;
    QSqlQueryModel * sort_Hebergement() ;
    QSqlQueryModel *rechercher(int iden) ;


private:
    int note,prix;
    int identifiant ,nombre_etoile, nombre_des_chambres;
    QString nom, adresse;

};

#endif // HEBERGEMENT_H
