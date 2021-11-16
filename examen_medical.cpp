#include "examen_medical.h"
#include <QSqlQuery>
#include<QtDebug>
#include<QObject>
//stat
#include <iostream>
using namespace std;
#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
QT_CHARTS_USE_NAMESPACE



examen_medical::examen_medical()
{id=0; nom=" "; type=" "; tranche_age=0; etat_sante=" "; coordonnees_athletes=" ";}


examen_medical::examen_medical(int id, QString nom, QString type, int tranche_age, QString etat_sante, QString coordonnees_athletes)
{this->id=id; this->nom=nom; this->type=type; this->tranche_age=tranche_age; this->etat_sante=etat_sante;
this->coordonnees_athletes=coordonnees_athletes;}


int examen_medical::getid() {return id;}
QString examen_medical::getnom(){return nom;}
QString examen_medical::gettype() {return type;}
int examen_medical::gettranche_age() {return tranche_age;}
QString examen_medical::getetat_sante() {return etat_sante;}
QString examen_medical::getcoordonnees_athletes() {return coordonnees_athletes;}
void examen_medical::setid(int id){this->id=id;}
void examen_medical::setnom(QString nom){this->nom=nom;}
void examen_medical::settype(QString type){this->type=type;}
void examen_medical::settranche_age(int tranche_age){this->tranche_age=tranche_age;}
void examen_medical::setetat_sante(QString etat_sante){this->etat_sante=etat_sante;}
void examen_medical::setcoordonnees_athletes(QString coordonnees_athletes){this->coordonnees_athletes=coordonnees_athletes;}


bool examen_medical::ajouter_examen()
{QSqlQuery query;
QString id_string = QString::number(id);
QString tranche_age_string = QString::number(tranche_age);

query.prepare("INSERT INTO examens_medicaux (id, nom, type, tranche_age, etat_sante, coordonnees_athletes) "
"VALUES (:id, :nom, :type, :tranche_age, :etat_sante, :coordonnees_athletes)");
query.bindValue(":id", id_string);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":tranche_age", tranche_age_string);
query.bindValue(":etat_sante", etat_sante);
query.bindValue(":coordonnees_athletes", coordonnees_athletes);
return query.exec();}


bool examen_medical::supprimer_examen(int id)
{QSqlQuery query;
QString id_string = QString::number(id);
query.prepare("Delete FROM examens_medicaux where id=:id");
query.bindValue(0, id);
return query.exec();}




QSqlQueryModel * examen_medical::afficher()
{QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT* FROM examens_medicaux");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'examen"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type d'examen "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Tranche d'age"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Etat de santé"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Coordonnées des athlétes"));
return model;}


bool examen_medical::modifier_examen(int id, QString nom, QString type, int tranche_age, QString etat_sante, QString coordonnees_athletes)
{QSqlQuery query;
QString id_string = QString::number(id);
QString age_string = QString::number(tranche_age);

query.prepare("UPDATE examens_medicaux SET id=:id, nom=:nom, type=:type, tranche_age=:tranche_age, etat_sante=:etat_sante, coordonnees_athletes=:coordonnees_athletes WHERE id=:id");
query.bindValue(":id",id_string);
query.bindValue(":nom",nom);
query.bindValue(":type",type);
query.bindValue(":tranche_age",age_string);
query.bindValue(":etat_sante",etat_sante);
query.bindValue(":coordonnees_athletes",coordonnees_athletes);
return query.exec();}

QSqlQueryModel * examen_medical::chercher_id(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where id='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::chercher_nom(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where nom='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model; }


QSqlQueryModel * examen_medical::chercher_type(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where type='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model; }


QSqlQueryModel * examen_medical::chercher_age(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where tranche_age='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::chercher_etat(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where etat_sante='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model; }


QSqlQueryModel * examen_medical::chercher_coordonnees(QString q)
{QSqlQuery query ;
query.prepare("select * from examens_medicaux where coordonnees_athletes='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model; }



QSqlQueryModel * examen_medical::tri_id()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY id");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::tri_nom()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY nom");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::tri_type()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY type");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::tri_age()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY tranche_age");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::tri_etat()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY etat_sante");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}


QSqlQueryModel * examen_medical::tri_coordonnees()
{QSqlQuery query ;
query.prepare("select * from examens_medicaux ORDER BY coordonnees_athletes");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}




bool examen_medical::ajouter_antecedants(int id, QString maladies_cardio, QString maladies_resp, QString autres, QString blessures)
{QSqlQuery query;
QString id_string = QString::number(id);
query.prepare("INSERT INTO antecedants_medicaux (id, maladies_cardio, maladies_resp, autres, blessures) "
"VALUES (:id, :maladies_cardio, :maladies_resp, :autres, :blessures)");
query.bindValue(":id", id_string);
query.bindValue(":maladies_cardio",maladies_cardio);
query.bindValue(":maladies_resp", maladies_resp);
query.bindValue(":autres", autres);
query.bindValue(":blessures", blessures);
return query.exec();}


bool examen_medical::supprimer_antecedants(int id)
{QSqlQuery query;
QString id_string = QString::number(id);
query.prepare("Delete FROM antecedants_medicaux where id=:id");
query.bindValue(0, id);
return query.exec();}




QSqlQueryModel * examen_medical::afficher_antecedants()
{QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT* FROM antecedants_medicaux");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("maladies cardiovasculaires"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("maladies repiratoires"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Autres"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Blessures"));
return model;}



/*QSqlQueryModel * examen_medical::afficher_resultats()
{QSqlQueryModel * model = new QSqlQueryModel();
model->setQuery("SELECT id, nom, etat_sante from examens_medicaux");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom de l'examen"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Resultat de l'examen"));
return model;}*/




QSqlQueryModel* examen_medical::chercher_resultats(QString q)
{QSqlQuery query ;
query.prepare("select id, nom, etat_sante from examens_medicaux where id='"+q+"'");
query.exec();
QSqlQueryModel *model=new QSqlQueryModel ;
model->setQuery(query);
return model;}

void examen_medical::statistique(QVector<double>* ticks,QVector<QString> *labels)
{QSqlQuery q;
int i=0;
q.exec("select nom from examens_medicaux");
while (q.next())
{QString nom = q.value(0).toString();
i++;
*ticks<<i;
*labels <<nom; }}


void examen_medical::statistiques(QString table,QString critere,int valeur1,int valeur2,QString unite)
{QSqlQueryModel * model= new QSqlQueryModel();
QString valeur1QString=QString::number(valeur1);
QString valeur2QString=QString::number(valeur2);

model->setQuery("select * from "+table+" where "+critere+"=="+valeur1QString);
float countFirst=model->rowCount();
//model->setQuery("select * from "+table+" where " +critere+" between " +valeur1QString+ " and "+valeur2QString);
//float countSecond=model->rowCount();
model->setQuery("select * from "+table+" where " +critere+"=="+valeur2QString);
float countThird=model->rowCount();
//float total=countFirst+countSecond+countThird;
float total=countFirst+countThird;
QString a=QString("moins de "+valeur1QString+" "+unite+" "+QString::number((countFirst*100)/total,'f',2)+"%" );
//QString b=QString("entre "+valeur1QString+ " et " +valeur2QString+" "+unite+" "+QString::number((countSecond*100)/total,'f',2)+"%" );
QString c=QString("Plus que "+valeur2QString +" "+unite+" "+QString::number((countThird*100)/total,'f',2)+"%" );
QPieSeries *series = new QPieSeries();
series->append(a,countFirst);
//series->append(b,countSecond);
series->append(c,countThird);
if (countFirst!=0)
{QPieSlice *slice = series->slices().at(0);
slice->setLabelVisible();
slice->setPen(QPen());}
/*if ( countSecond!=0)
{ // Add label, explode and define brush for 2nd slice
QPieSlice *slice1 = series->slices().at(1);
//slice1->setExploded();
slice1->setLabelVisible();}*/
if(countThird!=0)
{ // Add labels to rest of slices
QPieSlice *slice2 = series->slices().at(2);
//slice1->setExploded();
slice2->setLabelVisible();}
// Create the chart widget
QChart *chart = new QChart();
// Add data to chart with title and hide legend
chart->addSeries(series);
/*if(critere=="CAPACITE_STADE")
critere="Capacite";
chart->setTitle("Pourcentage Par " +critere+":Nombre Des " +table+" :" +QString::number(total));
chart->legend()->hide();
// Used to display the chart
QChartView *chartView = new QChartView(chart);
chartView->setRenderHint(QPainter::Antialiasing);
 chartView->resize(1000,500);
chartView->show();*/

}

