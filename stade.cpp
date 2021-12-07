#include "stade.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Stade::Stade()
{
id=0; capacite=0; nbre_evenement=0 ; nom=""; adresse="";specialite="";surface=0.0f ;
}

Stade::Stade(int id,int capacite,int nbre_evenement,float surface,QString nom,QString adresse,QString specialite)
{this->id=id; this->capacite=capacite; this->nbre_evenement=nbre_evenement ; this->surface=surface ; this->nom=nom ; this->adresse=adresse; this->specialite=specialite;}
int Stade::getid() {return id ;}
int Stade::getcapacite() {return capacite ;}
int Stade::getnbre_evenement() {return nbre_evenement ;}
float Stade::getsurface() {return surface ;}
QString Stade::getnom() {return nom ;}
QString Stade::getadresse() {return adresse ;}
QString Stade::getspecialite() {return specialite;}
void Stade::setid(int id) {this->id=id;}
void Stade::setcapacite(int capacite) {this->capacite=capacite;}
void Stade::setnbre_evenement(int nbre_evenement) {this->nbre_evenement=nbre_evenement;}
void Stade::setsurface(float surface) {this->surface=surface;}
void Stade::setnom(QString nom) {this->nom=nom;}
void Stade::setadresse(QString adresse) {this->adresse=adresse;}
void Stade::setspecialite(QString specialite) {this->specialite=specialite;}
bool Stade::ajouter()
{

    QString id_string=QString::number(id);
    QString capacite_string=QString::number(capacite);
    QString nbre_evenement_string=QString::number(nbre_evenement);
    QString surface_string=QString::number(surface);
     QSqlQuery query;
query.prepare("INSERT INTO stades (id_stade,nom_stade,adresse_stade,surface,specialite_stade,capacite_stade,nbre_evenement) "
  "VALUES (:id, :nom, :adresse, :surface, :specialite, :capacite, :nbre_evenement)");
     query.bindValue(0,id_string);
     query.bindValue(1,nom);
     query.bindValue(2, adresse);
     query.bindValue(3,surface_string);
     query.bindValue(4,specialite);
     query.bindValue(5,capacite_string);
     query.bindValue(6,nbre_evenement_string);
          return query.exec();                                                                    // la requete
}

bool Stade::supprimer(int id)
{
    QSqlQuery query;
         query.prepare("Delete from stades where id_stade=:id");
         query.bindValue(0,id);

         return query.exec();
}


QSqlQueryModel* Stade::afficher()
{
   QSqlQueryModel* model=new QSqlQueryModel();
model->setQuery("SELECT* FROM stades");

model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Surface"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Specialite"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Capacite"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbre_evenement"));

return model;
}

bool Stade::modifier(int id,int capacite,int nbre_evenement,float surface,QString nom,QString adresse,QString specialite)

{

    QString id_string=QString::number(id);
    QString capacite_string=QString::number(capacite);
    QString nbre_evenement_string=QString::number(nbre_evenement);
    QString surface_string=QString::number(surface);
    QSqlQuery query;
       query.prepare("update stades set nom_stade=:nom,adresse_stade=:adresse,surface=:surface,specialite_stade=:specialite,capacite_stade=:capacite,nbre_evenement=:nbre_evenement where id_stade=:id");


       query.bindValue(":id",id_string);
       query.bindValue(":nom",nom);
       query.bindValue(":adresse",adresse);
       query.bindValue(":surface",surface_string);
       query.bindValue(":specialite",specialite);
       query.bindValue(":capacite",capacite_string);
       query.bindValue(":nbre_evenement",nbre_evenement_string);
return query.exec();
}


 QSqlQueryModel *Stade::tri_id()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  stades ORDER BY id_stade");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));
return model;
 }

 QSqlQueryModel *Stade::tri_capacite()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  stades ORDER BY capacite_stade");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));
return model;
 }

 QSqlQueryModel *Stade::tri_nbre_evenement()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  stades ORDER BY nbre_evenement");

     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));
return model;
 }

 QSqlQueryModel * Stade::rechercher(QString idStade)
 {
 QSqlQueryModel * model= new QSqlQueryModel();

 model->setQuery("SELECT * FROM stades WHERE  id_stade LIKE '%"+idStade+"%'" );

 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
 model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));

 return model ;
 }
 QSqlQueryModel * Stade::rechercher_football(QString specialite)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 QSqlQuery query;
 query.prepare("SELECT * from stades where specialite_stade=:Football");
 query.bindValue(":Football",specialite);

     query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
 model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));



 return model ;
}
 QSqlQueryModel * Stade::rechercher_athletisme(QString specialite)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 QSqlQuery query;
 query.prepare("SELECT * from stades where specialite_stade=:Athletisme");
 query.bindValue(":Athletisme",specialite);

     query.exec();
 model->setQuery(query);
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("Surface"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("Specialite"));
 model->setHeaderData(5, Qt::Horizontal,QObject::tr("Capacite"));
 model->setHeaderData(6, Qt::Horizontal,QObject::tr("Nbre_evenement"));



 return model ;
}
