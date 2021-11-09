#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <hebergement.h>
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_annuler_clicked();

    void on_pb_rechercher_clicked();

    //void on_pushButton_7_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pb_annuler_2_clicked();

private:
    Ui::MainWindow *ui;
    Hebergement H;
};
#endif // MAINWINDOW_H
