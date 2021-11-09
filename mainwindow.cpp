#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
#include <QMessageBox>
#include <QIntValidator>


MainWindow::MainWindow(QWidget *parent)://constructeur de la classe mainwindow généré automatiquement(initalitation de la classe n3abi fih les attributs)
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
ui->tab_stade->setModel(S.afficher());//appel de la methode afficher()via l'attribut S dans le constructeur de la classe mainwindow

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    //Recuperation des informations saisies dans les champs
 int id=ui->le_id->text().toInt();//convertir la chaine saisie en un entier car l'attribut id est de type int
 int capacite=ui->le_capacite->text().toInt();
 int nbre_evenement=ui->le_nbre_evenement->text().toInt();
 float surface=ui->le_surface->text().toFloat();
 QString nom=ui->le_nom->text();
 QString adresse=ui->le_adresse->text();
 QString specialite=ui->cb_specialite->currentText();

  Stade S(id,capacite,nbre_evenement,surface,nom,adresse,specialite);//instancier un objet de la classe stade en utilisant les informations saisies dans l'interface
bool test=S.ajouter();//inserer l'objet stade instancié dans la tavle stade et recuperer la valeur de retour de query.exec()
if(test) //si requete executée==> QMessageBox::information
{

    QMessageBox::information(nullptr,QObject::tr("OK"),
    QObject::tr("Ajout effectué\n"
    "click Cancel to exit"),QMessageBox::Cancel);
     ui->tab_stade->setModel(S.afficher());//Refresh
}
else //si requete non executée==> QMessageBox::critical
    QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
    QObject::tr("Ajout not effectué.\n"
    "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()

{
  Stade S;
  S.setid(ui->le_id->text().toInt());
  bool test=S.supprimer(S.getid());//appel de la methode supprimer() via l'attribut S

  if(test)
  {

      QMessageBox::information(nullptr,QObject::tr("OK"),
      QObject::tr("Suppression avec succes.\n"
      "click Cancel to exit"),QMessageBox::Cancel);
      ui->tab_stade->setModel(S.afficher());
  }
  else
      QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
      QObject::tr("Echec de suppression.\n"
      "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{

    int id=ui->le_id->text().toInt();
    int capacite=ui->le_capacite->text().toInt();
    int nbre_evenement=ui->le_nbre_evenement->text().toInt();
    float surface=ui->le_surface->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->le_adresse->text();
    QString specialite=ui->cb_specialite->currentText();


    Stade S;
           bool test;
           test=S.modifier(id,capacite,nbre_evenement,surface,nom,adresse,specialite);
           if(test)
           {
              ui->tab_stade->setModel(S.afficher());

              QMessageBox::information(nullptr,QObject::tr("modifier stade"),
                QObject::tr(" stade modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("modifier stade"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
    }


void MainWindow::on_cb_tri_currentIndexChanged(int index)
{
    if(index==1)
          {
              ui->tab_stade->setModel(S.tri_Stade());
          }else
              ui->tab_stade->setModel(S.tri_Stade());

}

void MainWindow::on_pb_rechercher_stade_clicked()
{
    int id=ui->le_id->text().toInt() ;
    ui->tab_stade->setModel(S.rechercher(id)) ;
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr(" affiché  dans le tableau !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_annuler_clicked()
{
    ui->le_id->setText(0);
    ui->tab_stade->setModel(S.afficher());
}
