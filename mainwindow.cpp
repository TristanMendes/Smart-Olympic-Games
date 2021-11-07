#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "factures.h"
#include <QObject>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    QString st = facAff.get_Statut();
    ui->setupUi(this);
    ui->tableView_Afficher->setModel(facAff.consulterFacture());
    ui->tableView_Payer->setModel(facAff.afficherFacturesNonPayee());


}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_clicked()
{
    //int statInt,nbserInt;

    QString ref = ui->lineEditRef->text();
    QString dateC = ui->dateEdit_creation->text();
    QString stat = ui->comboBoxStatut->currentText();
    int mon = ui->lineEditMontant->text().toInt();
    QString nbser = ui->comboBoxNbServ->currentText();

    /*
    if(stat == "Payee")
    {
        statInt = 1;
    }
    else
    {
        statInt = 2;
    }
    if(nbser == "Transport")
    {
        nbserInt = 1;
    }
    else
    {
        nbserInt = 2;
    }
    */

    factures f(ref,nbser,stat,mon,dateC,dateC);

    bool ajout = f.ajouterFacture();

    if(ajout)
    {
       ui->tableView_Afficher->setModel(facAff.consulterFacture());
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Ajout Effectue \n"
                                            "Click Cancel to exit . "),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("Ajout non Efectue \n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButtonSupprimer_clicked()
{
   QString ref = ui->lineEditSupprimer->text();

   bool supp = facAff.supprimerFacture(ref);

   if(supp)
   {
       ui->tableView_Afficher->setModel(facAff.consulterFacture());
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Suppression effectuee\n",
                                            "Click Cancel to Exit."),QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                             QObject::tr("Suppression non effectuee ."
                                         "Click Cancel to exit ."),QMessageBox::Cancel);
   }
}

void MainWindow::on_pushButtonModifier_clicked()
{
   QString refModif = ui->lineEditModifier->text();
   int monNouv = ui->lineEditMonMod->text().toFloat();

   bool mod = facAff.modifierFacture(refModif,monNouv);

   if(mod)
   {
       ui->tableView_Afficher->setModel(facAff.consulterFacture());
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("modification effectuee\n",
                                            "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                             QObject::tr("modification non effectuee.",
                                         "Click Cancel to Exit"),QMessageBox::Cancel);
   }
}

void MainWindow::on_pushButtonPayer_clicked()
{
    QString ref = ui->lineEditPayer->text();

    bool pay = facAff.payerFactures(ref);

    if(pay)
    {
        ui->tableView_Afficher->setModel(facAff.consulterFacture());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("payement effectue\n",
                                             "Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                              QObject::tr("payement non effectue",
                                          "Click cancel to exit"),QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QString choix = ui->comboBoxTrier->currentText();

    if(choix == "Reference")
    {
        ui->tableViewTri->setModel(facAff.triReference());
    }
    else if(choix == "Date creation")
    {
        ui->tableViewTri->setModel(facAff.triDateCreation());
    }
    else if(choix == "Date modification")
    {
        ui->tableViewTri->setModel(facAff.triDateModification());
    }
    else if(choix == "Date Statut")
    {
        ui->tableViewTri->setModel(facAff.triStatut());
    }
    else if(choix == "Montant")
    {
        ui->tableViewTri->setModel(facAff.triMontant());
    }
    else if(choix == "Nombre Service")
    {
        ui->tableViewTri->setModel(facAff.triNbServ());
    }
}
