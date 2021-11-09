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
       bool supprimer(int);
       bool modifier(int);





private:
    int id,nbr_voyages,capacite,nbr_billet;
    QString nom,type,destination_depart,destination_arrivee;
};



#endif // MOYENSDETRANSPORT_H
