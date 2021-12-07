#include "gestion_hebergements.h"
#include "ui_gestion_hebergements.h"
#include "hebergement.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>
#include <QSqlQuery>
#include "calendrier.h"
#include <QSystemTrayIcon>
#include <iostream>
using namespace std;
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include<QQuickItem>
#include<QQuickItem>
QT_CHARTS_USE_NAMESPACE


gestion_hebergements::gestion_hebergements(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_hebergements)
{
    ui->setupUi(this);
    setWindowTitle("Gestion des hebergements");
    setWindowIcon(QIcon(":/icone_app.png"));
    ui->le_identifiant->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_id_supp->setValidator(new QIntValidator(0, 99999999, this));
    ui->rechercher->setValidator(new QIntValidator(0, 99999999, this));
    ui->tab_hebergement->setModel(H.afficher());
    ui->tab_hebergement_2->setModel(H.afficher());
    ui->table_prix->setModel(H.afficher());
   ui->table_periode->setModel(c.afficher());
   ui->table_payment->setModel(p.afficher());
}

gestion_hebergements::~gestion_hebergements()
{
    delete ui;
}


void gestion_hebergements::on_pb_ajouter_clicked()
{
    int identifiant=ui->le_identifiant->text().toInt();
    QString nom=ui->le_nom->text();
    QString adresse=ui->le_adresse->text();
    int nombre_etoile=ui->le_nombre_etoile->text().toInt();
    int nombre_des_chambres=ui->le_nombre_des_chambres->text().toInt();
    int note=ui->le_note->text().toInt();
    int prix=ui->le_prix->text().toInt();


     Hebergement H(identifiant,nom,adresse,nombre_etoile,nombre_des_chambres,note,prix);
     bool test=H.ajouter();
     if (test)
     {
       QMessageBox::information(nullptr,QObject::tr("Ajout avec succes"),QObject::tr("SUCCES"),QMessageBox::Ok) ;
     ui->tab_hebergement->setModel(H.afficher());
     ui->tab_hebergement_2->setModel(H.afficher());
     }else
         QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                     QObject::tr("Echec d'ajout.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_hebergements::on_pb_supprimer_clicked()
{
    Hebergement H1; H1.setidentifiant(ui->le_id_supp->text().toInt());
    bool test=H1.supprimer(H1.getidentifiant());
    if (test)
    {
      QMessageBox::information(nullptr,QObject::tr("Suppression avec succes"),QObject::tr("SUCCES"),QMessageBox::Ok) ;
    }else

        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Echec de suppression.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_hebergement->setModel(H.afficher());
ui->tab_hebergement_2->setModel(H.afficher());



}



void gestion_hebergements::on_pb_modifier_clicked()
{

    int identifiant=ui->le_identifiant->text().toInt() ;
    QString nom=ui->le_nom->text() ;
    QString adresse=ui->le_adresse->text();
    int nombre_etoile=ui->le_nombre_etoile->text().toInt();
    int nombre_des_chambres=ui->le_nombre_des_chambres->text().toInt();
    int note=ui->le_note->text().toInt();
    int prix=ui->le_prix->text().toInt();




             Hebergement H(identifiant,nom,adresse,nombre_etoile,nombre_des_chambres,note,prix);
            bool test=H.modifier(identifiant,nombre_etoile,nombre_des_chambres,note,prix);
            if(test)
            {
                ui->tab_hebergement->setModel(H.afficher());
                ui->tab_hebergement_2->setModel(H.afficher());
                QMessageBox::information(nullptr, QObject::tr("succes"),
                            QObject::tr("HEBERGEMENT modifié."), QMessageBox::Ok);
        }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("erreur"),
                           QObject::tr("erreur de modification."), QMessageBox::Ok);
    }
}

void gestion_hebergements::on_pb_annuler_clicked()
{


        ui->le_identifiant->setText(0) ;
          ui->le_nom->setText(0) ;
          ui->le_adresse->setText(0) ;
          ui->le_nombre_etoile->setText(0) ;
          ui->le_nombre_des_chambres->setText(0) ;
          ui->le_note->setText(0) ;
          ui->le_prix->setText(0) ;

}




void gestion_hebergements::on_comboBox_currentIndexChanged(int index)
{
    if(index==1)
      {
          ui->tab_hebergement_2->setModel(H.sort_Hebergement());
      }else
          ui->tab_hebergement_2->setModel(H.sort_Hebergement());
}

void gestion_hebergements::on_pb_rechercher_clicked()
{
    int iden=ui->rechercher->text().toInt() ;
    ui->tab_hebergement_2->setModel(H.rechercher(iden)) ;
    QMessageBox::information(nullptr, QObject::tr("succes"),
                QObject::tr(" affiche  dans le tableau !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_hebergements::on_pb_annuler_2_clicked()
{

            ui->rechercher->setText(0) ;
            ui->tab_hebergement_2->setModel(H.afficher());

}



void gestion_hebergements::on_tab_hebergement_activated(const QModelIndex &index)
{
    QSqlQuery query ;
        QString val=ui->tab_hebergement->model()->data(index).toString();
        query.prepare("SELECT * from hebergement where id_hebergement=:id_hebergement ");

        query.bindValue(":id_hebergement",val);
        if(query.exec())
        {
            while(query.next())
            {
                ui->le_identifiant->setText(query.value(0).toString());
                ui->le_nom->setText(query.value(1).toString());
                ui->le_adresse->setText(query.value(2).toString());
                ui->le_nombre_etoile->setText(query.value(3).toString());
                ui->le_nombre_des_chambres->setText(query.value(4).toString());
                ui->le_note->setText(query.value(5).toString());
                ui->le_prix->setText(query.value(6).toString());

            }
        }
        else
        {
                QMessageBox::critical(nullptr, QObject::tr("Transferer données"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

}



void gestion_hebergements::on_pb_ajouter_2_clicked()
{
    {
        int id=ui->le_id_2->text().toInt();
        QDate date_deb=ui->le_date_deb->date();
       QDate date_fin=ui->le_date_fin->date();
      int periode=ui->la_periode->text().toInt();

        calendrier c(id,date_deb,date_fin,periode);

    bool test=c.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("calendrier"),QObject::tr("calendrier ajouté\n" "click ok to exit"),QMessageBox::Ok);
        ui->le_id_2->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
        ui->tab_etudiant_2->setModel(c.afficher());//actualisation


        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                 notifyIcon->show();
                                 notifyIcon->setIcon(QIcon("icone.png"));

                                 notifyIcon->showMessage("GESTION hebergement   ","calendrier Ajouté",QSystemTrayIcon::Information,15000);
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("calendrier"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }




    }
}

void gestion_hebergements::on_le_modifier_2_clicked()
{
    int id= ui->le_id_2->text().toInt();

            QDate date_deb=ui->le_date_deb->date();
            QDate date_fin=ui->le_date_fin->date();
            int periode= ui->la_periode->text().toInt();
                           calendrier c(id,date_deb,date_fin,periode);
                           ui->le_id_2->setText("");


                bool test = c.update(id,date_deb,date_fin,periode);


                if(test)

                {
                     ui->tab_etudiant_2->setModel(c.afficher());
                     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                              notifyIcon->show();
                                              notifyIcon->setIcon(QIcon("icone.png"));

                                              notifyIcon->showMessage("GESTION hebergement  ","calendrier Modifier",QSystemTrayIcon::Information,15000);
                              QMessageBox::information(nullptr, QObject::tr("OK"),
                                          QObject::tr("Modification effectué.\n"
                                                      "Click Cancel to exit."), QMessageBox::Cancel);
                    QMessageBox::information(nullptr, QObject::tr("update "),
                                QObject::tr("Participant modifie\n"
                "Click Cancel to exit."), QMessageBox::Cancel);}
}


void gestion_hebergements::on_pb_supprimer_2_clicked()
{
    calendrier c1;
    c1.setid(ui->le_id_sup_2->text().toInt());
        bool test=c1.supprimer(c1.getid());
        QMessageBox msgBox;
        if(test)
           { msgBox.setText("Suppression avec succes.");
            ui->tab_etudiant_2->setModel(c1.afficher());
            QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                     notifyIcon->show();
                                     notifyIcon->setIcon(QIcon("icone.png"));

                                     notifyIcon->showMessage("GESTION hebergement   ","calendrier supprimer",QSystemTrayIcon::Information,15000);
                     QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("suppression effectué.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            msgBox.setText("Echec de suppression");
        msgBox.exec();
}




void gestion_hebergements::statistiques(QString table,QString critere,int valeur1,int valeur2,QString unite)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QString valeur1QString=QString::number(valeur1);
    QString valeur2QString=QString::number(valeur2);

                model->setQuery("select * from "+table+" where "+critere+"<"+valeur1QString);

                float countFirst=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
                float countSecond=model->rowCount();
                model->setQuery("select * from "+table+" where " +critere+">"+valeur2QString);
                float countThird=model->rowCount();
                float total=countFirst+countSecond+countThird;
                QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );

                QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
                QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,countFirst);
                series->append(b,countSecond);
                series->append(c,countThird);
        if (countFirst!=0)
        {QPieSlice *slice = series->slices().at(0);
         slice->setLabelVisible();
         slice->setPen(QPen());}
        if ( countSecond!=0)
        {
                 // Add label, explode and define brush for 2nd slice
                 QPieSlice *slice1 = series->slices().at(1);
                 //slice1->setExploded();
                 slice1->setLabelVisible();
        }
       if(countThird!=0)
        {
                 // Add labels to rest of slices
                 QPieSlice *slice2 = series->slices().at(2);
                 //slice1->setExploded();
                 slice2->setLabelVisible();
        }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                if(critere=="nombre_des_chambres")
                    critere="nombre_des_chambres";
                chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();

}


void gestion_hebergements::on_par_capacite_clicked()
{
    statistiques("hebergement","nombre_des_chambres",0,10,"nombre_des_chambres");
}





void gestion_hebergements::on_table_prix_activated(const QModelIndex &index)

{
    QSqlQuery query ;
        QString val=ui->table_prix->model()->data(index).toString();
        query.prepare("SELECT * from hebergement where prix_hebergement=:prix_hebergement ");

        query.bindValue(":prix_hebergement",val);
        if(query.exec())
        {
            while(query.next())
            {

                ui->la_prix->setText(query.value(6).toString());

            }
        }
        else
        {
                QMessageBox::critical(nullptr, QObject::tr("Transferer données"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void gestion_hebergements::on_table_periode_activated(const QModelIndex &index)
{
    QSqlQuery query ;
        QString val=ui->table_periode->model()->data(index).toString();
        query.prepare("SELECT * from calendrier where periode=:periode ");

        query.bindValue(":periode",val);
        if(query.exec())
        {
            while(query.next())
            {

                ui->le_periode->setText(query.value(3).toString());

            }
        }
        else
        {
                QMessageBox::critical(nullptr, QObject::tr("Transferer données"),
                            QObject::tr("Erreur !.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


void gestion_hebergements::on_pb_reserve_clicked()
{
    {
        int chambre_reserve=ui->la_nbchambre->text().toInt();
       int periode=ui->le_periode->text().toInt();
        int prix=ui->la_prix->text().toInt();

int a=ui->la_prix->text().toInt() ;
int b=ui->la_nbchambre->text().toInt() ;
int c=ui->le_periode->text().toInt() ;
 int test2=a*b*c ;

QString test22=QString::number(test2) ;
ui->total->setText(test22) ;
        payment p(chambre_reserve,periode,prix);

    bool test=p.ajouter();
    if(test){
        QMessageBox::information(nullptr,QObject::tr("payment"),QObject::tr("payment ajouté\n" "click ok to exit"),QMessageBox::Ok);
        ui->la_nbchambre->setText("");//bech ba3ed mankamel l ajout yarja3 a 0
        ui->table_payment->setModel(p.afficher());//actualisation


        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                                 notifyIcon->show();
                                 notifyIcon->setIcon(QIcon("icone.png"));

                                 notifyIcon->showMessage("GESTION hebergement   ","payment Ajouté",QSystemTrayIcon::Information,15000);
                 QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("Ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


    }
    else{
        QMessageBox::critical(nullptr,QObject::tr("payment"),QObject::tr("Erreur!\n" "click ok to exit"),QMessageBox::Ok);
    }




    }
}


void gestion_hebergements::on_pb_supp_3_clicked()
{
    payment P1; P1.setprix(ui->prix_supp->text().toInt());
    bool test=P1.supprimer(P1.getprix());
    if (test)
    {
      QMessageBox::information(nullptr,QObject::tr("Suppression avec succes"),QObject::tr("SUCCES"),QMessageBox::Ok) ;
    }else

        QMessageBox::critical(nullptr, QObject::tr("ERREUR"),
                    QObject::tr("Echec de suppression.\n"
                        "Click Cancel to exit."), QMessageBox::Cancel);
ui->table_payment->setModel(p.afficher());
}


void gestion_hebergements::on_table_payment_activated(const QModelIndex &index)
{
    {
        QSqlQuery query ;
            QString val=ui->table_payment->model()->data(index).toString();
            query.prepare("SELECT * from payment where prix_chambre=:prix_chambre ");

            query.bindValue(":prix_chambre",val);
            if(query.exec())
            {
                while(query.next())
                {

                    ui->prix_supp->setText(query.value(2).toString());

                }
            }
            else
            {
                    QMessageBox::critical(nullptr, QObject::tr("Transferer données"),
                                QObject::tr("Erreur !.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);
            }

    }
}

