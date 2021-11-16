#ifndef CALENDRIER_H
#define CALENDRIER_H

#include<QDate>
#include <QSqlQueryModel>


class calendrier
{
public:
    calendrier();
    calendrier(int,QDate,QDate,int);
        int getid();
        QDate getdate_deb();
        QDate getdate_fin();
       int getperiode();
        void setid(int);
        void setdate_deb(QDate);
        void setdate_fin(QDate);
       void setperiode(int);

        bool ajouter();
      QSqlQueryModel* afficher();
      bool update(int , QDate ,QDate ,int);
      bool supprimer(int);

    private:
        int id,periode;
        QDate date_deb,date_fin;
};







#endif // CALENDRIER_H
