#include "stade.h"

Stade::Stade()
{
id=0; capacite=0; nbre_evenement=0 ; nom=""; adresse="";specialite="";dimension=0.0f ;
}

 Stade::Stade(int id,int capacite,int nbre_evenement,float dimension,QString nom,QString adresse,QString specialite)
 {this->id=id; this->capacite=capacite; this->nbre_evenement=nbre_evenement ; this->dimension=dimension ; this->nom=nom ; this->adresse=adresse; this->specialite=specialite;}
 int Stade::getid() {return id ;}
 int Stade::getcapacite() {return capacite ;}
 int Stade::getnbre_evenement() {return nbre_evenement ;}
 float Stade::getdimension() {return dimension ;}
 QString Stade::getnom() {return nom ;}
 QString Stade::getadresse() {return adresse ;}
 QString Stade::getspecialite() {return specialite;}
 void Stade::setid(int id) {this->id=id;}
 void Stade::setcapacite(int capacite) {this->capacite=capacite;}
 void Stade::setnbre_evenement(int nbre_evenement) {this->nbre_evenement=nbre_evenement;}
 void Stade::setdimension(float dimension) {this->dimension=dimension;}
 void Stade::setnom(QString nom) {this->nom=nom;}
 void Stade::setadresse(QString adresse) {this->adresse=adresse;}
 void Stade::setspecialite(QString specialite) {this->specialite=specialite;}
