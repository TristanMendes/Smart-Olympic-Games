#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "athletes.h"
#include <QMessageBox>
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    int Id=ui->lineEdit_id->text().toInt();
    int Age=ui->lineEdit_age->text().toInt();
    QString Nom=ui->lineEdit_nom->text();
    QString Prenom=ui->lineEdit_prenom->text();
    QString Nationalite=ui->lineEdit_nation->text();
    QString Sexe=ui->comboBox_sexe->currentText();
    QString Specialite=ui->lineEdit_special->text();
    QString Mail=ui->lineEdit_mail->text();

    Athletes A(Id,Age,Nom,Prenom,Nationalite,Sexe,Specialite,Mail);
    bool test=A.ajouter();

      if(test)
      {
          QMessageBox::information(nullptr, QObject::tr("OK"),
                      QObject::tr("Ajout effectué\n"
                                  "Click Channel to Exit."), QMessageBox::Cancel);
      }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("not OK"),
                      QObject::tr("Ajout non effectué\n"
                                  "Click Channel to Exit."), QMessageBox::Cancel);
      }
}
