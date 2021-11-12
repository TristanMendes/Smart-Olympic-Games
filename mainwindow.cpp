#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "examen_medical.h"
#include <QMessageBox>
#include <QIntValidator>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id_supp->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id_modif->setValidator(new QIntValidator(0,99999999,this));
    ui->tab_examens->setModel(e.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
int id=ui->le_id->text().toInt();
QString nom=ui->le_nom->text();
QString type=ui->le_type->text();
int tranche_age=ui->le_age->text().toInt();
QString etat_sante=ui->le_etat->text();
QString coordonnees_athletes=ui->le_coordonnees->text();

examen_medical e(id,nom,type,tranche_age,etat_sante,coordonnees_athletes);

bool test = e.ajouter_examen();
if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),
                          QObject::tr("Ajout effectué\n" "Click Cancel to exit."),
                          QMessageBox::Cancel);
ui->tab_examens->setModel(e.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."),
                           QMessageBox::Cancel);

}



void MainWindow::on_pb_supprimer_clicked()
{ int id= ui->le_id_supp->text().toInt();
bool test=e1.supprimer_examen(id);
if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),
                          QObject::tr("Suppression effectuée.\n" "Click Cancel to exit."),
                          QMessageBox::Cancel);
ui->tab_examens->setModel(e1.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("Suppression non effectuée.\n" "Click Cancel to exit."),
                           QMessageBox::Cancel);
}


void MainWindow::on_pb_modif_clicked()
{int id = ui->le_id_modif->text().toInt();
QString nom=ui->le_nom_modif->text();
QString type=ui->le_type_modif->text();
int tranche_age=ui->le_age_modif->text().toInt();
QString etat_sante=ui->le_etat_modif->text();
QString coordonnees_athletes=ui->le_coordonnees_modif->text();
bool test=e2.modifier_examen(id, nom, type, tranche_age, etat_sante, coordonnees_athletes);

if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),
                          QObject::tr("Modification effectuée\n" "Click Cancel to exit."),
                          QMessageBox::Cancel);
ui->tab_examens->setModel(e2.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),
                           QObject::tr("Modification non effectuée.\n" "Click Cancel to exit."),
                           QMessageBox::Cancel);
}



