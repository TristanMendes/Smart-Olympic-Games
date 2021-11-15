#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "stade.h"
#include "agent.h"
#include "fan.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <iostream>
#include<QQuickItem>
using namespace std;


//Include Stats
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE
//Fin Include Stats


MainWindow::MainWindow(QWidget *parent):
     QMainWindow(parent),
     ui(new Ui::MainWindow)
{

ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(100, 999, this));
ui->le_id_agent->setValidator(new QIntValidator(1000, 9999, this));
ui->le_id_fan->setValidator(new QIntValidator(1000, 9999, this));
ui->tab_stade->setModel(S.afficher());
ui->tab_agent->setModel(A.afficher_agent());
ui->tab_fan->setModel(F.afficher_fan());
ui->tab_affectation->setModel(Aff.afficher_aff());
ui->qw_map->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
ui->qw_map->show();


auto obj = ui-> qw_map->rootObject();
connect(this,SIGNAL(setCenter(Qvariant,Qvariant)), obj, SLOT(setCenter(Qvarian,Qvariant)));

emit setCenter(25.000,50.000);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pb_ajouter_clicked()
{
    //Recuperation des informations saisies dans les champs
 int id=ui->le_id->text().toInt();//
 int capacite=ui->le_capacite->text().toInt();
 int nbre_evenement=ui->le_nbre_evenement->text().toInt();
 float surface=ui->le_surface->text().toFloat();
 QString nom=ui->le_nom->text();
 QString adresse=ui->le_adresse->text();
 QString specialite=ui->cb_specialite->currentText();

  Stade S(id,capacite,nbre_evenement,surface,nom,adresse,specialite);
bool test=S.ajouter();
if(test)
{

    QMessageBox::information(nullptr,QObject::tr("OK"),
    QObject::tr("Ajout effectué\n"
    "click Cancel to exit"),QMessageBox::Cancel);
     ui->tab_stade->setModel(S.afficher());//Refresh
}
else
    QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
    QObject::tr("Ajout not effectué.\n"
    "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()

{
  Stade S;
  S.setid(ui->le_id->text().toInt());
  bool test=S.supprimer(S.getid());

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

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" stade modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
    }


void MainWindow::on_cb_tri_currentIndexChanged(int index)
{
    if(index==1)
              ui->tab_stade->setModel(S.tri_id());
    else if(index==2)
              ui->tab_stade->setModel(S.tri_capacite());
    else if(index==3)
              ui->tab_stade->setModel(S.tri_nbre_evenement());
}





void MainWindow::on_pb_annuler_clicked()
{
    ui->le_id->setText(0);
    ui->tab_stade->setModel(S.afficher());
}

void MainWindow::on_pb_ajouter_agent_clicked()
{
    int id_agent=ui->le_id_agent->text().toInt();
    QString nom_agent=ui->le_nom_agent->text();
    QString prenom_agent=ui->le_prenom_agent->text();
    QString grade_agent=ui->cb_grade_agent->currentText();
    QString poste_agent=ui->cb_poste_agent->currentText();

     Agent A(id_agent,nom_agent,prenom_agent,grade_agent,poste_agent);
   bool test=A.ajouter_agent();
   if(test)
   {

       QMessageBox::information(nullptr,QObject::tr("OK"),
       QObject::tr("Ajout effectué\n"
       "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_agent->setModel(A.afficher_agent());//Refresh
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
       QObject::tr("Ajout not effectué.\n"
       "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_agent_clicked()
{
    Agent A;
    A.setid_agent(ui->le_id_agent->text().toInt());
    bool test=A.supprimer_agent(A.getid_agent());

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("Suppression avec succes.\n"
        "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_agent->setModel(A.afficher_agent());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
        QObject::tr("Echec de suppression.\n"
        "Click Cancel to exit"), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_agent_clicked()
{
    int id_agent=ui->le_id_agent->text().toInt();
    QString nom_agent=ui->le_nom_agent->text();
    QString prenom_agent=ui->le_prenom_agent->text();
    QString grade_agent=ui->cb_grade_agent->currentText();
    QString poste_agent=ui->cb_poste_agent->currentText();


    Agent A;
           bool test;
           test=A.modifier_agent(id_agent,nom_agent,prenom_agent,grade_agent,poste_agent);
           if(test)
           {
              ui->tab_agent->setModel(A.afficher_agent());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" Agent modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}

void MainWindow::on_cb_trier_agent_currentIndexChanged(int index)
{
    if(index==1)
          {
              ui->tab_agent->setModel(A.tri_agent());
          }else
              ui->tab_agent->setModel(A.tri_agent());
}



void MainWindow::on_pb_annuler_agent_clicked()
{
    ui->le_id_agent->setText(0);
    ui->tab_agent->setModel(A.afficher_agent());
}


void MainWindow::on_pb_ajouter_fan_clicked()
{
    int id_fan=ui->le_id_fan->text().toInt();
    QString nom_fan=ui->le_nom_fan->text();
    QString prenom_fan=ui->le_prenom_fan->text();
    QString nationalite_fan=ui->le_nationalite_fan->text();


     Fan F(id_fan,nom_fan,prenom_fan,nationalite_fan);
   bool test=F.ajouter_fan();
   if(test)
   {

       QMessageBox::information(nullptr,QObject::tr("OK"),
       QObject::tr("Ajout effectué\n"
       "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_fan->setModel(F.afficher_fan());//Refresh
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
       QObject::tr("Ajout not effectué.\n"
       "Click Cancel to exit"), QMessageBox::Cancel);
}
void MainWindow::on_pb_supprimer_fan_clicked()
{
   Fan F;
    F.setid_fan(ui->le_id_fan->text().toInt());
    bool test=F.supprimer_fan(F.getid_fan());

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("Suppression avec succes.\n"
        "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_fan->setModel(F.afficher_fan());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
        QObject::tr("Echec de suppression.\n"
        "Click Cancel to exit"), QMessageBox::Cancel);
}
void MainWindow::on_pb_modifier_fan_clicked()
{
    int id_fan=ui->le_id_fan->text().toInt();
    QString nom_fan=ui->le_nom_fan->text();
    QString prenom_fan=ui->le_prenom_fan->text();
    QString nationalite_fan=ui->le_nationalite_fan->text();



    Agent A;
           bool test;
           test=F.modifier_fan(id_fan,nom_fan,prenom_fan,nationalite_fan);
           if(test)
           {
              ui->tab_fan->setModel(F.afficher_fan());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" Fan modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}



void MainWindow::on_cb_trier_fan_currentIndexChanged(int index)
{
    if(index==1)
          {
              ui->tab_fan->setModel(F.tri_fan());
          }else
              ui->tab_fan->setModel(F.tri_fan());
}



void MainWindow::on_pb_annuler_fan_clicked()
{
    ui->le_id_fan->setText(0);
    ui->tab_fan->setModel(F.afficher_fan());
}



void MainWindow::stats(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);

                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);

                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );

                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
        }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                if(critere=="CAPACITE_STADE")
                    critere="Capacite";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();

}



void MainWindow::on_statsStadeCapacite_clicked()
{
    stats("STADES","CAPACITE_STADE",100,200,"Spectateurs");

}

void MainWindow::on_statsStadeSurface_clicked()
{
    stats("STADES","SURFACE",10,100,"Mcube");

}

void MainWindow::on_statsStadeNbrEvent_clicked()
{
    stats("STADES","NBRE_EVENEMENT",2,5,"Evenements");

}




void MainWindow::on_pb_football_clicked()
{
    QString specialite=ui->pb_football->text() ;
    ui->tab_specialite->setModel(S.rechercher_football(specialite)) ;
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr(" affiché  dans le tableau !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_athletisme_clicked()
{
    QString specialite=ui->pb_athletisme->text() ;
    ui->tab_specialite->setModel(S.rechercher_athletisme(specialite)) ;
    QMessageBox::information(nullptr, QObject::tr("OK"),
                QObject::tr(" affiché  dans le tableau !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_ajouter_affectation_clicked()
{
    int id_aff=ui->le_id_final->text().toInt();//
    int num_evenement=ui->le_num_evenement->text().toInt();
    QString specialite_aff=ui->cb_specialite_aff->currentText();

     Affectation Aff(id_aff,num_evenement,specialite_aff);
   bool test=Aff.ajouter_aff();
   if(test)
   {

       QMessageBox::information(nullptr,QObject::tr("OK"),
       QObject::tr("Ajout effectué\n"
       "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_affectation->setModel(Aff.afficher_aff());//Refresh
   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
       QObject::tr("Ajout not effectué.\n"
       "Click Cancel to exit"), QMessageBox::Cancel);
}


void MainWindow::on_pb_supprimer_affectation_clicked()
{
    Affectation Aff;
   Aff.setid_aff(ui->le_id_final->text().toInt());
    bool test=Aff.supprimer_aff(Aff.getid_aff());

    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("OK"),
        QObject::tr("Suppression avec succes.\n"
        "click Cancel to exit"),QMessageBox::Cancel);
        ui->tab_affectation->setModel(Aff.afficher_aff());
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not Ok"),
        QObject::tr("Echec de suppression.\n"
        "Click Cancel to exit"), QMessageBox::Cancel);
}


void MainWindow::on_pb_modifier_affectation_clicked()
{
    int id_aff=ui->le_id_final->text().toInt();
    int num_evenement=ui->le_num_evenement->text().toInt();
    QString specialite_aff=ui->cb_specialite_aff->currentText();



  Affectation Aff;
           bool test;
           test=Aff.modifier_aff(id_aff,num_evenement,specialite_aff);
           if(test)
           {
              ui->tab_affectation->setModel(Aff.afficher_aff());

              QMessageBox::information(nullptr,QObject::tr("OK"),
                QObject::tr(" Affectation modifé") ,QMessageBox::Ok);

             }else

                 QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                   QObject::tr("Erreur !.\n""Click Ok to exit."), QMessageBox::Ok);
}




void MainWindow::on_lineEditRechercheStade_textChanged(const QString &arg1)
{

    if(ui->lineEditRechercheStade->text()!="")
                {
                    QString idStade=ui->lineEditRechercheStade->text();
                    ui->tab_stade->setModel(S.rechercher(idStade));
                }
                 else
                    ui->tab_stade->setModel(S.afficher());



}

void MainWindow::on_lineEditRechercheAgent_textChanged(const QString &arg1)
{

    if(ui->lineEditRechercheAgent->text()!="")
                {
                    QString idAgent=ui->lineEditRechercheAgent->text();
                    ui->tab_agent->setModel(A.rechercher_agent(idAgent));
                }
                 else
                    ui->tab_agent->setModel(A.afficher_agent());
}



void MainWindow::on_lineEditRechercheFan_textChanged(const QString &arg1)
{
    if(ui->lineEditRechercheFan->text()!="")
                {
                    QString idFan=ui->lineEditRechercheFan->text();
                    ui->tab_fan->setModel(F.rechercherFan(idFan));
                }
                 else
                    ui->tab_fan->setModel(F.afficher_fan());
}

void MainWindow::on_valabiliteFan_clicked()
{
    QString idFan=ui->lineEditValabiliteFan->text();
    Fan fan=F.valabiliteFan(idFan);
    if(fan.getid_fan())

         {
        QString test="";
        QString str = " Fan valable \n ID Fan :" +QString::number(fan.getid_fan())+" \n Nom Fan : "+fan.getnom_fan()+ "\n Prenom Fan : "+fan.getprenom_fan()+" \n Nationalite Fan : "+fan.getnationalite_fan();


        QMessageBox::information(this, tr("Affectation"),str,QMessageBox::Ok);

        }


        else
        QMessageBox::critical(nullptr,QObject::tr("Non trouve"),
          QObject::tr("Fan non valable."), QMessageBox::Ok);




}
