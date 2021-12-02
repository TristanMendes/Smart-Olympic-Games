#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "moyensdetransport.h"


#include <QMessageBox>          //afficher des messages
#include <QIntValidator>
#include <QtDebug>  //correction en affichant des messages
#include <QSqlQuery>
#include "qcustomplot.h" // un widget Qt C++ pour le traçage et la visualisation des données.







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    QBarSet *set0=new QBarSet("Voiture");
    QBarSet *set1=new QBarSet("Train");
    QBarSet *set2=new QBarSet("Avion");
    QBarSet *set3=new QBarSet("Bus");
    QBarSet *set4=new QBarSet("Bateau");

    *set0<<20<<30<<50;
    *set1<<100<<80<<10<<30;
    *set2<<0<<20<<30<<40;
    *set3<<50<<0<<30<<10;
    *set4<<30<<70<<60<<30;

    QBarSeries *series= new QBarSeries();
    series->append(set0);
     series->append(set1);
      series->append(set2);
       series->append(set3);
        series->append(set4);


      QChart *chart =new QChart();
      chart->addSeries(series);
      chart->setTitle("Moyens de transport");
       chart->setAnimationOptions(QChart::SeriesAnimations);

       QStringList categories;
       categories <<"Jour 1"<<"Jour 2"<<"Jour 3"<<"Jour 4"<<"Jour 5"<<"Jour 6"<<"Jour 7";
       QBarCategoryAxis *axis=new QBarCategoryAxis();
       axis->append(categories);
       chart->createDefaultAxes();
       chart->setAxisX (axis,series);
       QChartView *chartView=new QChartView(chart);
       chartView->setParent(ui->horizontalFrame);










    ui->plot->addGraph();
    ui->plot->xAxis->setRange(0,7);
    ui->plot->yAxis->setRange(0,500);
    ui->plot->setInteractions(QCP::iRangeDrag |QCP::iRangeZoom|QCP::iSelectPlottables);

    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);  //points
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsLine);   // line


     ui->customPlot->replot();















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
                bool test=M.verifier_id(id);


                     if((result)&&(test==true))
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
qv_x.append(x);   //1)voiture prive /2)train /3)bus /4)Metro/5)Avion/6)Bateau/7)Jet prive
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




void MainWindow::on_B_ajouter_annuler_clicked()
{
          ui->le_id->clear();
          ui->le_nom->clear();
          ui->le_type->clear();
          ui->le_nbr_voyages->clear();
          ui->le_dest_dep->clear();
          ui->le_dest_arri->clear();
          ui->le_capacite->clear();
          ui->le_nbr_billet->clear();
}

void MainWindow::on_B_modifier_annuler_clicked()
{
     ui->le_m_id->clear();
     ui->le_m_nom->clear();
     ui->le_m_type->clear();
     ui->le_m_nbr_voyages->clear();
     ui->le_m_dest_dep->clear();
     ui->le_m_dest_arr->clear();
     ui->le_m_capacite->clear();
     ui->le_m_nbr_billet->clear();
}

void MainWindow::on_B_supprimer_annuler_clicked()
{
    ui->le_id_supp->clear();
}

void MainWindow::on_B_QR_annuler_clicked()
{
    ui->le_QR_id->clear();
    ui->le_QR_nbr_billet->clear();
    ui->le_QR_nbr_QR->clear();
}

void MainWindow::on_B_billet_annuler_clicked()
{
    ui->le_billet_id->clear();
    ui->le_billet_nbr_billet_actuel->clear();
    ui->le_billet_nbr_billet_ajouter->clear();
}

void MainWindow::on_B_choix_annuler_clicked()
{
  ui->le_choix_id->clear();
}

void MainWindow::on_B_excel_clicked()
{
    QTableView *table;
    table = ui->tab_choix;
    QString filters("XLS files (.xls);;All files (.*)");
    QString defaultFilter("XLS files (*.xls)");
    QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),filters, &defaultFilter);
    QFile file(fileName);
    QAbstractItemModel *model =  table->model();

    if (file.open(QFile::WriteOnly | QFile::Truncate))
    {QTextStream data(&file);
    QStringList strList;
    for (int i = 0; i < model->columnCount(); i++)
    {if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
    strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
    else strList.append("");}
    data << strList.join(";") << "\n";
    for (int i = 0; i < model->rowCount(); i++)
    {strList.clear();
    for (int j = 0; j < model->columnCount(); j++)
    {if (model->data(model->index(i, j)).toString().length() > 0)
    strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
    else strList.append("");}
    data << strList.join(";") + "\n";}
    file.close();
    QMessageBox::information(nullptr, QObject::tr("Export excel"),QObject::tr("Export avec succes .\n" "Click OK to exit."),QMessageBox::Ok);}


}
