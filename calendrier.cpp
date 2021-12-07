#include "calendrier.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>

calendrier::calendrier()
{
    id=0;
    date_deb=date_deb.currentDate();
    date_fin=date_fin.currentDate();
    periode=0;
}
calendrier::calendrier(int id,QDate date_deb,QDate date_fin,int periode)
{
    this->id=id; this->date_deb=date_deb; this->date_fin=date_fin; this->periode=periode;
}
int calendrier::getid() {return id;}
QDate calendrier::getdate_deb(){return date_deb;}
QDate calendrier::getdate_fin(){return date_fin;}
int calendrier::getperiode() {return periode;}

void calendrier::setid(int id){this->id=id;}
void calendrier::setdate_deb(QDate date_deb){this->date_deb=date_deb;}
void calendrier::setdate_fin(QDate date_fin){this->date_fin=date_fin;}
void calendrier::setperiode(int periode){this->periode=periode;}

bool calendrier::ajouter()
{ bool test=false;
    QSqlQuery query;
    QString id_string= QString::number(id);
          query.prepare("INSERT INTO calendrier (id, date_deb, date_fin, periode) "
                        "VALUES (:id, :date_deb, :date_fin, :periode)");

          query.bindValue(0, id_string);
          query.bindValue(1, date_deb);
          query.bindValue(2, date_fin);
          query.bindValue(3, periode);
        return query.exec();



    return test;

}
bool  calendrier::supprimer(int id)
{  QSqlQuery query;
    query.prepare("delete from calendrier where id=:id");
  query.bindValue(0, id);
return query.exec();
}


QSqlQueryModel* calendrier::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT* FROM calendrier");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Date_deb"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date_fin"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("periode"));

  return model;
}


bool calendrier::update(int id, QDate date_deb,QDate date_fin,int periode)
{
    QSqlQuery query;
    query.prepare("UPDATE calendrier SET id= :id,date_deb= :date_deb,date_fin=:date_fin,periode=:periode WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":date_deb",date_deb );
    query.bindValue(":date_fin", date_fin);
    query.bindValue(":periode", periode);


    return    query.exec();
}
