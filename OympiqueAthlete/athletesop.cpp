#include "athletesop.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>


athletesOP::athletesOP()
{
  id=0;
  age=0;
  nom=" ";
  prenom=" ";
  sexe=" ";
  nationalite=" ";
  specialite=" ";
  mail=" ";
}

athletesOP::athletesOP(int id,int age,QString nom,QString prenom,QString sexe,QString nationalite,QString specialite,QString mail)
{
    this->id=id;
    this->age=age;
    this->nom=nom;
    this->prenom=prenom;
    this->sexe=sexe;
    this->nationalite=nationalite;
    this->specialite=specialite;
    this->mail=mail;
}

bool athletesOP::ajouter()
{

    QSqlQuery query;

    QString id_string=QString::number(id);
    QString res=QString::number(age);
    query.prepare("INSERT INTO aolympiqueathlete (id, age, nom, prenom, sexe, nationalite, specialite, mail) "
                  "VALUES (:id, :age, :nom, :prenom, :sexe, :nationalite, :specialite, :mail)");
    query.bindValue(":id", id_string);
    query.bindValue(":age", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":sexe", sexe);
    query.bindValue(":nationalite", nationalite);
    query.bindValue(":specialite", specialite);
    query.bindValue(":mail", mail);
    return query.exec();

}

bool athletesOP::supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from aolympiqueathlete where id=:id");
    query.bindValue(":id", id);

    return query.exec();
}


QSqlQueryModel* athletesOP::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM aolympiqueathlete");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
         model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalité"));
         model->setHeaderData(6, Qt::Horizontal, QObject::tr("Specialite"));
         model->setHeaderData(7, Qt::Horizontal, QObject::tr("Mail"));



         return model;
}

bool athletesOP::Nomtest(QString nom)
{

    for(int i=0; i<nom.size();i++)
    {
        if(nom[i]=='@' || nom[i]=='#' ||nom[i]=='$' || nom[i]=='*'|| nom[i]=='&' || nom[i]=='+' || nom[i]=='-' || nom[i]=='.' || nom[i]=='?' || nom[i]=='/'|| nom[i]==';' || nom[i]=='!' || nom[i]=='%' || nom[i]=='>'|| nom[i]=='<' || nom[i]=='=')
            return false;
    }
    return true;
}

/*bool athletesOP::Prenomtest(QString prenom)
{
    for(int i=0; i<prenom.size();i++)
    {
        if(prenom[i]=='@' || prenom[i]=='#' ||prenom[i]=='$' || prenom[i]=='*'|| prenom[i]=='&' || prenom[i]=='+' || prenom[i]=='-' || prenom[i]=='.' || prenom[i]=='?' || prenom[i]=='/'|| prenom[i]==';' || prenom[i]=='!' || prenom[i]=='%' || prenom[i]=='>'|| prenom[i]=='<' || prenom[i]=='=')
            return false;
    }
    return true;
}*/

bool athletesOP::modifier(int id)
{
     QSqlQuery query;

     //QString id_string=QString::number(id);
    // QString res=QString::number(age);
     query.prepare("update aolympiqueathlete set id=:id, age=:age, nom=:nom, prenom=:prenom, sexe=:sexe, nationalite=:nationalite, specialite=:specialite, mail=:mail where id=:id");
     query.bindValue(":id", id);
     //qDebug()<< id;
    // qDebug()<<"id: "<<id<<"age: "<<age<<"sexe: "<<sexe<< "nationalite: "<<nationalite<<"specialite: "<<specialite<<"mail: "<<mail;
     query.bindValue(":age", age);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":sexe", sexe);
     query.bindValue(":nationalite", nationalite);
     query.bindValue(":specialite", specialite);
     query.bindValue(":mail", mail);

     return query.exec();
}

QSqlQueryModel* athletesOP::recherche(int id)
{
   QSqlQueryModel* model=new QSqlQueryModel();
   QSqlQuery query;

    QString res=QString::number(id);  //SQLQUERY ONLY TAKES STRING ENTRIES.

    query.prepare("SELECT * from aolympiqueathlete where id= :id");
    query.bindValue(":id",res);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Mail"));

        return model;
    }

QSqlQueryModel* athletesOP::rechercheNom(QString nom)
{
    QSqlQueryModel* model=new QSqlQueryModel();
    QSqlQuery query;
    query.bindValue(":nom", nom);

    // QString res=QString::number(id);  //SQLQUERY ONLY TAKES STRING ENTRIES.

     query.prepare("SELECT * from aolympiqueathlete where nom=:nom");
     //query.bindValue(":id",res);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Sexe"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalite"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("Mail"));

         return model;

}

QSqlQueryModel* athletesOP::trier_age()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from aolympiqueathlete ORDER BY age");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));

    return model;
}

QSqlQueryModel* athletesOP::trier_nationalite()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from aolympiqueathlete ORDER BY nationalite");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));

    return model;

}

QSqlQueryModel* athletesOP::trier_specialite()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from aolympiqueathlete ORDER BY specialite");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Age"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("sexe"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Nationalite"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("specialite"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("mail"));

    return model;
}
