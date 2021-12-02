#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "athletesop.h"
#include <QSystemTrayIcon>
#include <QDialog>
#include <QFile>
#include<QTextStream>
#include <arduino.h>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


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


    void on_bouton_PDF_clicked();



    void on_bouton_excel_clicked();

    void on_bouton_URL_clicked();

    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino




private:
    Ui::MainWindow *ui;
    athletesOP A;


    QByteArray data; // variable contenant les données reçues

    Arduino a; // objet temporaire

};
#endif // MAINWINDOW_H
