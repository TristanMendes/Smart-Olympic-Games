#ifndef ATHLETESOP_H
#define ATHLETESOP_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQueryModel>


class athletesOP
{
private:
    int id,age;
    QString nom,prenom,sexe,nationalite,specialite,mail;
public:
    athletesOP();
    athletesOP(int,int,QString,QString,QString,QString,QString,QString);

    //getters
    QString get_nom(){return nom;}
    QString get_prenom(){return prenom;}
    QString get_sexe(){return sexe;}
    QString get_nationalite(){return nationalite;}
    QString get_specialite(){return specialite;}
    QString get_mail(){return mail;}
    int get_id(){return id;}
    int get_age(){return age;}

    //setters
    void set_nom(QString n){nom=n;}
    void set_prenom(QString p){prenom=p;}
    void set_sexe(QString s){sexe=s;}
    void set_nationalite(QString nt){nationalite=nt;}
    void set_specilaite(QString sp){specialite=sp;}
    void set_mail(QString m){mail=m;}
    void set_id(int ids){this->id=ids;}
    void set_age(int a){this->age=a;}

    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();

};

#endif // ATHLETESOP_H
