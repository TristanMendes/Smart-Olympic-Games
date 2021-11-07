#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "factures.h"
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


    void on_pushButton_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonPayer_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    factures facAff;

};
#endif // MAINWINDOW_H
