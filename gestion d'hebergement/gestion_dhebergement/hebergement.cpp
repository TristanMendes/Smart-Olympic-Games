#include "hebergement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Hebergement::Hebergement()
{
identifiant=0 ; nom=" "  ; adresse=" " ; nombre_etoile=0 ; nombre_des_chambres=0 ;note=0; prix=0;
}

Hebergement::Hebergement (int identifiant,QString nom,QString adresse,int nombre_etoile,int nombre_des_chambres,int note, int prix)
{   this->identifiant=identifiant;
    this->nom=nom;
    this->adresse=adresse;
    this->nombre_etoile=nombre_etoile;
    this->nombre_des_chambres=nombre_des_chambres;
    this->note=note;
    this->prix=prix;

}
int Hebergement::getidentifiant(){return identifiant;}
QString Hebergement::getnom(){return nom;}
QString Hebergement::getadresse(){return adresse;}
int Hebergement::getnombre_etoile(){return nombre_etoile;}
int Hebergement::getnombre_des_chambres(){return nombre_des_chambres;}
int Hebergement::getnote(){return note;}
int Hebergement::getprix(){return prix;}

void Hebergement::setidentifiant(int identifiant){this->identifiant=identifiant;}
void Hebergement::setnom(QString nom){this->nom=nom;}
void Hebergement::setadresse(QString adresse){this->adresse=adresse;}
void Hebergement::setnombre_etoile(int nombre_etoile){this->nombre_etoile=nombre_etoile;}
void Hebergement::setnombre_des_chambres(int nombre_des_chambres){this->nombre_des_chambres=nombre_des_chambres;}
void Hebergement::setnote(int note){this->note=note;}
void Hebergement::setprix(int prix){this->prix=prix;}

bool Hebergement::ajouter()
{
    QString identifiant_string=QString::number(identifiant);
    QSqlQuery query;

          query.prepare("INSERT INTO HEBERGEMENT (id_hebergement, nom_hebergement, adresse_hebergement, nombre_etoile, nombre_des_chambres, note_hebergement, prix_hebergement) "
                        "VALUES (:id_hebergement, :nom_hebergement, :adresse_hebergement, :nombre_etoile, :nombre_des_chambres, :note, :prix_hebergement)");
          query.bindValue(0,identifiant_string);
          query.bindValue(1,nom);
          query.bindValue(2,adresse);
          query.bindValue(3, nombre_etoile);
          query.bindValue(4, nombre_des_chambres);
          query.bindValue(5, note);
          query.bindValue(6, prix);

          return query.exec();

}
bool Hebergement::supprimer(int identifiant)
{
    QSqlQuery query;

          query.prepare("Delete from Hebergement where id_hebergement=:identifiant");

          query.bindValue(0,identifiant);

          return query.exec();



}
QSqlQueryModel* Hebergement::afficher()
{
  QSqlQueryModel* model=new QSqlQueryModel();


model->setQuery("SELECT *  FROM hebergement");
model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nombre d'étoiles"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("Nombre des chambres"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("Note"));
model->setHeaderData(6, Qt::Horizontal,QObject::tr("prix"));


  return model;
}

int identifiant();
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
bool Hebergement::modifier(int identifiant , int nombre_etoile ,int nombre_des_chambres,int note,int prix )
{
    QSqlQuery query;

     QString res = QString::number(identifiant);
     QString nbretoile=QString::number(nombre_etoile);
     QString nbrchambre=QString::number(nombre_des_chambres);
     QString notee=QString::number(note);
     QString prixx=QString::number(prix);


        query.prepare( "UPDATE   HEBERGEMENT set NOM_HEBERGEMENT=:nom ,adresse_hebergement=:adresse ,nombre_etoile=:nombre_etoile,nombre_des_chambres=:nombre_des_chambres,note_hebergement=:note,prix_hebergement=:prix where id_hebergement=:identifiant ;");
        query.bindValue(":identifiant",res );
        query.bindValue(":nom", nom);
        query.bindValue(":adresse",adresse);
        query.bindValue(":nombre_etoile",nbretoile);
        query.bindValue(":nombre_des_chambres", nbrchambre) ;
        query.bindValue(":note", notee) ;
        query.bindValue(":prix", prixx) ;


     return query.exec();
}
QSqlQueryModel *Hebergement::sort_Hebergement()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from  HEBERGEMENT ORDER BY id_hebergement");

    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nombre d'étoiles"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Nombre des chambres"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("Note"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("prix"));


    return model;
}
QSqlQueryModel * Hebergement::rechercher(int iden)
{
QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res=QString::number(iden);  //SQLQUERY ONLY TAKES STRING ENTRIES.
query.prepare("SELECT * from HEBERGEMENT where id_hebergement= :Identifiant");
query.bindValue(":Identifiant",res);

    query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal,QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
model->setHeaderData(2, Qt::Horizontal,QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nombre d'étoiles"));
model->setHeaderData(4, Qt::Horizontal,QObject::tr("Nombre des chambres"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("Note"));
model->setHeaderData(5, Qt::Horizontal,QObject::tr("prix"));

return model ;
}







