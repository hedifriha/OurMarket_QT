#include "reception.h"
#include "ui_reception.h"

reception::reception(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::reception)
{
    ui->setupUi(this);
}

reception::~reception()
{
    delete ui;
}
