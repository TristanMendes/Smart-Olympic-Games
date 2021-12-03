#ifndef GESTION_EXAMENS_MEDICAUX_H
#define GESTION_EXAMENS_MEDICAUX_H

#include <QDialog>
#include "examen_medical.h"
#include "smtp.h"
#include "qcustomplot.h"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPainter>
#include <QtGui>


namespace Ui {
class gestion_examens_medicaux;
}

class gestion_examens_medicaux : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_examens_medicaux(QWidget *parent = nullptr);
    ~gestion_examens_medicaux();

private slots:
    //crud
    void on_pb_ajouter_clicked();
    void on_pb_annuler_ajout_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_annuler_supp_clicked();
    void on_pb_modif_clicked();
    void on_pb_annuler_modif_clicked();

    //tri et recherche
    void on_recherche_id_clicked();
    void on_recherche_nom_clicked();
    void on_recherche_type_clicked();
    void on_recherche_age_clicked();
    void on_recherche_etat_clicked();
    void on_recherche_coordonnees_clicked();
    void on_pb_annuler_recherche_clicked();

    void on_tri_id_clicked();
    void on_tri_nom_clicked();
    void on_tri_type_clicked();
    void on_tri_age_clicked();
    void on_tri_etat_clicked();
    void on_tri_coordonnees_clicked();

    //antecedants
    void on_pb_ajouter_antecedants_clicked();
    void on_pb_supprimer_antecedants_clicked();
    void on_pb_pdf_clicked();
    void on_pb_excel_clicked();
    void on_pb_annuler_antecedants_clicked();
    //resultat
    void on_pb_resultat_clicked();
    void on_pb_annuler_resultat_clicked();
    //mailing
    void on_sendMail_clicked();
    void mailsent(QString);


private:
    Ui::gestion_examens_medicaux *ui;
    //crud
    examen_medical e;
    examen_medical e1;
    examen_medical e2;
    //recherche et tri
    examen_medical et;
    examen_medical er;
    //antecedants_medicaux
    examen_medical ea;
    //resultats_examens_medicaux
    examen_medical e_resultats;
    //stat
    examen_medical es;

};

#endif // GESTION_EXAMENS_MEDICAUX_H
