#ifndef GESTION_SERVICE_FINANCIER_H
#define GESTION_SERVICE_FINANCIER_H

#include <QDialog>

namespace Ui {
class gestion_service_financier;
}

class gestion_service_financier : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_service_financier(QWidget *parent = nullptr);
    ~gestion_service_financier();

private:
    Ui::gestion_service_financier *ui;
};

#endif // GESTION_SERVICE_FINANCIER_H
