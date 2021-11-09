#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "athletesop.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->lineEdit_ID_3->setValidator(new QIntValidator(0, 99999999, this));
ui->lineEdit_supprimerath->setValidator(new QIntValidator(0, 99999999, this));
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

        int id=ui->lineEdit_ID_3->text().toInt();
        int age=ui->lineEdit_Age_3->text().toInt();
        QString nom=ui->lineEdit_Nom_3->text();

        QString prenom=ui->lineEdit_Prenom_3->text();
        QString sexe=ui->comboBox_sexe_3->currentText();
        QString nationalite=ui->lineEdit_nationalite_3->text();
        QString specialite=ui->lineEdit_specialite_3->text();
        QString mail=ui->lineEdit_mail_3->text();

        athletesOP A(id,age,nom,prenom,sexe,nationalite,specialite,mail);
                if(A.Nomtest(nom))
                {

                            test=A.ajouter();
                }
                else
                {
                    ui->label_nom_test->setText("Nom invalid");
                }

                /*if(A.Prenomtest(prenom))
                {
                    test=A.ajouter();
                }

                else
                {
                    ui->label_prenom_test->setText("Prenom invalid");
                }*/


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

    athletesOP A(id,age,nom,prenom,sexe,nationalite,specialite,mail);

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
    QString nom=ui->lineEdit_rechercher->text();
    ui->table_athletes_2->setModel(A.recherche(id));
    ui->table_athletes_2->setModel(A.rechercheNom(nom));

   QString test=ui->lineEdit_rechercher->text();
   if(test=="")
   {
       ui->table_athletes_2->setModel(A.afficher());
   };
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
