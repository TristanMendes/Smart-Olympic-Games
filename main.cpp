#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include <Connexion.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c; // une seule instance de la classe connexion
     bool test=c.ouvrirConnexion(); //Etablir la connexion
    MainWindow w;//appel des constructeurs des methodes doit se faire apres avoir etablie la connexion à la BD

    if(test) //si la connexion est établie
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel."), QMessageBox::Cancel);

}
    else //si la connexion a echoué
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
