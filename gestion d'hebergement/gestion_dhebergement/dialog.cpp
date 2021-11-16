#include "dialog.h"
#include "ui_dialog.h"
#include<QQuickItem>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->fakhri->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
ui->fakhri->show();


auto obj = ui-> fakhri->rootObject();
connect(this,SIGNAL(setCenter(Qvariant,Qvariant)), obj, SLOT(setCenter(Qvarian,Qvariant)));

//emit setCenter(25.000,50.000);

}




Dialog::~Dialog()
{
    delete ui;
}
