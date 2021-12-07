#ifndef GESTION_ATHLETES_H
#define GESTION_ATHLETES_H

#include <QDialog>
#include "athletesop.h"
#include <QSystemTrayIcon>
#include <QDialog>
#include <QFile>
#include<QTextStream>




namespace Ui {
class gestion_athletes;
}

class gestion_athletes : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_athletes(QWidget *parent = nullptr);
    ~gestion_athletes();

private slots:
    void on_boutton_ajouterath_clicked();

    void on_boutton_supprimerath_clicked();

    void on_pushButton_Modifierath_clicked();

    void on_table_athletes_2_activated(const QModelIndex &index);

    void on_bouton_rechercherath_clicked();


    void on_comboBox_trierath_currentIndexChanged(int index);


    void on_bouton_PDF_clicked();



    void on_bouton_excel_clicked();

    void on_bouton_URL_clicked();

   /* void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino */





private:
    Ui::gestion_athletes *ui;
    athletesOP A;


};

#endif // GESTION_ATHLETES_H
