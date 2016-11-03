#include "menu1.h"
#include "ui_menu1.h"
#include"finance.h"
#include"Vente.h"
#include"QDesktopServices"
#include"QUrl"
#include"banque.h"

menu1::menu1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    menu1::setWindowTitle("OurMarket");
}

menu1::~menu1()
{
    delete ui;
}

void menu1::on_pushButton_clicked()
{   hide();
    finance d;
    d.exec();
}

void menu1::on_pushButton_2_clicked()
{   hide();
    Vente d;
    d.exec();
}

void menu1::on_pushButton_6_clicked()
{   hide();
    QDesktopServices::openUrl(QUrl("http://en.wikipedia.org/wiki/Enterprise_resource_planning", QUrl::TolerantMode));
}

void menu1::on_pushButton_5_clicked()
{   hide();
    banque d;
    d.exec();
}


