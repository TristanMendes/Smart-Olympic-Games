#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hebergement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_identifiant->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_id_supp->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_hebergement->setModel(H.afficher());
    ui->tab_hebergement_2->setModel(H.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int identifiant=ui->le_identifiant->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->le_adresse->text();
    int nombre_etoile=ui->le_nombre_etoile->text().toInt();
    int nombre_des_chambres=ui->le_nombre_des_chambres->text().toInt();
    int note=ui->le_note->text().toInt();

     Hebergement H(identifiant,nom,adresse,nombre_etoile,nombre_des_chambres,note);
     bool test=H.ajouter();
     if (test)
     {
       QMessageBox::information(nullptr,QObject::tr("Ajout avec succes"),QObject::tr("SUCCES"),QMessageBox::Ok) ;
     ui->tab_hebergement->setModel(H.afficher());
     }else
         QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                     QObject::tr("Echec d'ajout.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    Hebergement H1; H1.setidentifiant(ui->le_id_supp->text().toInt());
    bool test=H1.supprimer(H1.getidentifiant());
    if (test)
    {
      QMessageBox::information(nullptr,QObject::tr("Suppression avec succes"),QObject::tr("SUCCES"),QMessageBox::Ok) ;
    }else

        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Echec de suppression.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_hebergement->setModel(H.afficher());



}



void MainWindow::on_pb_modifier_clicked()
{

    int identifiant=ui->le_identifiant->text().toInt() ;
    QString nom=ui->le_nom->text() ;
    QString adresse=ui->le_adresse->text();
    int nombre_etoile=ui->le_nombre_etoile->text().toInt();
    int nombre_des_chambres=ui->le_nombre_des_chambres->text().toInt();
    int note=ui->le_note->text().toInt();




             Hebergement H(identifiant,nom,adresse,nombre_etoile,nombre_des_chambres,note);
            bool test=H.modifier(identifiant,nombre_etoile,nombre_des_chambres,note);
            if(test)
            {
                ui->tab_hebergement->setModel(H.afficher());
                QMessageBox::information(nullptr, QObject::tr("succes"),
                            QObject::tr("HEBERGEMENT modifié."), QMessageBox::Ok);
        }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                           QObject::tr("erreur de modification."), QMessageBox::Ok);
    }
}

void MainWindow::on_pb_annuler_clicked()
{


        ui->le_identifiant->setText(0) ;
          ui->le_nom->setText(0) ;
          ui->le_adresse->setText(0) ;
          ui->le_nombre_etoile->setText(0) ;
          ui->le_nombre_des_chambres->setText(0) ;
          ui->le_note->setText(0) ;

}




void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(index==1)
      {
          ui->tab_hebergement_2->setModel(H.sort_Hebergement());
      }else
          ui->tab_hebergement_2->setModel(H.sort_Hebergement());
}

void MainWindow::on_pb_rechercher_clicked()
{
    int iden=ui->rechercher->text().toInt() ;
    ui->tab_hebergement_2->setModel(H.rechercher(iden)) ;
    QMessageBox::information(nullptr, QObject::tr("succes"),
                QObject::tr(" affiche  dans le tableau !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_annuler_2_clicked()
{

            ui->rechercher->setText(0) ;
            ui->tab_hebergement_2->setModel(H.afficher());

}
