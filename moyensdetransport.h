#ifndef MOYENSDETRANSPORT_H
#define MOYENSDETRANSPORT_H
#include <QString>
#include <QSqlQueryModel>



class MoyensDeTransport
{
public:
        MoyensDeTransport();
        MoyensDeTransport(int,QString,QString,int,QString,QString,int,int);


        int getid();
        QString getnom();
        QString gettype();
        int getnbr_voyages();
        QString getdestination_depart();
        QString getdestination_arrivee();
        int getcapacite();
        int getnbr_billet();


        void setid (int);
        void setnom (QString);
        void settype (QString);
        void setnbr_voyages (int);
        void setdestination_depart (QString);
        void setdestination_arrivee (QString);
        void setcapacite (int);
        void setnbr_billet(int);
        bool ajouter();
       QSqlQueryModel* afficher();
       QSqlQueryModel *stats();

       bool supprimer(int);
       bool modifier(int);

       bool modifie_billet(int,int,int);
       bool verifier_id(int);

       int recherche_nbr_billet(int);
              bool modifier_QR_code (int,int,int);
              bool recherche_id (int);

              QSqlQueryModel * rechercher_nom(QString );
              QSqlQueryModel * rechercher_capacite(int );
              QSqlQueryModel * rechercher_dest_dep(QString );
              QSqlQueryModel * rechercher_type(QString );
              QSqlQueryModel * rechercher_dest_arr(QString );
              QSqlQueryModel * rechercher_nbr_voyages(int );
              QSqlQueryModel * choix_moyen(int );
              QSqlQueryModel* afficher_billet();
              QSqlQueryModel* rechercher_id(int);








private:
    int id,nbr_voyages,capacite,nbr_billet;
    QString nom,type,destination_depart,destination_arrivee;
};



#endif // MOYENSDETRANSPORT_H
