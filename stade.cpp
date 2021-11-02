#include "stade.h"
#include <QSqlQuery>
#include <QDebug>
Stade::Stade()
{
id=0; capacite=0; nbre_evenement=0 ; nom=""; adresse="";specialite="";dimension=0.0f ;
}

 Stade::Stade(int id,int capacite,int nbre_evenement,float dimension,QString nom,QString adresse,QString specialite)
 {this->id=id; this->capacite=capacite; this->nbre_evenement=nbre_evenement ; this->dimension=dimension ; this->nom=nom ; this->adresse=adresse; this->specialite=specialite;}
 int Stade::getid() {return id ;}
 int Stade::getcapacite() {return capacite ;}
 int Stade::getnbre_evenement() {return nbre_evenement ;}
 float Stade::getdimension() {return dimension ;}
 QString Stade::getnom() {return nom ;}
 QString Stade::getadresse() {return adresse ;}
 QString Stade::getspecialite() {return specialite;}
 void Stade::setid(int id) {this->id=id;}
 void Stade::setcapacite(int capacite) {this->capacite=capacite;}
 void Stade::setnbre_evenement(int nbre_evenement) {this->nbre_evenement=nbre_evenement;}
 void Stade::setdimension(float dimension) {this->dimension=dimension;}
 void Stade::setnom(QString nom) {this->nom=nom;}
 void Stade::setadresse(QString adresse) {this->adresse=adresse;}
 void Stade::setspecialite(QString specialite) {this->specialite=specialite;}
 bool Stade::ajouter()
 {
     QSqlQuery query;
     QString id_string=QString::number(id);
     QString capacite_string=QString::number(capacite);
     QString nbre_evenement_string=QString::number(nbre_evenement);
     QString dimension_string=QString::number(dimension);

           query.prepare("INSERT INTO stade (id,capacite,nbre_evenement,dimension,nom,adresse,specialite) "
                         "VALUES (:id, :capacite, :nbre_evenement, :dimension, :nom, :adresse, :specialite)");
           query.bindValue(":id",id_string);
           query.bindValue(":capacite",capacite_string);
           query.bindValue(":nbre_evenement", nbre_evenement_string);
           query.bindValue(":dimension",dimension_string);
           query.bindValue(":nom",nom);
           query.bindValue(":adresse",adresse);
           query.bindValue(":specialite",specialite);
           return query.exec();


 }
 QSqlQueryModel * Stade::afficher()
 {
     QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * from Stade");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("capacite"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbre_evenement"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("dimension"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));


 return model;
 }








