#include "gestion_service_financier.h"
#include "ui_gestion_service_financier.h"

gestion_service_financier::gestion_service_financier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_service_financier)
{
    ui->setupUi(this);
}

gestion_service_financier::~gestion_service_financier()
{
    delete ui;
}
