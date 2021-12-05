#include "historique.h"
#include "ui_historique.h"

historique::historique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::historique)
{
    ui->setupUi(this);
}

historique::~historique()
{
    delete ui;
}
