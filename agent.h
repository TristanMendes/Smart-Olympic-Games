#ifndef AGENT_H
#define AGENT_H
#include <QSqlQueryModel>
#include <QString>

class Agent
{
public:
    Agent();
    Agent(int,QString,QString,QString,QString);
    //Getters
    int getid_agent();
    QString getnom_agent();
    QString getprenom_agent();
    QString getgrade_agent();
    QString getposte_agent();
    //Setters
    void setid_agent(int);
    void setnom_agent(QString);
    void setprenom_agent(QString);
    void setgrade_agent(QString);
    void setposte_agent(QString);
    //Fonctionnalités de Base relatives à l'entite Stade
    bool ajouter_agent();
    QSqlQueryModel* afficher_agent();
    bool supprimer_agent(int);
    bool modifier_agent(int id_agent,QString nom_agent,QString prenom_agent,QString grade_agent,QString poste_agent);
    QSqlQueryModel * tri_agent() ;
    QSqlQueryModel* rechercher_agent(QString id_agent);

private:
int id_agent  ;
QString nom_agent,prenom_agent,grade_agent,poste_agent ;


};



#endif // AGENT_H
