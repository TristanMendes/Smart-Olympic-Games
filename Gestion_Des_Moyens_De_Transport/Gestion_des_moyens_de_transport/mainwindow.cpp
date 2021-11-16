#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moyensdetransport.h"


#include <QMessageBox>
#include <QIntValidator>
#include <QtDebug>
#include <QPlainTextEdit>
#include <QSqlQuery>

#include <QTextStream>
#include <QPainter>
#include <QTextStream>

#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include "qcustomplot.h"








MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);  //points
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);   //No line


     ui->customPlot->replot();
     /*int size=10;
     QVector<double> x(size),y (size);
     for(int i=0; i<size; i++)
           {
             x[i]=i;
             y[i]=i;

           }*/



     QLinearGradient gradient(0, 0, 0, 400);
                   gradient.setColorAt(0, QColor(90, 90, 90));
                   gradient.setColorAt(0.38, QColor(105, 105, 105));
                   gradient.setColorAt(1, QColor(70, 70, 70));
                   ui->customPlot->setBackground(QBrush(gradient));


                   // create empty bar chart objects:
                   QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
                   amande->setAntialiased(false);
                   amande->setStackingGap(1);
                    //set names and colors:
                   amande->setName("Le nombre de billets en fonction des moyens de transport ");
                   amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
                   amande->setBrush(QColor(0, 168, 140));
                   // stack bars on top of each other:

                   // prepare x axis with country labels:
                   QVector<double> ticks;
                   QVector<QString> labels;
                   M.statistique(&ticks,&labels);
                   QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                                 textTicker->addTicks(ticks, labels);
                                 ui->customPlot->xAxis->setTicker(textTicker);
                                 ui->customPlot->xAxis->setTickLabelRotation(60);
                                 ui->customPlot->xAxis->setSubTicks(false);
                                 ui->customPlot->xAxis->setTickLength(0, 4);
                                 ui->customPlot->xAxis->setRange(0, 8);
                                 ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
                                 ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
                                 ui->customPlot->xAxis->grid()->setVisible(true);
                                 ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                                 ui->customPlot->xAxis->setTickLabelColor(Qt::white);
                                 ui->customPlot->xAxis->setLabelColor(Qt::white);




                                 // prepare y axis:
                                              ui->customPlot->yAxis->setRange(0,10);
                                              ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
                                              ui->customPlot->yAxis->setLabel("Statistiques");
                                              ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
                                              ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
                                              ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
                                              ui->customPlot->yAxis->grid()->setSubGridVisible(true);
                                              ui->customPlot->yAxis->setTickLabelColor(Qt::white);
                                              ui->customPlot->yAxis->setLabelColor(Qt::white);
                                              ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                                              ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));



                                              // Add data:

                                                            QVector<double> PlaceData;
                                                            QSqlQuery q1("select nbr_billet from Moyens_De_Transport");
                                                            while (q1.next()) {
                                                                          int  nbr = q1.value(0).toInt();
                                                                          PlaceData<< nbr;
                                                                            }
                                                            amande->setData(ticks, PlaceData);




                                                            // setup legend:
                                                                         ui->customPlot->legend->setVisible(true);
                                                                         ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                                                                         ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
                                                                         ui->customPlot->legend->setBorderPen(Qt::NoPen);
                                                                         QFont legendFont = font();
                                                                         legendFont.setPointSize(5);//888//
                                                                         ui->customPlot->legend->setFont(legendFont);
                                                                         ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);











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
    ui->le_billet_nbr_billet_actuel->setValidator( new QIntValidator(100, 9999, this));
    ui->le_QR_nbr_billet->setValidator( new QIntValidator(100, 9999, this));





    ui->table_moyens->setModel(M.afficher());
    ui->tab_aerien->setModel(M1.afficher_billet());
    ui->tab_QR->setModel(M1.afficher_billet());

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


                     if((result))
                     {

                   QMessageBox::information(nullptr, QObject::tr("Supprimer un moyen de transport"),
                                     QObject::tr("Suppression effectuée.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);}


                     else
                         QMessageBox::critical(nullptr, QObject::tr("Supprimer un moyen de transport"),
                                     QObject::tr("Suppression non effectuée !.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);



               /*QMessageBox::critical(nullptr, QObject::tr("Supprimer un moyen de transport"),
                               QObject::tr("Moyen inexistant!.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);*/
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


void MainWindow::on_B_recherche_nom_clicked()
{

    QString nom =ui->le_recherche_nom->text();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_nom(nom);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_nom(nom));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par son nom"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par son nom"),
                  QObject::tr("Echec de recherche !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_B_recherche_capacite_clicked()
{
   int capacite =ui->le_recherche_capacite->text().toInt();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_capacite(capacite);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_capacite(capacite));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par sa capacite"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par sa capacite"),
                  QObject::tr("Echec de recherche !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_B_recherche_dest_dep_clicked()
{
    QString destination_depart =ui->le_rechercher_dest_dep->text();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_dest_dep(destination_depart);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_dest_dep(destination_depart));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par sa destination de depart"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par sa destination de depart"),
                  QObject::tr("Echec de recherche !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}














void MainWindow::on_B_choisir_clicked()
{
    int id =ui->le_choix_id->text().toInt();

     MoyensDeTransport M;
   QSqlQueryModel *test=M.choix_moyen(id);
   if(test)
 {

       ui->tab_choix->setModel(M.choix_moyen(id));
 QMessageBox::information(nullptr, QObject::tr("Choisir un moyen de transport"),
                   QObject::tr("Element choisi.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

 }
   else
       QMessageBox::critical(nullptr, QObject::tr("Choisir un moyen de transport"),
                   QObject::tr("Element non choisi!.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_B_recherche_type_clicked()
{
    QString type =ui->le_recherche_type->currentText();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_type(type);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_type(type));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par son type"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par son type"),
                  QObject::tr("Echec de recherche !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_B_recherche_nbr_voyages_clicked()
{
    int nbr_voyages =ui->le_recherche_nbr_voyages->text().toInt();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_nbr_voyages(nbr_voyages);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_nbr_voyages(nbr_voyages));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par son nombre de voyages"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par son nombre de voyages"),
                  QObject::tr("Echec de recherche !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}





void MainWindow::on_B_recherche_dest_arr_clicked()
{
    QString destination_arrivee =ui->le_recherche_dest_arr->text();

    MoyensDeTransport M;
  QSqlQueryModel *test=M.rechercher_dest_arr(destination_arrivee);
  if(test)
{

      ui->tab_recherche->setModel(M.rechercher_dest_arr(destination_arrivee));
QMessageBox::information(nullptr, QObject::tr("Rechercher un moyen de transport par sa destination d'arrivee"),
                  QObject::tr("Element trouve.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Rechercher un moyen de transport par sa destination d'arrivee"),
                  QObject::tr("Echec de recherche!.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}



void MainWindow::on_B_billet_entrer_clicked()
{
    QMessageBox msgbox;

    int id =ui->le_billet_id->text().toInt();
    int nbr_billet=ui->le_billet_nbr_billet_actuel->text().toInt();
    int nb=ui->le_billet_nbr_billet_ajouter->text().toInt();
    MoyensDeTransport M1 ;
  int test=M1.modifie_billet(id,nbr_billet,nb);
  if(test)
{


  ui->tab_aerien->setModel(M1.afficher_billet());
QMessageBox::information(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("Billet ajoute.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else

     QMessageBox::critical(nullptr, QObject::tr("Ajouter un billet"),
                  QObject::tr("Billet non ajoute!.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_B_QR_clicked()
{

    int id =ui->le_QR_id->text().toInt();
    int nbr_billet=ui->le_QR_nbr_billet->text().toInt();
    int nb=ui->le_QR_nbr_QR->text().toInt();







    MoyensDeTransport M1 ;
  bool test=M1.modifier_QR_code(id,nbr_billet,nb);
  if(test)
{

      ui->tab_QR->setModel(M1.afficher_billet());
QMessageBox::information(nullptr, QObject::tr("Generer un QR Code"),
                  QObject::tr("QR code genere avec succes.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Generer un QR Code"),
                  QObject::tr("Echec!.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);





}

void MainWindow::addPoint(double x, double y)
{
qv_x.append(x);
qv_y.append(y);
}

void MainWindow::clearData()
{
qv_x.clear();
qv_y.clear();
}

void MainWindow::plot()
{
ui->plot->graph(0)->setData(qv_x,qv_y);
ui->plot->replot();
ui->plot->update();
}








void MainWindow::on_B_ajouter_clicked()
{
addPoint(ui->spin_x->value(),ui->spin_y->value());
plot();

}





void MainWindow::on_B_clear_clicked()
{
clearData();
plot();
}



