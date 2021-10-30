#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
 int id=ui->le_id->text().toInt();
 int capacite=ui->le_capacite->text().toInt();
 int nbre_evenement=ui->le_nbre_evenement->text().toInt();
 float dimension=ui->le_dimension->text().toFloat();
 QString nom=ui->le_nom->text();
 QString adresse=ui->le_adresse->text();
 QString specialite=ui->le_specialite->text();

  Stade S(id,capacite,nbre_evenement,dimension,nom,adresse,specialite);

}
