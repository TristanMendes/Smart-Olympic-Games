#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moyensdetransport.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);




    ui->le_id->setValidator( new QIntValidator(100, 999999, this));
    ui->le_m_id->setValidator( new QIntValidator(100, 999999, this));
    ui->le_billet_id->setValidator( new QIntValidator(100, 999999, this));
    ui->le_QR_id->setValidator( new QIntValidator(100, 999999, this));
    ui->le_choix_id->setValidator( new QIntValidator(100, 999999, this));
    ui->le_id_supp->setValidator( new QIntValidator(100, 999999, this));

    ui->le_nbr_voyages->setValidator( new QIntValidator(100, 99, this));
    ui->le_recherche_nbr_voyages->setValidator( new QIntValidator(100, 99, this));
    ui->le_m_nbr_voyages->setValidator( new QIntValidator(100, 99, this));


    ui->le_capacite->setValidator( new QIntValidator(100, 9999, this));
    ui->le_m_capacite->setValidator( new QIntValidator(100, 9999, this));
    ui->le_recherche_capacite->setValidator( new QIntValidator(100, 9999, this));


    ui->le_m_nbr_billet->setValidator( new QIntValidator(100, 9999, this));
    ui->le_nbr_billet->setValidator( new QIntValidator(100, 9999, this));
    ui->le_billet_nbr_billet->setValidator( new QIntValidator(100, 9999, this));
    ui->le_QR_nbr_billet->setValidator( new QIntValidator(100, 9999, this));





   /* ui->table_moyens->setModel(M.afficher());
    ui->tab_aerien->setModel(M1.afficher_billet());
    ui->tab_QR->setModel(M1.afficher_billet());*/

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_Ajouter_clicked()
{


     int id=ui->le_id->text().toInt();
     QString nom=ui->le_nom->text();
     QString type=ui->le_type->currentText();
     int nbr_voyages=ui->le_nbr_voyages->text().toInt();
     QString destination_depart=ui->le_dest_dep->text();
     QString destination_arrivee=ui->le_dest_arri->text();
     int capacite=ui->le_capacite->text().toInt();
     int nbr_billet=ui->le_nbr_billet->text().toInt();



   MoyensDeTransport M(id,nom,type,nbr_voyages,destination_depart,destination_arrivee,capacite,nbr_billet);

   bool test=M.ajouter();
   QMessageBox msgBox;


      if(test)
              { msgBox.setText("Ajout avec succes.");
               ui->table_moyens->setModel(M.afficher());}
           else
           msgBox.setText("Echec d'ajout");
           msgBox.exec();




}




 void MainWindow::on_B_supp_clicked()

{    QMessageBox msgBox;

     int id=ui->le_id_supp->text().toInt();


               bool result=M.supprimer(id);


               if ((result))

              {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un moyen de transport"),
                                     QObject::tr("Suppression effectuée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}


                     else
                         QMessageBox::critical(nullptr, QObject::tr("Supprimer un moyen de transport"),
                                     QObject::tr("Suppression non effectuée !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
                ui->table_moyens->setModel(M.afficher());






}
















void MainWindow::on_B_modifier_clicked()
{

        int id =ui->le_m_id->text().toInt();
        QString nom= ui->le_m_nom->text();
        QString type= ui->le_m_type->currentText();
        int nbr_voyages = ui->le_m_nbr_voyages->text().toInt();
        QString destination_depart= ui->le_m_dest_dep->text();
        QString destination_arrivee= ui->le_m_dest_arr->text();
        int capacite = ui->le_m_capacite->text().toInt();
        int nbr_billet=ui->le_m_nbr_billet->text().toInt();


        MoyensDeTransport M (id,nom,type,nbr_voyages,destination_depart,destination_arrivee,capacite,nbr_billet);
      bool test=M.modifier(id);
      if(test)
    {

          ui->table_moyens->setModel(M.afficher());
    QMessageBox::information(nullptr, QObject::tr("Modifier un moyen de transport"),
                      QObject::tr("Modification effectuée.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Modifier un moyen de transport"),
                      QObject::tr("Modification non effectuée !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
















