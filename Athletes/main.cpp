#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include"connexion.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    connexion c;// une seule instance de la classe connexion
    bool test= c.createconnect();
    MainWindow w;
     w.show();
    if(test)//si la connexion est etablie
    {

    QMessageBox::information(nullptr, QObject::tr("database is open"),QObject::tr("Connection Reussie.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }else//si la connexion a échoué
        QMessageBox::critical(nullptr, QObject::tr("database is open"),QObject::tr("Connection Echoué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    return a.exec();
}

