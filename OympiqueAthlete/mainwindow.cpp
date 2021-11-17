#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "athletesop.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQuery>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinterInfo>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->lineEdit_ID_3->setValidator(new QIntValidator(0, 99999, this));
ui->lineEdit_supprimerath->setValidator(new QIntValidator(0, 99999, this));
ui->lineEdit_Age_3->setValidator(new QIntValidator(0, 9999, this));
ui->table_athletes_2->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_boutton_ajouterath_clicked()
{
     bool test=false;
     //bool test2=false;

        int id=ui->lineEdit_ID_3->text().toInt();
        int age=ui->lineEdit_Age_3->text().toInt();
        QString nom=ui->lineEdit_Nom_3->text();

        QString prenom=ui->lineEdit_Prenom_3->text();
        QString sexe=ui->comboBox_sexe_3->currentText();
        QString nationalite=ui->lineEdit_nationalite_3->text();
        QString specialite=ui->lineEdit_specialite_3->text();
        QString mail=ui->lineEdit_mail_3->text();
        QString time=ui->comboBox_heure->currentText();

        athletesOP A(id,age,nom,prenom,sexe,nationalite,specialite,mail,time);
                if(A.Nomtest(nom)&&(A.Nomtest(prenom)&&(A.Nomtest(nationalite))&&(A.Nomtest(specialite))))
                {

                            test=A.ajouter();
                }
                else
                {
                    ui->label_nom_test->setText("nom , prenon , nationalite ou specialite mal remplie");
                }





          if(test)
          {
              QMessageBox::information(nullptr, QObject::tr("OK"),
                          QObject::tr("Ajout effectué\n"
                                      "Click Cancel to Exit."), QMessageBox::Cancel);
              ui->table_athletes_2->setModel(A.afficher());
          }

          else
          {
              QMessageBox::critical(nullptr, QObject::tr("not OK"),
                          QObject::tr("Ajout non effectué\n"
                                      "Click Cancel to Exit."), QMessageBox::Cancel);
          }


}

void MainWindow::on_boutton_supprimerath_clicked()
{
    athletesOP A1; A1.set_id(ui->lineEdit_supprimerath->text().toInt());
    bool test=A1.supprimer(A1.get_id());

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Suppression effectué\n"
                                "Click Cancel to Exit."), QMessageBox::Cancel);
        ui->table_athletes_2->setModel(A.afficher());
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Suppression non effectué\n"
                                "Click Cancel to Exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_table_athletes_2_activated(const QModelIndex &index)
{
    QSqlQuery query;
    QString val=ui->table_athletes_2->model()->data(index).toString();
    query.prepare("SELECT * from aolympiqueathlete where id= :id");

    query.bindValue(":id",val);

    if(query.exec())
    {
        while(query.next())
        {
           ui->lineEdit_ID_3->setText(query.value(0).toString());
           ui->lineEdit_Age_3->setText(query.value(1).toString());
           ui->lineEdit_Nom_3->setText(query.value(2).toString());
           ui->lineEdit_Prenom_3->setText(query.value(3).toString());
           ui->comboBox_sexe_3->setCurrentText(query.value(4).toString());
           ui->lineEdit_nationalite_3->setText(query.value(5).toString());
           ui->lineEdit_specialite_3->setText(query.value(6).toString());
           ui->lineEdit_mail_3->setText(query.value(7).toString());
        }
    }
    else
    {
            QMessageBox::critical(nullptr, QObject::tr("Transferer données"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_Modifierath_clicked()
{

    int id=ui->lineEdit_ID_3->text().toInt();
    int age=ui->lineEdit_Age_3->text().toInt();
    QString nom=ui->lineEdit_Nom_3->text();
    QString prenom=ui->lineEdit_Prenom_3->text();
    QString sexe=ui->comboBox_sexe_3->currentText();
    QString nationalite=ui->lineEdit_nationalite_3->text();
    QString specialite=ui->lineEdit_specialite_3->text();
    QString mail=ui->lineEdit_mail_3->text();
    QString time=ui->comboBox_heure->currentText();


    athletesOP A(id,age,nom,prenom,sexe,nationalite,specialite,mail,time);

    bool test=A.modifier(id);

    if(test)
    {
         ui->table_athletes_2->setModel(A.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("Modification effectué\n"
                                "Click Cancel to Exit."), QMessageBox::Cancel);


    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not OK"),
                    QObject::tr("Modification non effectué\n"
                                "Click Cancel to Exit."), QMessageBox::Cancel);
    }

}



void MainWindow::on_bouton_rechercherath_clicked()
{
    int id=ui->lineEdit_rechercher->text().toInt();
    ui->table_athletes_2->setModel(A.recherche(id));
    QString test=ui->lineEdit_rechercher->text();
   if(test=="")
   {
       ui->table_athletes_2->setModel(A.afficher());
   }


  /* QString nom=ui->lineEdit_rechercher->text();
   ui->table_athletes_2->setModel(A.rechercheNom(nom));

   if(test=="")
   {
       ui->table_athletes_2->setModel(A.afficher());
   }*/
}


void MainWindow::on_comboBox_trierath_currentIndexChanged(int index)
{
    if(index==1)
        ui->table_athletes_2->setModel(A.trier_age());
    else if(index==2)
        ui->table_athletes_2->setModel(A.trier_nationalite());
    else if(index==3)
        ui->table_athletes_2->setModel(A.trier_specialite());
}



void MainWindow::on_bouton_PDF_clicked()
{

    QPdfWriter pdf("C:/Users/mende/Desktop/COURS 2A19/PDFAthletes.pdf");

      QPainter painter(&pdf);

      int i = 4000;
      painter.setPen(Qt::red);
      painter.setFont(QFont("Arial", 30));
      painter.drawPixmap(QRect(200,200,2000,2000),QPixmap("C:/Users/mende/Desktop/Smart-Olympic-Games-2A19/OympiqueAthlete/essai_logo2.png"));
      painter.drawText(3000,1500,"LISTE DES ATHLETES");
      painter.setPen(Qt::black);
      painter.setFont(QFont("Arial", 50));
      // painter.drawText(1100,2000,afficheDC);
      painter.drawRect(2700,200,7300,2600);
      //painter.drawRect(1500,200,7300,2600);
      //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
      painter.drawRect(0,3000,9600,500);
      painter.setFont(QFont("Arial", 9));
      painter.drawText(300,3300,"ID");
      painter.drawText(2300,3300,"AGE");
      painter.drawText(4300,3300,"NOM");
      painter.drawText(6300,3300,"PRENOM");
      painter.drawText(8000,3300,"SEXE");
      painter.drawText(10300,3300,"NATIONALITE");
      painter.drawText(12300,3300,"SPECIALITE");
      painter.drawText(14300,3300,"MAIL");
      QSqlQuery query;
      query.prepare("select * from aolympiqueathlete");
      query.exec();
      while (query.next())
      {
          painter.drawText(300,i,query.value(0).toString());
          painter.drawText(2300,i,query.value(1).toString());
          painter.drawText(4300,i,query.value(2).toString());
          painter.drawText(6300,i,query.value(3).toString());
          painter.drawText(8000,i,query.value(4).toString());
          painter.drawText(10000,i,query.value(5).toString());
          painter.drawText(12000,i,query.value(6).toString());
          painter.drawText(14000,i,query.value(7).toString());
          i = i +500;
      }

      int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
      if (reponse == QMessageBox::Yes)
      {
          QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/mende/Desktop/COURS 2A19/PDFAthletes.pdf"));

          painter.end();
      }
      if (reponse == QMessageBox::No)
      {
          painter.end();
      }


}






void MainWindow::on_bouton_excel_clicked()
{
    QTableView *table;
               table = ui->table_athletes_2;

               QString filters("CSV files (.csv);;All files (.*)");
               QString defaultFilter("CSV files (*.csv)");
               QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                  filters, &defaultFilter);
               QFile file(fileName);

               QAbstractItemModel *model =  table->model();
               if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                   QTextStream data(&file);
                   QStringList strList;
                   for (int i = 0; i < model->columnCount(); i++) {
                       if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                           strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                       else
                           strList.append("");
                   }
                   data << strList.join(";") << "\n";
                   for (int i = 0; i < model->rowCount(); i++) {
                       strList.clear();
                       for (int j = 0; j < model->columnCount(); j++) {

                           if (model->data(model->index(i, j)).toString().length() > 0)
                               strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                           else
                               strList.append("");
                       }
                       data << strList.join(";") + "\n";
                   }
                   file.close();
                   QMessageBox::information(nullptr, QObject::tr("Export excel"),
                                             QObject::tr("Export avec succes .\n"
                                                         "Click OK to exit."), QMessageBox::Ok);
               }
}
