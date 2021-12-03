#include "factures.h"
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrinter>
#include <QPrinter>


factures::factures()
{
   this->reference = "";
   this->nbService = "";
   this->statut = "";
   this->montant = 0;
   this->dateCreation = "";
   this->dateModification = "";

}
factures::factures(QString reference,QString nbService,QString statut,float montant,QString dateCreation,QString dateModification)
{
    this->reference = reference;
    this->nbService = nbService;
    this->statut = statut;
    this->montant = montant;
    this->dateCreation = dateCreation;
    this->dateModification = dateModification;
}
QString factures::get_reference()
{
    return this->reference;
}
QString factures::get_NbServices()
{
    return this->nbService;
}
QString factures::get_Statut()
{
    return this->statut;
}
float factures::get_Montant()
{
    return this->montant;
}
QString factures::get_DateCreation()
{
    return this->dateCreation;
}
QString factures::get_DateModification()
{
    return this->dateModification;
}
bool factures::ajouterFacture()
{
    QSqlQuery query;

    QString montantstr = QString::number(montant);

    query.prepare("INSERT INTO factures(reference,date_creation,date_modification,statut,montant,nombre_service)"
            "VALUES(:reference,:date_creation,:date_modification,:statut,:montant,:nombre_service)");

    query.bindValue(":reference",reference);
    query.bindValue(":date_creation",dateCreation);
    query.bindValue(":date_modification",dateModification);
    query.bindValue(":statut",statut);
    query.bindValue(":montant",montantstr);
    query.bindValue(":nombre_service",nbService);


    return query.exec();

}

QSqlQueryModel* factures::consulterFacture()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM factures");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

QSqlQueryModel* factures::afficherFacturesNonPayee()
{
    QSqlQuery query;

    query.prepare("SELECT * FROM factures where statut= :st");
    query.bindValue(":st","Non Payee");
    query.exec();
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery(query);
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;

}
bool factures::supprimerFacture(QString ref)
{
    QSqlQuery query;

    query.prepare("DELETE from factures where reference= :ref");
    query.bindValue(":ref",ref);

    return query.exec();
}

bool factures::modifierFacture(QString reference,int montantNouv)
{
    QSqlQuery query;
    QDateTime date = QDateTime::currentDateTime();
    QString formatTime = date.toString("dd.MM.yyyy");

    QString montantstr = QString::number(montant);
    query.prepare("UPDATE factures set date_modification= :datemod,montant =:mon where reference= :ref");
    query.bindValue(":ref",reference);
 //   query.bindValue(":datecre",dateCreation);
    query.bindValue(":datemod",formatTime);
   // query.bindValue(":statut",statut);
    query.bindValue(":mon",montantNouv);
  //  query.bindValue(":nbserv",nbService);

    return query.exec();
}

bool factures::payerFactures(QString reference)
{
    QSqlQuery query;
    QString ref;

    query.prepare("UPDATE factures set statut= :stat where reference= :ref");
    query.bindValue(":ref",reference);
    query.bindValue(":stat","Payee");


    return query.exec();
}

QSqlQueryModel * factures::triReference()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES ORDER BY REFERENCE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

QSqlQueryModel * factures::triDateCreation()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES ORDER BY DATE_CREATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

QSqlQueryModel * factures::triDateModification()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES ORDER BY DATE_MODIFICATION");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

QSqlQueryModel * factures::triStatut()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query;


    query.bindValue(":statut","Payee");
    model->setQuery("SELECT * FROM FACTURES where statut= :statut");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}
QSqlQueryModel * factures::triNbServ()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES ORDER BY NOMBRE_SERVICE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

QSqlQueryModel * factures::triMontant()
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM FACTURES ORDER BY MONTANT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("date_creation"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_modification"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("montant"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("nombre_service"));

    return model;
}

void factures::creerPdf(QTableView * table)
{
    QString strstream;
    QTextStream out(&strstream);

    const int rowCount = table->model()->rowCount();
    const int columnCount = table->model()->columnCount();
    const QString titre = "Factures";

    out << "<html>\n"
           "<img src ='C:/Users/MNS/Downloads/ol-logo.png' height='120' width='120' />"
           "<head>\n"
           "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                               <<  QString("<title>%1</title>\n").arg(titre)
                               <<  "</head>\n"
                               "<body bgcolor=#ffffff link=#5000A0>\n"
                              << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des produits")
                              <<"<br>"
                    <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                                 out << "<thead><tr bgcolor=#f0f0f0>";
                                 for (int column = 0; column < columnCount; column++)
                                 if (!table->isColumnHidden(column))
                                     out << QString("<th>%1</th>").arg(table->model()->headerData(column, Qt::Horizontal).toString());
                                 out << "</tr></thead>\n";
                                 for (int row = 0; row < rowCount; row++) {
                          out << "<tr>";
                          for (int column = 0; column < columnCount; column++) {
                          if (!table->isColumnHidden(column)) {
                              QString data = table->model()->data(table->model()->index(row, column)).toString().simplified();
                              out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                          }
                          }
                          out << "</tr>\n";
                      }
                      out <<  "</table>\n"
                          "<br><br>"
                          <<"<br>"
                          <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                          out << "<thead><tr bgcolor=#f0f0f0>";

                          out <<  "</table>\n"

                          "</body>\n"
                          "</html>\n";
   QTextDocument * document = new QTextDocument();
   document->setHtml(strstream);
   QPrinter printer;
   QPrintDialog * dialog = new QPrintDialog(&printer,NULL);
   if(dialog->exec() == QDialog::Accepted)
   {
       document->print(&printer);
   }
   printer.setOutputFormat(QPrinter::PdfFormat);
   printer.setPaperSize(QPrinter::A4);
   printer.setOutputFileName("C:/Users/MNNS/Downloads/olympic.pdf");
   printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                   delete document;

}
