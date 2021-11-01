#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "athletesop.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->lineEdit_ID_3->setValidator(new QIntValidator(0, 99999999, this));
ui->table_athletes_2->setModel(A.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_boutton_ajouterath_clicked()
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

        bool test=A.ajouter();

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
