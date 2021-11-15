#include "agent.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Agent::Agent()
{
id_agent=0 ; nom_agent=""; prenom_agent="";grade_agent="";poste_agent="" ;
}

 Agent::Agent(int id_agent,QString nom_agent,QString prenom_agent,QString grade_agent,QString poste_agent)
 {this->id_agent=id_agent; this->nom_agent=nom_agent; this->prenom_agent=prenom_agent ; this->grade_agent=grade_agent ; this->poste_agent=poste_agent ;}
 int Agent::getid_agent() {return id_agent ;}
 QString Agent::getnom_agent() {return nom_agent ;}
 QString Agent::getprenom_agent() {return prenom_agent ;}
 QString Agent::getgrade_agent() {return grade_agent;}
 QString Agent::getposte_agent() {return poste_agent ;}
 void Agent::setid_agent(int id_agent) {this->id_agent=id_agent;}
 void Agent::setnom_agent(QString nom_agent) {this->nom_agent=nom_agent;}
 void Agent::setprenom_agent(QString prenom_agent) {this->prenom_agent=prenom_agent;}
 void Agent::setgrade_agent(QString grade_agent) {this->grade_agent=grade_agent;}
 void Agent::setposte_agent(QString poste_agent) {this->poste_agent=poste_agent;}

 bool Agent::ajouter_agent()
 {

     QString id_agent_string=QString::number(id_agent);

      QSqlQuery query;
 query.prepare("INSERT INTO agents (id_agent,nom_agent,prenom_agent,grade_agent,poste_agent) "
   "VALUES (:id_agent, :nom_agent, :prenom_agent, :grade_agent, :poste_agent)");
      query.bindValue(0,id_agent_string);
      query.bindValue(1,nom_agent);
      query.bindValue(2,prenom_agent);
      query.bindValue(3,grade_agent);
      query.bindValue(4,poste_agent);

           return query.exec();                                                                    // la requete
}

 bool Agent::supprimer_agent(int id_agent)
 {
     QSqlQuery query;
          query.prepare("Delete from agents where id_agent=:id_agent");
          query.bindValue(0,id_agent);

          return query.exec();
}


QSqlQueryModel* Agent::afficher_agent()
{
    QSqlQueryModel* model=new QSqlQueryModel();
 model->setQuery("SELECT* FROM agents");

 model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("Grade"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));


return model;
}

 bool Agent::modifier_agent(int id_agent,QString nom_agent,QString prenom_agent,QString grade_agent,QString poste_agent)

{

     QString id_agent_string=QString::number(id_agent);
     QSqlQuery query;
        query.prepare("update agents set nom_agent=:nom_agent,prenom_agent=:prenom_agent,grade_agent=:grade_agent,poste_agent=:poste_agent where id_agent=:id_agent");
        query.bindValue(":id_agent",id_agent_string);
        query.bindValue(":nom_agent",nom_agent);
        query.bindValue(":prenom_agent",prenom_agent);
        query.bindValue(":grade_agent",grade_agent);
        query.bindValue(":poste_agent",poste_agent);

return query.exec();
}


 QSqlQueryModel *Agent::tri_agent()
 {
     QSqlQueryModel * model=new QSqlQueryModel();

     model->setQuery("select * from  agents ORDER BY id_agent");

     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Grade"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));




     return model;
 }
 QSqlQueryModel * Agent::rechercher_agent(QString id_agent)
 {
 QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM agents WHERE  id_agent LIKE '%"+id_agent+"%'" );



     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Grade"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));



 return model ;
 }

