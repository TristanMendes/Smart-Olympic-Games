#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
#include <QMessageBox>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
ui->tab_stade->setModel(S.afficher());
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
bool test=S.ajouter();
if(test)
{
ui->tab_stade->setModel(S.afficher());
    QMessageBox::information(nullptr,QObject::tr("OK"),
    QObject::tr("Ajout effectué\n"
    "click Cancel to exit"),QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
    QObject::tr("Ajout not effectué.\n"
    "Click Cancel to exit"), QMessageBox::Cancel);
}
