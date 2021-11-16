#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "examen_medical.h"
#include "smtp.h"
#include "qcustomplot.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QTableWidget>
#include <vector>
#include <QPrinter>
#include <QPrinterInfo>
#include <QPrintDialog>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
//#include <strstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{ui->setupUi(this);
ui->le_id->setValidator(new QIntValidator(0,99999999,this));
ui->le_id_supp->setValidator(new QIntValidator(0,99999999,this));
ui->le_id_modif->setValidator(new QIntValidator(0,99999999,this));
ui->le_id_recherche->setValidator(new QIntValidator(0,99999999,this));
ui->le_id_antecedants->setValidator(new QIntValidator(0,99999999,this));
ui->le_id_resultats->setValidator(new QIntValidator(0,99999999,this));
ui->tab_examens->setModel(e.afficher());
ui->tab_antecedants->setModel(ea.afficher_antecedants());
//ui->tab_resultats->setModel(e_resultats.afficher_resultats());

//statistiques par nom d'examens

QBarSet *set0 = new QBarSet("malade");
QBarSet *set1 = new QBarSet("sain");
*set0 <<5<<4<<2;
*set1 <<5<<6<<8;

QBarSeries *series_nom = new QBarSeries();
series_nom->append(set0);
series_nom->append(set1);

QChart *chart_nom = new QChart();
chart_nom->addSeries(series_nom);
chart_nom->setTitle("nombre de malades et de sains par examens");

chart_nom->setAnimationOptions(QChart::SeriesAnimations);

QStringList categories_nom;

categories_nom <<"NFS"<<"PCR"<<"ECG";
QBarCategoryAxis *axis_nom = new QBarCategoryAxis();
axis_nom->append(categories_nom);
chart_nom->createDefaultAxes();
chart_nom->setAxisX(axis_nom,series_nom);

QChartView *chartView_nom = new QChartView(chart_nom);
chartView_nom->setParent(ui->gridFrame_stat);

//statistiques par type

QBarSet *set3 = new QBarSet("malade");
QBarSet *set4 = new QBarSet("sain");
QBarSet *set5 = new QBarSet("patients au total");
*set3 <<5<<4<<2;
*set4 <<2<<3<<4;
*set5 <<7<<7<<6;

QBarSeries *series_type = new QBarSeries();
series_type->append(set3);
series_type->append(set4);
series_type->append(set5);

QChart *chart_type = new QChart();
chart_type->addSeries(series_type);
chart_type->setTitle("nombre de malades, de sains et de patients par examens");

chart_type->setAnimationOptions(QChart::SeriesAnimations);

QStringList categories_type;

categories_type <<"Sanguin"<<"Nazal"<<"Echgraphique";
QBarCategoryAxis *axis_type = new QBarCategoryAxis();
axis_type->append(categories_type);
chart_type->createDefaultAxes();
chart_type->setAxisX(axis_type,series_type);

QChartView *chartView_type = new QChartView(chart_type);
chartView_type->setParent(ui->stat2);

//statistiques par etat

QBarSet *set6 = new QBarSet("NFS");
QBarSet *set7 = new QBarSet("PCR");
QBarSet *set8 = new QBarSet("ECG");
*set6 <<5<<2;
*set7 <<4<<3;
*set8 <<2<<4;

QBarSeries *series_etat = new QBarSeries();
series_etat->append(set6);
series_etat->append(set7);
series_etat->append(set8);

QChart *chart_etat = new QChart();
chart_etat->addSeries(series_etat);
chart_etat->setTitle("nombre d'examens de chaque type par etat de sante");

chart_etat->setAnimationOptions(QChart::SeriesAnimations);

QStringList categories_etat;

categories_etat <<"Malades"<<"Sains";
QBarCategoryAxis *axis_etat = new QBarCategoryAxis();
axis_etat->append(categories_etat);
chart_etat->createDefaultAxes();
chart_etat->setAxisX(axis_etat,series_etat);

QChartView *chartView_etat = new QChartView(chart_etat);
chartView_etat->setParent(ui->stat3);}






MainWindow::~MainWindow()
{delete ui;}





void MainWindow::on_pb_ajouter_clicked()
{int id=ui->le_id->text().toInt();
QString nom=ui->le_nom->text();
QString type=ui->le_type->text();
int tranche_age=ui->le_age->text().toInt();
QString etat_sante=ui->le_etat->text();
QString coordonnees_athletes=ui->le_coordonnees->text();

examen_medical e(id,nom,type,tranche_age,etat_sante,coordonnees_athletes);

bool test = e.ajouter_examen();
if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."), QMessageBox::Cancel);
ui->tab_examens->setModel(e.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}



void MainWindow::on_pb_annuler_ajout_clicked()
{ui->le_id->clear();
ui->le_nom->clear();
ui->le_type->clear();
ui->le_age->clear();
ui->le_etat->clear();
ui->le_coordonnees->clear();}



void MainWindow::on_pb_supprimer_clicked()
{ int id= ui->le_id_supp->text().toInt();
bool test=e1.supprimer_examen(id);

if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);
ui->tab_examens->setModel(e1.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"), QObject::tr("Suppression non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}



void MainWindow::on_pb_annuler_supp_clicked()
{ui->le_id_supp->clear();}




void MainWindow::on_pb_modif_clicked()
{int id = ui->le_id_modif->text().toInt();
QString nom=ui->le_nom_modif->text();
QString type=ui->le_type_modif->text();
int tranche_age=ui->le_age_modif->text().toInt();
QString etat_sante=ui->le_etat_modif->text();
QString coordonnees_athletes=ui->le_coordonnees_modif->text();
bool test=e2.modifier_examen(id, nom, type, tranche_age, etat_sante, coordonnees_athletes);

if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Modification effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);
ui->tab_examens->setModel(e2.afficher());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Modification non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}



void MainWindow::on_pb_annuler_modif_clicked()
{ui->le_id_modif->clear();
ui->le_nom_modif->clear();
ui->le_type_modif->clear();
ui->le_age_modif->clear();
ui->le_etat_modif->clear();
ui->le_coordonnees_modif->clear();}





void MainWindow::on_recherche_id_clicked()
{QString q=ui->le_id_recherche->text();
QSqlQueryModel * test=er.chercher_id(q);
if(test)
{ ui->tab_recherche_tri->setModel(er.chercher_id(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}





void MainWindow::on_recherche_nom_clicked()
{QString q=ui->le_nom_recherche->text();
QSqlQueryModel * test=er.chercher_nom(q);
if(test)
{ui->tab_recherche_tri->setModel(er.chercher_nom(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}






void MainWindow::on_recherche_type_clicked()
{QString q=ui->le_type_recherche->text();
QSqlQueryModel * test=er.chercher_type(q);
if(test)
{ui->tab_recherche_tri->setModel(er.chercher_type(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_recherche_age_clicked()
{QString q=ui->le_age_recherche->text();
QSqlQueryModel * test=er.chercher_age(q);
if(test)
{ui->tab_recherche_tri->setModel(er.chercher_age(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_recherche_etat_clicked()
{QString q=ui->le_etat_recherche->text();
QSqlQueryModel * test=er.chercher_etat(q);
if(test)
{ui->tab_recherche_tri->setModel(er.chercher_etat(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}



void MainWindow::on_recherche_coordonnees_clicked()
{QString q=ui->le_coordonnees_recherche->text();
QSqlQueryModel * test=er.chercher_coordonnees(q);
if(test)
{ui->tab_recherche_tri->setModel(er.chercher_coordonnees(q));
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Recherche effectuée\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Recherche non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_pb_annuler_recherche_clicked()
{ui->le_id_recherche->clear();
ui->le_nom_recherche->clear();
ui->le_type_recherche->clear();
ui->le_age_recherche->clear();
ui->le_etat_recherche->clear();
ui->le_coordonnees_recherche->clear();}




void MainWindow::on_tri_id_clicked()
{QSqlQueryModel * test = et.tri_id();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_id());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}


void MainWindow::on_tri_nom_clicked()
{QSqlQueryModel * test=et.tri_nom();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_nom());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}


void MainWindow::on_tri_type_clicked()
{QSqlQueryModel * test=et.tri_type();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_type());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}


void MainWindow::on_tri_age_clicked()
{QSqlQueryModel * test=et.tri_age();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_age());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_tri_etat_clicked()
{QSqlQueryModel * test=et.tri_etat();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_etat());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_tri_coordonnees_clicked()
{QSqlQueryModel * test=et.tri_coordonnees();
if(test)
{ui->tab_recherche_tri->setModel(et.tri_coordonnees());
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Tri effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Tri non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}





void MainWindow::on_pb_ajouter_antecedants_clicked()
{int id=ui->le_id_antecedants->text().toInt();
QString maladies_cardio=ui->choix_cardio->currentText();
QString maladies_resp=ui->choix_resp->currentText();
QString autres=ui->choix_autres->currentText();
QString blessures=ui->choix_blessures->currentText();
bool test = ea.ajouter_antecedants(id, maladies_cardio, maladies_resp, autres, blessures);
ui->tab_antecedants->setModel(ea.afficher_antecedants());
if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Ajout effectué\n" "Click Cancel to exit."),QMessageBox::Cancel);
ui->tab_antecedants->setModel(ea.afficher_antecedants());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Ajout non effectué.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_pb_supprimer_antecedants_clicked()
{int id= ui->le_id_antecedants->text().toInt();
bool test=e1.supprimer_antecedants(id);
ui->tab_antecedants->setModel(ea.afficher_antecedants());
if(test)
{QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Suppression effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);
ui->tab_antecedants->setModel(ea.afficher_antecedants());}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Suppression non effectuée.\n" "Click Cancel to exit."),QMessageBox::Cancel);}



void MainWindow::on_pb_annuler_antecedants_clicked()
{ui->le_id_antecedants->clear();}



void MainWindow::on_pb_pdf_clicked()
{QTableView *table;
table=ui->tab_antecedants;
QString strStream;
QTextStream out(&strStream);
const int rowCount = table->model()->rowCount();
const int columnCount = table->model()->columnCount();
const QString strTitle ="Document";
out <<  "<html>\n"
"<img src='C:/Users/ASUS/Documents/kiosqueK/logocin.png' height='120' width='120'/>"
"<head>\n"
"<meta Content=\"Text/html; charset=Windows-1251\">\n"
<<  QString("<title>%1</title>\n").arg(strTitle)
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
for (int row = 0; row < rowCount; row++)
{out << "<tr>";
for (int column = 0; column < columnCount; column++)
{if (!table->isColumnHidden(column))
{QString data = table->model()->data(table->model()->index(row, column)).toString().simplified();
out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));} }
out << "</tr>\n";}
out <<  "</table>\n"
"<br><br>"
<<"<br>"
<<"<table border=1 cellspacing=0 cellpadding=2>\n";
out << "<thead><tr bgcolor=#f0f0f0>";
out <<  "</table>\n"
"</body>\n"
"</html>\n";
QTextDocument *document = new QTextDocument();
document->setHtml(strStream);
QPrinter printer;
QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
if (dialog->exec() == QDialog::Accepted)
{document->print(&printer);}
printer.setOutputFormat(QPrinter::PdfFormat);
printer.setPaperSize(QPrinter::A4);
printer.setOutputFileName("/tmp/produit.pdf");
printer.setPageMargins(QMarginsF(15, 15, 15, 15));
delete document;}


void MainWindow::on_pb_excel_clicked()
{QTableView *table;
table = ui->tab_antecedants;
QString filters("CSV files (.csv);;All files (.*)");
QString defaultFilter("CSV files (*.csv)");
QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),filters, &defaultFilter);
QFile file(fileName);
QAbstractItemModel *model =  table->model();

if (file.open(QFile::WriteOnly | QFile::Truncate))
{QTextStream data(&file);
QStringList strList;
for (int i = 0; i < model->columnCount(); i++)
{if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
else strList.append("");}
data << strList.join(";") << "\n";
for (int i = 0; i < model->rowCount(); i++)
{strList.clear();
for (int j = 0; j < model->columnCount(); j++)
{if (model->data(model->index(i, j)).toString().length() > 0)
strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
else strList.append("");}
data << strList.join(";") + "\n";}
file.close();
QMessageBox::information(nullptr, QObject::tr("Export excel"),QObject::tr("Export avec succes .\n" "Click OK to exit."),QMessageBox::Ok);}}





void MainWindow::on_pb_resultat_clicked()
{QString q=ui->le_id_resultats->text();
QSqlQueryModel * test=er.chercher_id(q);
ui->tab_resultats->setModel(e_resultats.afficher());

if(test)
{ui->tab_resultats->setModel(e_resultats.chercher_resultats(q));
QString resultat=ui->tab_resultats->model()->index(0,2).data().toString();

QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("Résultat trouvé.\n" "Click Cancel to exit."),QMessageBox::Cancel);
if (resultat=="sain")
QMessageBox::information(nullptr,QObject::tr("Recommandations"),QObject::tr("Vous êtes en bonne santé.\n" "Prenez soin de  vous.\n" "Pour maintenir une bonne santé, un contrôle est recommandé chaque 6 mois à un an.\n"),QMessageBox::Cancel);
else QMessageBox::information(nullptr,QObject::tr("Alertes"),QObject::tr("Vous êtes malade.\n" "Consultez un médecin le plus tôt possible afin de suivre un traitement précis préscrit pour vous.\n" "En cas de maladie contagieuse, il est important de respecter le protocole sanitaire imposé par le médecin.\n" "Ceci dit le port de la bavette et le confinement total dans votre chambre,.." ),QMessageBox::Cancel);}
else QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject::tr("Résultat introuvable.\n" "Click Cancel to exit."),QMessageBox::Cancel);}




void MainWindow::on_pb_annuler_resultat_clicked()
{ui->le_id_resultats->clear();}




void MainWindow::on_sendMail_clicked()
{QString mail=ui->from->text();
QString password=ui->paswd->text();
QString recpt=ui->to->text();
QString objet=ui->subject->text();
QString description=ui->msg->toPlainText();
Smtp *smtp = new Smtp(mail,password,"smtp.gmail.com");
smtp->sendMail(mail,recpt ,objet,description);}




void MainWindow::mailsent(QString status)
{if(status == "Message sent")
QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
ui->to->clear();
ui->subject->clear();
ui->msg->clear();
ui->paswd->clear();
ui->from->clear();}






void MainWindow::on_b_statv_clicked()
{//ui->stat->setCurrentIndex(8);
QLinearGradient gradient(0, 0, 0, 400);
gradient.setColorAt(0, QColor(90, 90, 90));
gradient.setColorAt(0.38, QColor(105, 105, 105));
gradient.setColorAt(1, QColor(70, 70, 70));
ui->customPlot->setBackground(QBrush(gradient));
// create empty bar chart objects:
QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
regen->setAntialiased(false);  // gives more crisp, pixel aligned bar borders
nuclear->setAntialiased(false);
regen->setStackingGap(1);
nuclear->setStackingGap(1);
// set names and colors:
regen->setName("nombre de malades");
regen->setPen(QPen(QColor(111, 9, 176).lighter(170)));
regen->setBrush(QColor(111, 9, 176));
nuclear->setName("nombre de sains");
nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
nuclear->setBrush(QColor(250, 170, 20));
regen->setBrush(QColor(0, 168, 140));
// stack bars on top of each other:
regen->moveAbove(nuclear);
// prepare x axis with  labels:
QVector<double> ticks;
QVector<QString> labels;
int i=0;
QSqlQuery q;
q.exec("select nom from examens_medicaux");
while (q.next())
{QString nom=q.value(0).toString();
i++;
ticks<<i;
labels<<nom;
qDebug()<<"nom"<<nom<<endl;}
QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
textTicker->addTicks(ticks, labels);
ui->customPlot->xAxis->setTicker(textTicker);
ui->customPlot->xAxis->setTickLabelRotation(60);
ui->customPlot->xAxis->setSubTicks(false);
ui->customPlot->xAxis->setTickLength(0, 20);
ui->customPlot->xAxis->setRange(0, 20);
ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
ui->customPlot->xAxis->grid()->setVisible(true);
ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
ui->customPlot->xAxis->setTickLabelColor(Qt::white);
ui->customPlot->xAxis->setLabelColor(Qt::white);

// prepare y axis:
ui->customPlot->yAxis->setRange(0, 50);
ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
ui->customPlot->yAxis->setLabel("nbr de reparation et locations par voiture");
ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
ui->customPlot->yAxis->grid()->setSubGridVisible(true);
ui->customPlot->yAxis->setTickLabelColor(Qt::white);
ui->customPlot->yAxis->setLabelColor(Qt::white);
ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
// Add data:
QVector<double> nuclearData, regenData;
int j=0;int nb_malades=0;
QSqlQuery q2, q1;
q2.exec("select etat_sante from examens_medicaux");
while (q2.next())
{QString etat_sante=q2.value(0).toString();
if (etat_sante == "malade")
{ nb_malades++;
qDebug()<<"malades"<<nb_malades<<endl;
j++;
regenData <<nb_malades;}}
int v=0;int nb_sains=0;
q1.exec("select etat_sante from examens_medicaux");
while (q1.next())
{QString etat_sante=q1.value(0).toString();
if (etat_sante == "sain")
{ nb_sains++;
qDebug()<<"sains"<<nb_sains<<endl;
v++;
nuclearData <<nb_sains;}}
nuclear->setData(ticks, nuclearData);
regen->setData(ticks, regenData);
// setup legend:
ui->customPlot->legend->setVisible(true);
ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
ui->customPlot->legend->setBorderPen(Qt::NoPen);
QFont legendFont = font();
legendFont.setPointSize(10);
ui->customPlot->legend->setFont(legendFont);
ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);}






void MainWindow::on_tabWidget_6_currentChanged(int index)
{ // background //
QLinearGradient gradient(0, 0, 0, 400);
gradient.setColorAt(0, QColor(90, 90, 90));
gradient.setColorAt(0.38, QColor(105, 105, 105));
gradient.setColorAt(1, QColor(70, 70, 70));
ui->plot->setBackground(QBrush(gradient));
QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
amande->setAntialiased(false);
amande->setStackingGap(1);
//couleurs
amande->setName("Les etats de santé en fonction le nom de l'examens ");
amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
amande->setBrush(QColor(0, 168, 140));
//axe des abscisses
QVector<double> ticks;
QVector<QString> labels;
es.statistique(&ticks,&labels);
QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
textTicker->addTicks(ticks, labels);
ui->plot->xAxis->setTicker(textTicker);
ui->plot->xAxis->setTickLabelRotation(60);
ui->plot->xAxis->setSubTicks(false);
ui->plot->xAxis->setTickLength(0, 4);
ui->plot->xAxis->setRange(0, 8);
ui->plot->xAxis->setBasePen(QPen(Qt::white));
ui->plot->xAxis->setTickPen(QPen(Qt::white));
ui->plot->xAxis->grid()->setVisible(true);
ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
ui->plot->xAxis->setTickLabelColor(Qt::white);
ui->plot->xAxis->setLabelColor(Qt::white);
// axe des ordonnées
ui->plot->yAxis->setRange(0,10);
ui->plot->yAxis->setPadding(5);
ui->plot->yAxis->setLabel("Statistiques");
ui->plot->yAxis->setBasePen(QPen(Qt::white));
ui->plot->yAxis->setTickPen(QPen(Qt::white));
ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
ui->plot->yAxis->grid()->setSubGridVisible(true);
ui->plot->yAxis->setTickLabelColor(Qt::white);
ui->plot->yAxis->setLabelColor(Qt::white);
ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
// ajout des données  (statistiques de la quantité)//
/*QVector<double> nuclearData;
QVector<double> regenData;
int j=0;int nb_malades=0;
QSqlQuery q2, q1;
q2.exec("select etat_sante from examens_medicaux");
while (q2.next())
{QString etat_sante=q2.value(0).toString();
if (etat_sante == "malade")
{ nb_malades++;
qDebug()<<"malades"<<nb_malades<<endl;
j++;
regenData <<nb_malades;}}
int v=0;int nb_sains=0;
q1.exec("select etat_sante from examens_medicaux");
while (q1.next())
{QString etat_sante=q1.value(0).toString();
if (etat_sante == "sain")
{ nb_sains++;
qDebug()<<"sains"<<nb_sains<<endl;
v++;
nuclearData <<nb_sains;}}
amande->setData(ticks, nuclearData);
amande->setData(ticks, regenData);*/
QVector<double> PlaceData;
int nb_patients=0;
QSqlQuery q1("select etat_sante from examens_medicaux");
while (q1.next())
{QString etat_sante = q1.value(0).toString();
nb_patients++;
PlaceData<< nb_patients;}
amande->setData(ticks, PlaceData);
ui->plot->legend->setVisible(true);
ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
ui->plot->legend->setBrush(QColor(0, 168, 140));
ui->plot->legend->setBorderPen(Qt::NoPen);
QFont legendFont = font();
legendFont.setPointSize(5);
ui->plot->legend->setFont(legendFont);
ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);}






void MainWindow::on_stat_examen_clicked()
{QString critere=ui->choix_stat->currentText();
if(critere=="nom")
 es.statistiques("examens_medicaux",critere,0,100,"nom");
else if(critere=="type")
es.statistiques("examens_medicaux",critere,0,100,"");}






void MainWindow::on_pb_stat_clicked()
{QString critere;
critere = ui->choix_stat->currentText();
if(critere=="nom")
{QBarSet *set0 = new QBarSet("malade");
QBarSet *set1 = new QBarSet("sain");
*set0 <<5<<4<<2;
*set1 <<2<<3<<4;

QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);

QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("nombre de malades et de sains par nom d'examens");

chart->setAnimationOptions(QChart::SeriesAnimations);


QStringList categories;

categories <<"NFS"<<"PCR"<<"ECG";
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis,series);

QChartView *chartView = new QChartView(chart);
chartView->setParent(ui->stat2);}

else if(critere=="type")
{QBarSet *set0 = new QBarSet("malade");
QBarSet *set1 = new QBarSet("sain");
QBarSet *set2 = new QBarSet("patients au total");
*set0 <<5<<4<<2;
*set1 <<2<<3<<4;
*set2 <<7<<7<<6;

QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);
series->append(set2);

QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("nombre de malades, de sains et de patients par examens");
chart->setAnimationOptions(QChart::SeriesAnimations);

QStringList categories;

categories <<"Sanguin"<<"Nazal"<<"Echgraphique";
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis,series);

QChartView *chartView = new QChartView(chart);
chartView->setParent(ui->stat2);}

else if (critere=="etat")
{QBarSet *set0 = new QBarSet("NFS");
QBarSet *set1 = new QBarSet("PCR");
QBarSet *set2 = new QBarSet("ECG");
*set0 <<5<<2;
*set1 <<4<<3;
*set2 <<2<<4;

QBarSeries *series = new QBarSeries();
series->append(set0);
series->append(set1);
series->append(set2);

QChart *chart = new QChart();
chart->addSeries(series);
chart->setTitle("nombre d'examens de chaque type par etat de sante");

chart->setAnimationOptions(QChart::SeriesAnimations);

QStringList categories;

categories <<"Malades"<<"Sains";
QBarCategoryAxis *axis = new QBarCategoryAxis();
axis->append(categories);
chart->createDefaultAxes();
chart->setAxisX(axis,series);

QChartView *chartView = new QChartView(chart);
chartView->setParent(ui->stat2); }}









