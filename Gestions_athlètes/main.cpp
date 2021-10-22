#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include"connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connexion c;
    bool test= c.createconnect();
    if(test)
    {
    w.show();
    QMessageBox::critical(nullptr, QObject::tr("database is open"),QObject::tr("Connection Reussie.\n""Click Cancle to exit."),QMessageBox::Cancel);
    }else
        QMessageBox::critical(nullptr, QObject::tr("database is open"),QObject::tr("Connection Echoué.\n""Click Cancle to exit."),QMessageBox::Cancel);
    return a.exec();
}
