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

    void on_pushButton_Modifierath_clicked();

    void on_table_athletes_2_activated(const QModelIndex &index);

    void on_bouton_rechercherath_clicked();


    void on_comboBox_trierath_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    athletesOP A;

};
#endif // MAINWINDOW_H
