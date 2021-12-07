#ifndef GESTION_STADES_H
#define GESTION_STADES_H
#include "stade.h"
#include "agent.h"
#include "fan.h"
#include "affectation.h"
#include <QPainter>
#include<QtGui>
#include <QVariant>
#include <QDialog>

namespace Ui {
class gestion_stades;
}

class gestion_stades : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_stades(QWidget *parent = nullptr);
    ~gestion_stades();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();


    void on_cb_tri_currentIndexChanged(int index);

    void on_pb_annuler_clicked();

    void on_pb_ajouter_agent_clicked();

    void on_pb_supprimer_agent_clicked();

    void on_pb_modifier_agent_clicked();

    void on_cb_trier_agent_currentIndexChanged(int index);


    void on_pb_annuler_agent_clicked();

    void on_pb_ajouter_fan_clicked();

    void on_pb_modifier_fan_clicked();

    void on_pb_supprimer_fan_clicked();

    void on_cb_trier_fan_currentIndexChanged(int index);


    void on_pb_annuler_fan_clicked();


    void stats(QString,QString ,int,int,QString);



    void on_statsStadeCapacite_clicked();

    void on_statsStadeSurface_clicked();

    void on_statsStadeNbrEvent_clicked();


    void on_pb_football_clicked();

    void on_pb_athletisme_clicked();

    void on_pb_ajouter_affectation_clicked();

    void on_pb_supprimer_affectation_clicked();

    void on_pb_modifier_affectation_clicked();


    void on_lineEditRechercheStade_textChanged(const QString &arg1);

    void on_lineEditRechercheAgent_textChanged(const QString &arg1);


    void on_lineEditRechercheFan_textChanged(const QString &arg1);

    void on_valabiliteFan_clicked();




private:
    Ui::gestion_stades *ui;
    Stade S ;
    Agent A ;
    Fan F;
    Affectation Aff;

signals:
    void setCenter(QVariant,QVariant);
};

#endif // GESTION_STADES_H
