#ifndef GESTION_HEBERGEMENTS_H
#define GESTION_HEBERGEMENTS_H

#include <QPainter>
#include<QtGui>
#include <hebergement.h>
#include <calendrier.h>
#include <payment.h>
#include <QVariant>
#include <QDialog>

namespace Ui {
class gestion_hebergements;
}

class gestion_hebergements : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_hebergements(QWidget *parent = nullptr);
    ~gestion_hebergements();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_annuler_clicked();

    void on_pb_rechercher_clicked();

    //void on_pushButton_7_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pb_annuler_2_clicked();

    void on_tab_hebergement_activated(const QModelIndex &index);



    void on_pb_ajouter_2_clicked();

    void on_le_modifier_2_clicked();

    void on_pb_supprimer_2_clicked();



void statistiques(QString,QString ,int,int,QString);


void on_par_capacite_clicked();


void on_table_prix_activated(const QModelIndex &index);

void on_table_periode_activated(const QModelIndex &index);

void on_pb_reserve_clicked();

void on_pb_supp_3_clicked();

void on_table_payment_activated(const QModelIndex &index);



private:
    Ui::gestion_hebergements *ui;
    Hebergement H;
    calendrier c ;
    payment p;
signals:
   void setCenter(QVariant,QVariant);
};

#endif // GESTION_HEBERGEMENTS_H
