#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historique.h"
#include <QDebug>
#include <QObject>
#include <QFile>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int ret = a.connect_arduino();
    switch (ret)
    {
        case(0):
        {
            qDebug() << "arduino is available and connected to : "<< a.getarduino_port_name();
            break;
        }
        case(1):
        {
            qDebug() << "arduino is available but not connected to : "<< a.getarduino_port_name();
            break;
        }
        case(-1):
        {
            qDebug() << "arduino not available  : ";
            break;
        }


    }
    QByteArray serialdate = a.read_from_arduino();
    qDebug() << serialdate;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QString pass = "1234";
    QString passEdit = ui->password->text();
    QFile file("historiqueLogin.txt");
    file.open(QIODevice::WriteOnly );
    QTextStream text(&file);
    QDateTime date = QDateTime::currentDateTime();
    QString formatTime = date.toString("dd.mm.yyyy");

    if(pass == passEdit)
    {
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("WELCOME \n",
                                            "Click Cancel to Exit."),QMessageBox::Cancel) ;
       text << "Access Accepted " << formatTime << endl;
       a.write_to_arduino("1");
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("ERROR"),
                              QObject::tr("Access DENIED \n"
                              "Click Cancel to Exit."),QMessageBox::Cancel);
       text << "Access Denied " << formatTime << endl;
       a.write_to_arduino("0");
    }

    file.close();
}

void MainWindow::on_pushButton_clicked()
{
   historique h;
   h.exec();
}
