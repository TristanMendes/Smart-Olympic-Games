#ifndef GESTION_SERVICE_FINANCIER_H
#define GESTION_SERVICE_FINANCIER_H

#include <QDialog>
#include "factures.h"

namespace Ui {
class gestion_service_financier;
}

class gestion_service_financier : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_service_financier(QWidget *parent = nullptr);
    ~gestion_service_financier();

private slots:
    void on_pushButton_clicked();

    void on_pushButtonSupprimer_clicked();

       void on_pushButtonModifier_clicked();

       void on_pushButtonPayer_clicked();


       void on_pushButton_4_clicked();
       void on_pushButtonPdf_clicked();

       void on_pushButton_2_clicked();

       void on_pushButtonPdf_2_clicked();

private:
    Ui::gestion_service_financier *ui;
    factures facAff;
};

#endif // GESTION_SERVICE_FINANCIER_H
