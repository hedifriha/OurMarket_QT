#include "login.h"
#include "ui_login.h"
#include "connectionbd.h"
#include "formadmin.h"
#include "gestionnairemarkting.h"


LOGIN::LOGIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LOGIN)
{
    ui->setupUi(this);
    ui->label_verification->hide();
    LOGIN::setWindowTitle("BIENVENU ");
}

LOGIN::~LOGIN()
{delete ui;}


void LOGIN::on_buttonBox_accepted()
{
    connectionBD *ConnSQL= new connectionBD;
    int a=ConnSQL->connectionBD(ui->lineEdit_username->text(),ui->lineEdit_password->text());
    if(a==1){
        if(ui->lineEdit_username->text()=="khairi"){
        if(ui->lineEdit_password->text()=="123"){
         hide();
         FORMADMIN *n=new FORMADMIN();
         n->show();}}}else{
               ui->label_verification->show();
               ui->lineEdit_username->setText("");
               ui->lineEdit_password->setText("");
           }
    if(ui->lineEdit_username->text()=="chmengui"){
        if(ui->lineEdit_password->text()=="123"){
         hide();
              GESTIONNAIREMARKTING *g=new GESTIONNAIREMARKTING();
               g->show();}}
               else{

               ui->label_verification->show();
               ui->lineEdit_username->setText("");
               ui->lineEdit_password->setText("");}}
