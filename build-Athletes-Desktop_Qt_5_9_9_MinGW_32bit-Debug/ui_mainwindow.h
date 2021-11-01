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
    QWidget *tab;
    QTabWidget *tabWidget_2;
    QWidget *tab_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_nation;
    QLineEdit *lineEdit_special;
    QLineEdit *lineEdit_mail;
    QComboBox *comboBox_sexe;
    QLineEdit *lineEdit_age;
    QPushButton *pushButton;
    QWidget *tab_3;
    QWidget *tab_4;
    QLineEdit *lineEdit_supprimer;
    QLabel *label_10;
    QPushButton *pushButton_4;
    QWidget *tab_5;
    QTableView *tableView;
    QLabel *label_9;
    QComboBox *comboBox_trier;
    QLabel *label_11;
    QLineEdit *lineEdit_recherche;
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
        tabWidget->setGeometry(QRect(10, 10, 741, 401));
        QFont font;
        font.setFamily(QStringLiteral("Arial Narrow"));
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget_2 = new QTabWidget(tab);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 731, 371));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 61, 16));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 47, 14));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 130, 47, 14));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 190, 47, 14));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 30, 71, 16));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 80, 47, 14));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(370, 130, 61, 16));
        label_8 = new QLabel(tab_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(370, 180, 47, 14));
        lineEdit_id = new QLineEdit(tab_2);
        lineEdit_id->setObjectName(QStringLiteral("lineEdit_id"));
        lineEdit_id->setGeometry(QRect(130, 30, 113, 20));
        lineEdit_id->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_nom = new QLineEdit(tab_2);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(130, 80, 113, 20));
        lineEdit_nom->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_prenom = new QLineEdit(tab_2);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(130, 130, 113, 20));
        lineEdit_prenom->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_nation = new QLineEdit(tab_2);
        lineEdit_nation->setObjectName(QStringLiteral("lineEdit_nation"));
        lineEdit_nation->setGeometry(QRect(470, 30, 113, 20));
        lineEdit_nation->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_special = new QLineEdit(tab_2);
        lineEdit_special->setObjectName(QStringLiteral("lineEdit_special"));
        lineEdit_special->setGeometry(QRect(470, 130, 113, 20));
        lineEdit_special->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_mail = new QLineEdit(tab_2);
        lineEdit_mail->setObjectName(QStringLiteral("lineEdit_mail"));
        lineEdit_mail->setGeometry(QRect(470, 180, 113, 20));
        lineEdit_mail->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        comboBox_sexe = new QComboBox(tab_2);
        comboBox_sexe->setObjectName(QStringLiteral("comboBox_sexe"));
        comboBox_sexe->setGeometry(QRect(470, 80, 111, 22));
        comboBox_sexe->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        lineEdit_age = new QLineEdit(tab_2);
        lineEdit_age->setObjectName(QStringLiteral("lineEdit_age"));
        lineEdit_age->setGeometry(QRect(130, 190, 113, 20));
        lineEdit_age->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
""));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 260, 75, 23));
        tabWidget_2->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        lineEdit_supprimer = new QLineEdit(tab_4);
        lineEdit_supprimer->setObjectName(QStringLiteral("lineEdit_supprimer"));
        lineEdit_supprimer->setGeometry(QRect(250, 70, 241, 20));
        lineEdit_supprimer->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
"\n"
""));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(140, 70, 81, 20));
        pushButton_4 = new QPushButton(tab_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(320, 150, 101, 31));
        pushButton_4->setStyleSheet(QLatin1String("color:black;\n"
"border-color: rgb(222, 255, 52);\n"
"background-color: rgb(255, 255, 255);\n"
"border-style:outset;\n"
"border-width: 3px;\n"
"border-radius: 10px\n"
""));
        tabWidget_2->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tableView = new QTableView(tab_5);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 30, 431, 311));
        label_9 = new QLabel(tab_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(480, 80, 71, 21));
        comboBox_trier = new QComboBox(tab_5);
        comboBox_trier->setObjectName(QStringLiteral("comboBox_trier"));
        comboBox_trier->setGeometry(QRect(531, 80, 131, 22));
        label_11 = new QLabel(tab_5);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(430, 210, 61, 16));
        lineEdit_recherche = new QLineEdit(tab_5);
        lineEdit_recherche->setObjectName(QStringLiteral("lineEdit_recherche"));
        lineEdit_recherche->setGeometry(QRect(500, 210, 221, 20));
        lineEdit_recherche->setStyleSheet(QLatin1String("color:black;\n"
"border-style:outset;\n"
"border-width: 2px;\n"
"border-radius: 10px\n"
"\n"
""));
        tabWidget_2->addTab(tab_5, QString());
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Identifiant:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prenom:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Age:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Nationalit\303\251:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Sexe:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Sp\303\251cialit\303\251:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Mail:", Q_NULLPTR));
        comboBox_sexe->clear();
        comboBox_sexe->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Masculin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Feminin", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Autre", Q_NULLPTR)
        );
        pushButton->setText(QApplication::translate("MainWindow", "bouton", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_2), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Trier:", Q_NULLPTR));
        comboBox_trier->clear();
        comboBox_trier->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "Nationalit\303\251", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sexe", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Sp\303\251cialit\303\251", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Gestion des athl\303\250tes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
