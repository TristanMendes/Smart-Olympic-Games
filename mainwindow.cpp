#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_examens_medicaux.h"
#include "gestion_des_moyens_de_transport.h"


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


void MainWindow::on_pb_gestion_examens_medicaux_clicked()
{gestion_examens_medicaux e;
e.exec();}



void MainWindow::on_pushButton_clicked()
{gestion_des_moyens_de_transport m;
m.exec();}
