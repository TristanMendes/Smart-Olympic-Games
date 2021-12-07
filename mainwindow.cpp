#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestion_examens_medicaux.h"
#include "gestion_des_moyens_de_transport.h"
#include "gestion_athletes.h"
#include "gestion_service_financier.h"
#include "gestion_stades.h"
#include "gestion_hebergements.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Smart Olympic Games");
    setWindowIcon(QIcon(":/icone_app.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_gestion_examens_medicaux_clicked()
{gestion_examens_medicaux e;
e.exec();}


void MainWindow::on_pb_gestion_moyens_transport_clicked()
{gestion_des_moyens_de_transport m;
    m.exec();

}

void MainWindow::on_gestion_athletes_clicked()
{gestion_athletes a;
a.exec();}



void MainWindow::on_gestion_factures_clicked()
{gestion_service_financier f;
f.exec();}

void MainWindow::on_gestion_stades_clicked()
{gestion_stades s;
s.exec();}

void MainWindow::on_gestion_hebergements_clicked()
{gestion_hebergements h;
h.exec();}
