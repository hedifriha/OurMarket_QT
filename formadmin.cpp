#include "formadmin.h"
#include "ui_formadmin.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "chefcommerciale.h"
#include "pub.h"
#include "connectionbd.h"
#include <QString>
FORMADMIN::FORMADMIN(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FORMADMIN)
{
    ui->setupUi(this);
    FORMADMIN::setWindowTitle("FORMADMIN");
}

FORMADMIN::~FORMADMIN()
{
    delete ui;
}

void FORMADMIN::on_pushButton_ajouterpub_clicked()
{
    QMessageBox msg;
    CHEFCOMMERCIALE c;

  qDebug()<<ui->lineEdit_nom->text();
               PUB p

                       (
                           ui->lineEdit_nom->text() ,
                           ui->lineEdit_editeur->text() ,
                           ui->lineEdit_forum->text(),
                           ui->timeEdit_duree->text()
                           );
               if(ui->lineEdit_nom->text().isEmpty())
                              {
                              QMessageBox::warning(this,"Erreur","vous devez saisir le nom");
                                      ui->lineEdit_nom->text() ,
                                      ui->lineEdit_nom->setFocus(Qt::OtherFocusReason);
                              ui->lineEdit_nom->setStyleSheet("background-color:#FF0000");
                              return ;}else{ if(ui->lineEdit_editeur->text().isEmpty())
                   {
                   QMessageBox::warning(this,"Erreur","vous devez saisir l'editeur");
                           ui->lineEdit_editeur->text() ,
                           ui->lineEdit_editeur->setFocus(Qt::OtherFocusReason);
                   ui->lineEdit_editeur->setStyleSheet("background-color:#FF0000");
                   return ;}else{ if(ui->lineEdit_forum->text().isEmpty())
                       {
                       QMessageBox::warning(this,"Erreur","vous devez saisir le forum");
                               ui->lineEdit_forum->text() ,
                               ui->lineEdit_forum->setFocus(Qt::OtherFocusReason);
                       ui->lineEdit_forum->setStyleSheet("background-color:#FF0000");
                       return ;}

               qDebug()<<"votre programme fonctionne correctemet"<<p.getNom();
               c.AjouterPub(p);

              ui->tableView->setModel(c.AfficherPub());
              QMessageBox::information(this,tr("Ajouter"),tr("Publiciter Ajouter"));
               msg.setText("Ajouter avec succés");
}}}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FORMADMIN::on_pushButton_modifierpub_clicked()
{
    PUB p;
    CHEFCOMMERCIALE c;


            QString nom     = ui->lineEdit_nom->text();
            QString editeur = ui->lineEdit_editeur->text();
            QString forum   = ui->lineEdit_forum->text();
            QString duree   = ui->timeEdit_duree->text();

            p.setNom(nom);
            p.setEditeur(editeur);
            p.setForum(forum);
            p.setDuree(duree);

            c.ModifierPub(p);
             ui->tableView->setModel(c.AfficherPub());}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FORMADMIN::on_pushButton_supprimerpub_clicked()
{
QMessageBox msg;
PUB p;
CHEFCOMMERCIALE c;


        QString nom = ui->lineEdit_nom->text();
        p.setNom(nom);
        p.setForum(ui->lineEdit_forum->text());

        bool test= c.SupprimerPub(p);
        QMessageBox::critical(this,tr("Supprimer"),tr("Publiciter Supprimer"));
        ui->tableView->setModel(c.AfficherPub());}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void FORMADMIN::on_pushButton_afficherpub_clicked()
{
   connectionBD *conneSQL=new connectionBD();
   CHEFCOMMERCIALE c;
   ui->tableView->setModel(c.AfficherPub());
}

