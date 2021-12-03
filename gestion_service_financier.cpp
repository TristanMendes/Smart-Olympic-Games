#include "gestion_service_financier.h"
#include "ui_gestion_service_financier.h"

#include <QObject>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QPainter>

gestion_service_financier::gestion_service_financier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_service_financier)
{
    QString st = facAff.get_Statut();
    ui->setupUi(this);
    ui->tableView_Afficher->setModel(facAff.consulterFacture());
    ui->tableView_Payer->setModel(facAff.afficherFacturesNonPayee());
}

gestion_service_financier::~gestion_service_financier()
{
    delete ui;
}

void gestion_service_financier::on_pushButton_clicked()
{
    QString ref = ui->lineEditRef->text();
        QString dateC = ui->dateEdit_creation->text();
        QString stat = ui->comboBoxStatut->currentText();
        int mon = ui->lineEditMontant->text().toInt();
        QString nbser = ui->comboBoxNbServ->currentText();

        /*
        if(stat == "Payee")
        {
            statInt = 1;
        }
        else
        {
            statInt = 2;
        }
        if(nbser == "Transport")
        {
            nbserInt = 1;
        }
        else
        {
            nbserInt = 2;
        }
        */

        factures f(ref,nbser,stat,mon,dateC,dateC);

        bool ajout = f.ajouterFacture();

        if(ajout)
        {
           ui->tableView_Afficher->setModel(facAff.consulterFacture());
           QMessageBox::information(nullptr,QObject::tr("OK"),
                                    QObject::tr("Ajout Effectue \n"
                                                "Click Cancel to exit . "),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                  QObject::tr("Ajout non Efectue \n"
                                              "Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void gestion_service_financier::on_pushButtonSupprimer_clicked()
{

}

void gestion_service_financier::on_pushButtonPayer_clicked()
{

}

void gestion_service_financier::on_pushButton_2_clicked()
{

}

void gestion_service_financier::on_pushButton_4_clicked()
{

}

void gestion_service_financier::on_pushButtonModifier_clicked()
{

}

void gestion_service_financier::on_pushButtonPdf_2_clicked()
{

}

void gestion_service_financier::on_pushButtonPdf_clicked()
{

}
