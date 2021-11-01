#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "etudiant.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAjouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();

   Etudiant E(id,nom,prenom);

   bool test = E.ajouter();

   if(test)
   {
       QMessageBox::information(nullptr, QObject::tr("OK"),
                                QObject::tr("Ajout Effectue \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
   }
   else
   {
       QMessageBox::critical(nullptr, QObject::tr("NOT OK"),
                                QObject::tr("Ajout non Effectue \n"
                                            "Click Cancel to exit."),QMessageBox::Cancel);
   }
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    Etudiant e;
    e.setID(ui->lineEdit_supprimer->text().toUInt());

    bool test = e.supprimer(e.getID());

    if(test)
    {
        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Suppression effectuee\n"
                                             "Click cancel to exit."),QMessageBox::Cancel);
        ui->tableAfficahge->setModel(e.afficher());
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not OK"),
                              QObject::tr("Suppression non effectuee\n"
                                          "Click Cancel to exit"),QMessageBox::Cancel);
    }

}
