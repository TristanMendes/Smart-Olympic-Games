#include "payment.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
payment::payment()
{
chambre_reserve=0 ; periode=0 ;prix=0;
}
payment::payment (int chambre_reserve,int periode,int prix)
{   this->chambre_reserve=chambre_reserve;
    this->periode=periode;
    this->prix=prix;

}
int payment::getchambre_reserve(){return chambre_reserve;}
int payment::getperiode(){return periode;}
int payment::getprix(){return prix;}


void payment::setchambre_reserve(int chambre_reserve){this->chambre_reserve=chambre_reserve;}
void payment::setperiode(int periode){this->periode=periode;}
void payment::setprix(int prix){this->prix=prix;}
bool payment::ajouter()
{
    QString chambre_reserve_string=QString::number(chambre_reserve);
    QSqlQuery query;

          query.prepare("INSERT INTO payment (chambre, periode, prix_chambre) "
                        "VALUES (:chambre, :periode, :prix_chambre)");
          query.bindValue(0,chambre_reserve);
          query.bindValue(1,periode);
          query.bindValue(2,prix);


          return query.exec();

}


QSqlQueryModel* payment::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM payment");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("chambre_reserve"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("periode"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("prix"));

  return model;
}
int payment::gain()
{
    QSqlQueryModel* model=new QSqlQueryModel();
QSqlQuery query ;
int total=0 ;
total=query.prepare("select periode * prix_chambre * chambre from payment ") ;

   return total ;


}





