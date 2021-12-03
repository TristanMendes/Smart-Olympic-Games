#ifndef GESTION_DES_MOYENS_DE_TRANSPORT_H
#define GESTION_DES_MOYENS_DE_TRANSPORT_H

#include <QDialog>
#include "moyensdetransport.h"
#include "qcustomplot.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>


namespace Ui {
class gestion_des_moyens_de_transport;
}

class gestion_des_moyens_de_transport : public QDialog
{
    Q_OBJECT
public:
    explicit gestion_des_moyens_de_transport(QWidget *parent = nullptr);
    ~gestion_des_moyens_de_transport();


private slots:
    void on_B_Ajouter_clicked();
    void on_B_supp_clicked();
    void on_B_modifier_clicked();
    void on_B_recherche_nom_clicked();
    void on_B_recherche_capacite_clicked();
    void on_B_recherche_dest_dep_clicked();
    void on_B_choisir_clicked();
    void on_B_recherche_type_clicked();
    void on_B_recherche_nbr_voyages_clicked();
    void on_B_recherche_dest_arr_clicked();
    void on_B_billet_entrer_clicked();
    void on_B_QR_clicked();
    void addPoint(double x,double y);
    void clearData();
    void plot();
    void on_B_ajouter_clicked();
    void on_B_clear_clicked();
    void on_B_ajouter_annuler_clicked();
    void on_B_modifier_annuler_clicked();
    void on_B_supprimer_annuler_clicked();
    void on_B_QR_annuler_clicked();
    void on_B_billet_annuler_clicked();
    void on_B_choix_annuler_clicked();
    void on_B_excel_clicked();



private:
    Ui::gestion_des_moyens_de_transport *ui;
    MoyensDeTransport M;
    MoyensDeTransport M1;
    QVector <double> qv_x,qv_y;
    int index;

};

#endif // GESTION_DES_MOYENS_DE_TRANSPORT_H
