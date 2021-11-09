#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "stade.h"
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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_rechercher_stade_clicked();

    void on_cb_tri_currentIndexChanged(int index);

    void on_pb_annuler_clicked();

private:
    Ui::MainWindow *ui;
    Stade S ;//ajout d'un attribut à la classe mainwindow.h qui correspond à un objet de la classe stade pour pouvoir faire appel à la methode supprimer()

};
#endif // MAINWINDOW_H
