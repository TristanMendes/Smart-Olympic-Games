#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "athletesop.h"

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
    void on_boutton_ajouterath_clicked();

    void on_boutton_supprimerath_clicked();

private:
    Ui::MainWindow *ui;
    athletesOP A;
};
#endif // MAINWINDOW_H
