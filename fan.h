#ifndef FAN_H
#define FAN_H
#include <QSqlQueryModel>
#include <QString>

class Fan
{
public:
    Fan();
    Fan(int,QString,QString,QString);
    //Getters
    int getid_fan();
    QString getnom_fan();
    QString getprenom_fan();
    QString getnationalite_fan();

    //Setters
    void setid_fan(int);
    void setnom_fan(QString);
    void setprenom_fan(QString);
    void setnationalite_fan(QString);

    //Fonctionnalités de Base relatives à l'entite Stade
    bool ajouter_fan();
    QSqlQueryModel* afficher_fan();
    bool supprimer_fan(int);
    bool modifier_fan(int id_fan,QString nom_fan,QString prenom_fan,QString nationalite_fan);
    QSqlQueryModel * tri_fan() ;
    QSqlQueryModel* rechercherFan(QString id_fan);
    Fan valabiliteFan(QString);



private:
int id_fan  ;
QString nom_fan,prenom_fan,nationalite_fan ;

};

#endif // FAN_H
