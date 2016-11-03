#include "recept.h"
#include "ui_recept.h"
#include "gestionnairemarkting.h"
#include "formadmin.h"
recept::recept(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recept)
{
    ui->setupUi(this);
}

recept::~recept()
{
    delete ui;
}

void recept::on_pushButton_clicked()
{
    hide();
    FORMADMIN *n=new FORMADMIN();
    n->show();
}

void recept::on_pushButton_2_clicked()
{
    hide();
    GESTIONNAIREMARKTING *m=new GESTIONNAIREMARKTING();
    m->show();

}
