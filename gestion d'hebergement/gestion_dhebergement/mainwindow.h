#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPainter>
#include<QtGui>
#include <QMainWindow>
#include <hebergement.h>
#include <calendrier.h>
#include <payment.h>

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

void on_pb_map_clicked();

void on_table_prix_activated(const QModelIndex &index);

void on_table_periode_activated(const QModelIndex &index);

void on_pb_reserve_clicked();

void on_pb_supp_3_clicked();

void on_table_payment_activated(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Hebergement H;
    calendrier c ;
    payment p;
signals:
   void setCenter(QVariant,QVariant);
};
#endif // MAINWINDOW_H
