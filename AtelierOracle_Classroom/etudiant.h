#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>



class Etudiant
{
    QString nom, prenom;
    int id;
public:
    Etudiant();
    Etudiant(int ,QString,QString);

    QString getNom();
    QString getPrenom();
    int getID();

    void setNom(QString n);
    void setPrenom (QString p);
    void setID(int id);

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // ETUDIANT_H
