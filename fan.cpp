#include "fan.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlError>

Fan::Fan()
{
id_fan=0 ; nom_fan=""; prenom_fan="";nationalite_fan="" ;
}

 Fan::Fan(int id_fan,QString nom_fan,QString prenom_fan,QString nationalite_fan)


 {this->id_fan=id_fan; this->nom_fan=nom_fan; this->prenom_fan=prenom_fan ; this->nationalite_fan=nationalite_fan ;}
 int Fan::getid_fan() {return id_fan ;}
 QString Fan::getnom_fan() {return nom_fan ;}
 QString Fan::getprenom_fan() {return prenom_fan ;}
 QString Fan::getnationalite_fan() {return nationalite_fan;}

 void Fan::setid_fan(int id_fan) {this->id_fan=id_fan;}
 void Fan::setnom_fan(QString nom_fan) {this->nom_fan=nom_fan;}
 void Fan::setprenom_fan(QString prenom_fan) {this->prenom_fan=prenom_fan;}
 void Fan::setnationalite_fan(QString nationalite_fan) {this->nationalite_fan=nationalite_fan;}


 bool Fan::ajouter_fan()
 {

     QString id_fan_string=QString::number(id_fan);

      QSqlQuery query;
 query.prepare("INSERT INTO fans (id_fan,nom_fan,prenom_fan,nationalite_fan) "
   "VALUES (:id_fan, :nom_fan, :prenom_fan, :nationalite_fan)");
      query.bindValue(0,id_fan_string);
      query.bindValue(1,nom_fan);
      query.bindValue(2,prenom_fan);
      query.bindValue(3,nationalite_fan);


           return query.exec();                                                                    // la requete
}

 bool Fan::supprimer_fan(int id_fan)
 {
     QSqlQuery query;
          query.prepare("Delete from fans where id_fan=:id_fan");
          query.bindValue(0,id_fan);

          return query.exec();
}


QSqlQueryModel* Fan::afficher_fan()
{
    QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("SELECT* FROM fans");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));



return model;
}

 bool Fan::modifier_fan(int id_fan,QString nom_fan,QString prenom_fan,QString nationalite_fan)

{
     QString id_fan_string=QString::number(id_fan);
     QSqlQuery query;
        query.prepare("update fans set nom_fan=:nom_fan,prenom_fan=:prenom_fan,nationalite_fan=:nationalite_fan where id_fan=:id_fan");
        query.bindValue(":id_fan",id_fan_string);
        query.bindValue(":nom_fan",nom_fan);
        query.bindValue(":prenom_fan",prenom_fan);
        query.bindValue(":nationalite_fan",nationalite_fan);


return query.exec();
}


 QSqlQueryModel *Fan::tri_fan()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  fans ORDER BY id_fan");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));



     return model;
 }
 QSqlQueryModel * Fan::rechercherFan(QString id_fan)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM fans WHERE  id_fan LIKE '%"+id_fan+"%'" );





     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nationalite"));




 return model ;
 }

 Fan Fan::valabiliteFan(QString id_fan)
 {
     QSqlQuery query;

     query.prepare("SELECT * FROM fans WHERE  id_fan=:id_fan" );

     query.bindValue(":id_fan",id_fan);
     query.exec();
     Fan fan;
     if(query.next())
        {

         fan.setid_fan(query.value(0).toInt());
         fan.setnom_fan(query.value(1).toString());
         fan.setprenom_fan(query.value(2).toString());
         fan.setnationalite_fan(query.value(3).toString());


     }



    return fan;




 }
