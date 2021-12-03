#include "mainwindow.h"
#include <QMessageBox>
#include "connexion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;//une seule instance de la classe connection
    bool test=c.createconnect();//etablir la connexion
    MainWindow w;
    w.show();
    if (test)
    {QMessageBox::information(nullptr, QObject::tr("database is open"),
                              QObject::tr("connection successful.\n"
                                          " Click Cancel to exit."),
                              QMessageBox::Cancel);
     }
    else
     QMessageBox::critical(nullptr,QObject::tr("database is not open"),
                           QObject::tr("connection failed.\n"
                                       " Click Cancel to exit."),
                           QMessageBox::Cancel);
    return a.exec();
}
