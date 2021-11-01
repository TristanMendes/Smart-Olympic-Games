#include "etudiant.h"
#include <QSqlQuery>
#include <QDebug>

Etudiant::Etudiant()
{
    id = 0;
    nom = "";
    prenom = "";
}
Etudiant::Etudiant(int id,QString nom, QString prenom)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;

}

int Etudiant::getID()
{
return id;
}
QString Etudiant::getNom()
{
    return nom;
}
QString Etudiant::getPrenom()
{
    return prenom;
}
void Etudiant::setID(int id)
{
    this->id = id;
}
void Etudiant::setNom(QString n)
{
    this->nom = n;
}
void Etudiant::setPrenom(QString prenom)
{
    this->prenom = prenom;
}
bool Etudiant::ajouter()
{
    QSqlQuery query;
    QString id_string = QString::number(id);
    query.prepare("INSERT INTO etudiant (id, nom, prenom)" "VALUES (:id, :nom, :prenom)");

    query.bindValue(":id",id_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec();

}

bool Etudiant::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("delete from etudiant where id=:id");
    query.bindValue(":id",id);

    return query.exec();

}

QSqlQueryModel* Etudiant::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM etudiant");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));

    return model;
}
