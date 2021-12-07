#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_gestion_examens_medicaux_clicked();
    void on_pb_gestion_moyens_transport_clicked();
    void on_gestion_athletes_clicked();
    void on_gestion_factures_clicked();

    void on_gestion_stades_clicked();

    void on_gestion_hebergements_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

