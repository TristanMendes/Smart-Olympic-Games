#include "affectation.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Affectation::Affectation()
{
id_aff=0; num_evenement=0; specialite_aff="";
}
Affectation::Affectation(int id_aff,int num_evenement,QString specialite_aff)
{this->id_aff=id_aff; this->num_evenement=num_evenement; this->specialite_aff=specialite_aff;}
int Affectation::getid_aff() {return id_aff ;}
int Affectation::getnum_evenement() {return num_evenement ;}
QString Affectation::getspecialite_aff() {return specialite_aff;}
void Affectation::setid_aff(int id_aff) {this->id_aff=id_aff;}
void Affectation::setnum_evenement(int num_evenement) {this->num_evenement=num_evenement;}
void Affectation::setspecialite_aff(QString specialite_aff) {this->specialite_aff=specialite_aff;}
bool Affectation::ajouter_aff()
{

    QString id_aff_string=QString::number(id_aff);
    QString num_evenement_string=QString::number(num_evenement);
     QSqlQuery query;
query.prepare("INSERT INTO affectation (id_aff,num_evenement,specialite_aff) "
  "VALUES (:id_aff, :num_evenement, :specialite_aff)");
     query.bindValue(0,id_aff_string);
     query.bindValue(1,num_evenement_string);
     query.bindValue(2, specialite_aff);
          return query.exec();                                                                    // la requete
}

bool Affectation::supprimer_aff(int id_aff)
{
    QSqlQuery query;
         query.prepare("Delete from affectation where id_aff=:id_aff");
         query.bindValue(0,id_aff);

         return query.exec();
}


QSqlQueryModel* Affectation::afficher_aff()
{
   QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT* FROM affectation");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num_evenement"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Specialite"));


return model;
}

bool Affectation::modifier_aff(int id_aff,int num_evenement,QString specialite_aff)

{

    QString id_aff_string=QString::number(id_aff);
    QString num_evenement_string=QString::number(num_evenement);
    QSqlQuery query;
       query.prepare("update affectation set num_evenement=:num_evenement,specialite_aff=:specialite_aff where id_aff=:id_aff");


       query.bindValue(":id_aff",id_aff_string);
       query.bindValue(":num_evenement",num_evenement_string);
       query.bindValue(":specialite_aff",specialite_aff);

return query.exec();
}
