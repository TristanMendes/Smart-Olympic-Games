#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stade.h"
#include "agent.h"
#include "fan.h"
#include "affectation.h"
#include <QMainWindow>
#include <QPainter>
#include<QtGui>
#include <QVariant>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();




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
    Ui::MainWindow *ui;
    Stade S ;
    Agent A ;
    Fan F;
    Affectation Aff;
signals:
    void setCenter(QVariant,QVariant);

};
#endif // MAINWINDOW_H
