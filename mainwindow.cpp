#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include "connectionbd.h"
#include <phonon/VideoPlayer>
#include "video.h"
#include "gestionnaire_client.h"
#include "formadmin.h"
#include "recept.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    connectionBD *connSQL= new connectionBD();
    gestionnaire_client g;
   bool a= g.Aut(ui->lineEdit->text(),ui->lineEdit_2->text());
   if (a==1)
   {/* if(ui->lineEdit_username->text()=="khairi"){
           if(ui->lineEdit_password->text()=="123"){
            hide();
            FORMADMIN *n=new FORMADMIN();
            n->show();}}}else{
                  ui->label_verification->show();
                  ui->lineEdit_username->setText("");
                  ui->lineEdit_password->setText("");
              }*/

   if(ui->lineEdit->text()=="hedi"){
       if(ui->lineEdit_2->text()=="hedi")
    hide();
    video *n=new video();
    n->show();
    Phonon::MediaObject *music=createPlayer(Phonon::MusicCategory,
                                Phonon::MediaSource("C:/Users/hadhoud/Desktop/865862.mp3"));
    music->play();

   }
}
   if(ui->lineEdit->text()=="khairi"){
              if(ui->lineEdit_2->text()=="123"){
               hide();
               recept *n=new recept();
               n->show();}}
}
