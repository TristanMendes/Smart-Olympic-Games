#include "dialog.h"
#include "ui_dialog.h"
#include "athletes.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_ajouter_clicked()
{
    int ID=ui->lineEdit_ID_ajout->text().toInt();
    int age=ui->lineEdit_age_ajout->text().toInt();
    QString Nom=ui->lineEdit_Nom_ajout->text();
    QString Prenom=ui->lineEdit_prenom_ajout->text();
    QString nationalite=ui->lineEdit_specialite_modifier->text();
    QString sexe=ui->comboBox_sexe_ajout

    Athletes A()
}
