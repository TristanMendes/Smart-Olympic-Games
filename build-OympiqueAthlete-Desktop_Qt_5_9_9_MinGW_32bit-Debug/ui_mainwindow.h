/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab_9;
    QGroupBox *groupBox;
    QLineEdit *lineEdit_motdepass;
    QLineEdit *lineEdit_nomutilisateur;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_7;
    QWidget *tab_10;
    QTabWidget *tabWidget_2;
    QWidget *tab_11;
    QLineEdit *lineEdit_ID_3;
    QLineEdit *lineEdit_Nom_3;
    QLineEdit *lineEdit_Prenom_3;
    QLineEdit *lineEdit_Age_3;
    QLineEdit *lineEdit_nationalite_3;
    QLineEdit *lineEdit_specialite_3;
    QLineEdit *lineEdit_mail_3;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QComboBox *comboBox_sexe_3;
    QPushButton *boutton_ajouterath;
    QLabel *label_5;
    QPushButton *pushButton_Modifierath;
    QLabel *label_nom_test;
    QLabel *label_prenom_test;
    QWidget *tab_12;
    QGroupBox *groupBox_2;
    QLabel *label_42;
    QLineEdit *lineEdit_supprimerath;
    QPushButton *boutton_supprimerath;
    QComboBox *comboBox_trierath;
    QLabel *label_32;
    QTableView *table_athletes_2;
    QLineEdit *lineEdit_rechercher;
    QPushButton *bouton_rechercherath;
    QLabel *label_6;
    QWidget *tab_13;
    QLineEdit *lineEdit_ID_mo;
    QLabel *label_34;
    QLabel *label_35;
    QLineEdit *lineEdit_Nom_mo;
    QLabel *label_36;
    QLineEdit *lineEdit_Prenom_mo;
    QLineEdit *lineEdit_Age_mo;
    QLabel *label_37;
    QLineEdit *lineEdit_nationalite_4;
    QLabel *label_38;
    QComboBox *comboBox_sexe_4;
    QLabel *label_39;
    QLabel *label_40;
    QLineEdit *lineEdit_specialite_4;
    QLineEdit *lineEdit_mail_4;
    QLabel *label_41;
    QWidget *tab_14;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 781, 521));
        tabWidget->setStyleSheet(QStringLiteral("font: 63 italic 12pt \"Lucida Fax\";"));
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        groupBox = new QGroupBox(tab_9);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 681, 311));
        QFont font;
        font.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        groupBox->setFont(font);
        groupBox->setCursor(QCursor(Qt::ArrowCursor));
        groupBox->setContextMenuPolicy(Qt::DefaultContextMenu);
        groupBox->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        lineEdit_motdepass = new QLineEdit(groupBox);
        lineEdit_motdepass->setObjectName(QStringLiteral("lineEdit_motdepass"));
        lineEdit_motdepass->setGeometry(QRect(530, 170, 113, 31));
        lineEdit_motdepass->setStyleSheet(QLatin1String("color:black;\n"
"background-color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        lineEdit_nomutilisateur = new QLineEdit(groupBox);
        lineEdit_nomutilisateur->setObjectName(QStringLiteral("lineEdit_nomutilisateur"));
        lineEdit_nomutilisateur->setGeometry(QRect(530, 80, 113, 31));
        lineEdit_nomutilisateur->setStyleSheet(QLatin1String("color:black;\n"
"background-color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 80, 191, 20));
        label->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(340, 150, 151, 61));
        label_2->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 250, 231, 41));
        label_3->setStyleSheet(QLatin1String("border-color: rgb(85, 85, 255);\n"
"color: rgb(85, 85, 255);"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(0, 30, 251, 231));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/olympisc.jpg")));
        pushButton_7 = new QPushButton(groupBox);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(510, 260, 151, 31));
        tabWidget->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        tabWidget_2 = new QTabWidget(tab_10);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 761, 471));
        tabWidget_2->setStyleSheet(QStringLiteral(""));
        tab_11 = new QWidget();
        tab_11->setObjectName(QStringLiteral("tab_11"));
        lineEdit_ID_3 = new QLineEdit(tab_11);
        lineEdit_ID_3->setObjectName(QStringLiteral("lineEdit_ID_3"));
        lineEdit_ID_3->setGeometry(QRect(142, 19, 121, 31));
        lineEdit_ID_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_Nom_3 = new QLineEdit(tab_11);
        lineEdit_Nom_3->setObjectName(QStringLiteral("lineEdit_Nom_3"));
        lineEdit_Nom_3->setGeometry(QRect(132, 190, 111, 31));
        lineEdit_Nom_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_Prenom_3 = new QLineEdit(tab_11);
        lineEdit_Prenom_3->setObjectName(QStringLiteral("lineEdit_Prenom_3"));
        lineEdit_Prenom_3->setGeometry(QRect(122, 270, 111, 31));
        lineEdit_Prenom_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_Age_3 = new QLineEdit(tab_11);
        lineEdit_Age_3->setObjectName(QStringLiteral("lineEdit_Age_3"));
        lineEdit_Age_3->setGeometry(QRect(130, 100, 113, 31));
        lineEdit_Age_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_nationalite_3 = new QLineEdit(tab_11);
        lineEdit_nationalite_3->setObjectName(QStringLiteral("lineEdit_nationalite_3"));
        lineEdit_nationalite_3->setGeometry(QRect(460, 90, 121, 31));
        lineEdit_nationalite_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_specialite_3 = new QLineEdit(tab_11);
        lineEdit_specialite_3->setObjectName(QStringLiteral("lineEdit_specialite_3"));
        lineEdit_specialite_3->setGeometry(QRect(480, 180, 111, 31));
        lineEdit_specialite_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_mail_3 = new QLineEdit(tab_11);
        lineEdit_mail_3->setObjectName(QStringLiteral("lineEdit_mail_3"));
        lineEdit_mail_3->setGeometry(QRect(452, 260, 121, 31));
        lineEdit_mail_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        label_24 = new QLabel(tab_11);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(20, 30, 121, 21));
        label_24->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";\n"
""));
        label_25 = new QLabel(tab_11);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 200, 61, 21));
        label_25->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_26 = new QLabel(tab_11);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(20, 280, 91, 20));
        label_26->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_27 = new QLabel(tab_11);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(40, 90, 61, 41));
        label_27->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_28 = new QLabel(tab_11);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(330, 100, 131, 20));
        label_28->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_29 = new QLabel(tab_11);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setGeometry(QRect(390, 20, 71, 21));
        label_29->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_30 = new QLabel(tab_11);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setGeometry(QRect(340, 170, 121, 31));
        label_30->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        label_31 = new QLabel(tab_11);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(370, 260, 51, 21));
        label_31->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        comboBox_sexe_3 = new QComboBox(tab_11);
        comboBox_sexe_3->setObjectName(QStringLiteral("comboBox_sexe_3"));
        comboBox_sexe_3->setGeometry(QRect(470, 20, 101, 31));
        comboBox_sexe_3->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        boutton_ajouterath = new QPushButton(tab_11);
        boutton_ajouterath->setObjectName(QStringLiteral("boutton_ajouterath"));
        boutton_ajouterath->setGeometry(QRect(550, 330, 101, 31));
        boutton_ajouterath->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        label_5 = new QLabel(tab_11);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, -5, 771, 441));
        label_5->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/mondes21.jpg")));
        pushButton_Modifierath = new QPushButton(tab_11);
        pushButton_Modifierath->setObjectName(QStringLiteral("pushButton_Modifierath"));
        pushButton_Modifierath->setGeometry(QRect(390, 330, 111, 31));
        pushButton_Modifierath->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        label_nom_test = new QLabel(tab_11);
        label_nom_test->setObjectName(QStringLiteral("label_nom_test"));
        label_nom_test->setGeometry(QRect(100, 369, 381, 31));
        label_prenom_test = new QLabel(tab_11);
        label_prenom_test->setObjectName(QStringLiteral("label_prenom_test"));
        label_prenom_test->setGeometry(QRect(150, 320, 121, 16));
        tabWidget_2->addTab(tab_11, QString());
        label_5->raise();
        lineEdit_ID_3->raise();
        lineEdit_Nom_3->raise();
        lineEdit_Prenom_3->raise();
        lineEdit_Age_3->raise();
        lineEdit_nationalite_3->raise();
        lineEdit_specialite_3->raise();
        lineEdit_mail_3->raise();
        label_24->raise();
        label_25->raise();
        label_26->raise();
        label_27->raise();
        label_28->raise();
        label_29->raise();
        label_30->raise();
        label_31->raise();
        comboBox_sexe_3->raise();
        boutton_ajouterath->raise();
        pushButton_Modifierath->raise();
        label_nom_test->raise();
        label_prenom_test->raise();
        tab_12 = new QWidget();
        tab_12->setObjectName(QStringLiteral("tab_12"));
        groupBox_2 = new QGroupBox(tab_12);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 30, 791, 411));
        label_42 = new QLabel(groupBox_2);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setGeometry(QRect(30, 30, 151, 20));
        label_42->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        lineEdit_supprimerath = new QLineEdit(groupBox_2);
        lineEdit_supprimerath->setObjectName(QStringLiteral("lineEdit_supprimerath"));
        lineEdit_supprimerath->setGeometry(QRect(220, 30, 261, 31));
        lineEdit_supprimerath->setStyleSheet(QLatin1String("\n"
"color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        boutton_supprimerath = new QPushButton(groupBox_2);
        boutton_supprimerath->setObjectName(QStringLiteral("boutton_supprimerath"));
        boutton_supprimerath->setGeometry(QRect(500, 30, 111, 31));
        boutton_supprimerath->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        comboBox_trierath = new QComboBox(groupBox_2);
        comboBox_trierath->setObjectName(QStringLiteral("comboBox_trierath"));
        comboBox_trierath->setGeometry(QRect(130, 91, 131, 31));
        comboBox_trierath->setStyleSheet(QLatin1String("color:black;\n"
"font: 75 14pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_32 = new QLabel(groupBox_2);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setGeometry(QRect(30, 100, 81, 20));
        label_32->setStyleSheet(QLatin1String("font: 75 10pt \"MS Shell Dlg 2\";\n"
"font: 18pt \"MS Shell Dlg 2\";"));
        table_athletes_2 = new QTableView(groupBox_2);
        table_athletes_2->setObjectName(QStringLiteral("table_athletes_2"));
        table_athletes_2->setGeometry(QRect(0, 160, 751, 251));
        lineEdit_rechercher = new QLineEdit(groupBox_2);
        lineEdit_rechercher->setObjectName(QStringLiteral("lineEdit_rechercher"));
        lineEdit_rechercher->setGeometry(QRect(500, 99, 221, 31));
        lineEdit_rechercher->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        bouton_rechercherath = new QPushButton(groupBox_2);
        bouton_rechercherath->setObjectName(QStringLiteral("bouton_rechercherath"));
        bouton_rechercherath->setGeometry(QRect(344, 92, 131, 41));
        bouton_rechercherath->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"font: 75 16pt \"MS Shell Dlg 2\";\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        label_6 = new QLabel(tab_12);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(-20, -30, 791, 501));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../../Downloads/mondes21.jpg")));
        tabWidget_2->addTab(tab_12, QString());
        label_6->raise();
        groupBox_2->raise();
        tab_13 = new QWidget();
        tab_13->setObjectName(QStringLiteral("tab_13"));
        lineEdit_ID_mo = new QLineEdit(tab_13);
        lineEdit_ID_mo->setObjectName(QStringLiteral("lineEdit_ID_mo"));
        lineEdit_ID_mo->setGeometry(QRect(140, 30, 113, 20));
        lineEdit_ID_mo->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        label_34 = new QLabel(tab_13);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setGeometry(QRect(50, 170, 47, 14));
        label_35 = new QLabel(tab_13);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(30, 30, 101, 20));
        lineEdit_Nom_mo = new QLineEdit(tab_13);
        lineEdit_Nom_mo->setObjectName(QStringLiteral("lineEdit_Nom_mo"));
        lineEdit_Nom_mo->setGeometry(QRect(150, 180, 113, 20));
        lineEdit_Nom_mo->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_36 = new QLabel(tab_13);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(30, 260, 61, 20));
        lineEdit_Prenom_mo = new QLineEdit(tab_13);
        lineEdit_Prenom_mo->setObjectName(QStringLiteral("lineEdit_Prenom_mo"));
        lineEdit_Prenom_mo->setGeometry(QRect(150, 270, 113, 20));
        lineEdit_Prenom_mo->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        lineEdit_Age_mo = new QLineEdit(tab_13);
        lineEdit_Age_mo->setObjectName(QStringLiteral("lineEdit_Age_mo"));
        lineEdit_Age_mo->setGeometry(QRect(140, 100, 113, 20));
        lineEdit_Age_mo->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_37 = new QLabel(tab_13);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setGeometry(QRect(40, 100, 61, 20));
        label_37->setStyleSheet(QStringLiteral("font: 63 italic 12pt \"Lucida Fax\";"));
        lineEdit_nationalite_4 = new QLineEdit(tab_13);
        lineEdit_nationalite_4->setObjectName(QStringLiteral("lineEdit_nationalite_4"));
        lineEdit_nationalite_4->setGeometry(QRect(480, 30, 113, 20));
        lineEdit_nationalite_4->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_38 = new QLabel(tab_13);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setGeometry(QRect(350, 30, 101, 20));
        comboBox_sexe_4 = new QComboBox(tab_13);
        comboBox_sexe_4->setObjectName(QStringLiteral("comboBox_sexe_4"));
        comboBox_sexe_4->setGeometry(QRect(481, 100, 111, 22));
        comboBox_sexe_4->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_39 = new QLabel(tab_13);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setGeometry(QRect(400, 110, 47, 14));
        label_40 = new QLabel(tab_13);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setGeometry(QRect(360, 170, 91, 16));
        lineEdit_specialite_4 = new QLineEdit(tab_13);
        lineEdit_specialite_4->setObjectName(QStringLiteral("lineEdit_specialite_4"));
        lineEdit_specialite_4->setGeometry(QRect(480, 170, 113, 20));
        lineEdit_specialite_4->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        lineEdit_mail_4 = new QLineEdit(tab_13);
        lineEdit_mail_4->setObjectName(QStringLiteral("lineEdit_mail_4"));
        lineEdit_mail_4->setGeometry(QRect(490, 250, 113, 20));
        lineEdit_mail_4->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px"));
        label_41 = new QLabel(tab_13);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setGeometry(QRect(396, 250, 61, 20));
        tabWidget_2->addTab(tab_13, QString());
        tab_14 = new QWidget();
        tab_14->setObjectName(QStringLiteral("tab_14"));
        tabWidget_2->addTab(tab_14, QString());
        tabWidget->addTab(tab_10, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Authentification", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Nom d'utilisateur", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "mot de Passe", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Mot de passe Oubli\303\251?", Q_NULLPTR));
        label_4->setText(QString());
        pushButton_7->setText(QApplication::translate("MainWindow", "Se Connecter", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_9), QApplication::translate("MainWindow", "Authentification", Q_NULLPTR));
        lineEdit_ID_3->setText(QString());
        label_24->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_25->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_26->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_27->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        label_28->setText(QApplication::translate("MainWindow", "Nationalite", Q_NULLPTR));
        label_29->setText(QApplication::translate("MainWindow", "sexe", Q_NULLPTR));
        label_30->setText(QApplication::translate("MainWindow", "specialite", Q_NULLPTR));
        label_31->setText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        comboBox_sexe_3->clear();
        comboBox_sexe_3->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Masculin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Feminin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autres", Q_NULLPTR)
        );
        boutton_ajouterath->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_5->setText(QString());
        pushButton_Modifierath->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_nom_test->setText(QString());
        label_prenom_test->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_11), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "AFFICHAGE-SUPPRESSION", Q_NULLPTR));
        label_42->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        boutton_supprimerath->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        comboBox_trierath->clear();
        comboBox_trierath->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "age", Q_NULLPTR)
         << QApplication::translate("MainWindow", "nationalite", Q_NULLPTR)
         << QApplication::translate("MainWindow", "specialite", Q_NULLPTR)
        );
        label_32->setText(QApplication::translate("MainWindow", "Trier", Q_NULLPTR));
        bouton_rechercherath->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        label_6->setText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_12), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        lineEdit_ID_mo->setText(QString());
        label_34->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_35->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_36->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        label_37->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        label_38->setText(QApplication::translate("MainWindow", "Nationalite", Q_NULLPTR));
        comboBox_sexe_4->clear();
        comboBox_sexe_4->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Masculin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Feminin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autrs", Q_NULLPTR)
        );
        label_39->setText(QApplication::translate("MainWindow", "sexe", Q_NULLPTR));
        label_40->setText(QApplication::translate("MainWindow", "specialite", Q_NULLPTR));
        label_41->setText(QApplication::translate("MainWindow", "mail", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_13), QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_14), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_10), QApplication::translate("MainWindow", "Gestion des Athl\303\250tes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
