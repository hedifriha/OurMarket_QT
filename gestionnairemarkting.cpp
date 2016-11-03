#include "gestionnairemarkting.h"
#include "ui_gestionnairemarkting.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "connectionbd.h"
#include "plan.h"
#include "g_marketing.h"
#include "demande.h"
#include "gerer_demande.h"
#include <QMessageBox>

GESTIONNAIREMARKTING::GESTIONNAIREMARKTING(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GESTIONNAIREMARKTING)
{
    ui->setupUi(this);
    GESTIONNAIREMARKTING::setWindowTitle("Gestionnaire Marketing");}

GESTIONNAIREMARKTING::~GESTIONNAIREMARKTING()
{ delete ui;}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_ajoutpaln_clicked()
{
              G_MARKETING g;
              QMessageBox msg;

                    qDebug()<<ui->lineEdit_plantitre->text();
               PLAN pl

                       (   ui->lineEdit_plantitre->text() ,
                           ui->lineEdit_distinataire->text(),
                           ui->lineEdit_description->text()
                           );

               if(ui->lineEdit_plantitre->text().isEmpty()){
                   QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE LE TITRE");
                                      ui->lineEdit_plantitre->text() ,
                                      ui->lineEdit_plantitre->setFocus(Qt::OtherFocusReason);
                                      ui->lineEdit_plantitre->setStyleSheet("background-color:#FF0000");
                      return ;}else{ if(ui->lineEdit_distinataire->text().isEmpty()){
                   QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE LE DISTINATAIRE");
                                      ui->lineEdit_distinataire->text() ,
                                      ui->lineEdit_distinataire->setFocus(Qt::OtherFocusReason);
                                      ui->lineEdit_distinataire->setStyleSheet("background-color:#FF0000");
                      return ;}

               qDebug()<<"votre programme fonctionne correctemet"<<pl.getTitre();
               g.AjouterPlan(pl);

              msg.setText("Ajouter avec succés");
              ui->tableView->setModel(g.AfficherPlan());}}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_suppplan_clicked()
{
    QMessageBox msg;
    PLAN pl;
    G_MARKETING g;

            QString titre = ui->lineEdit_plantitre->text();
            pl.setTitre(titre);
            QString distinataire = ui->lineEdit_distinataire->text();
            pl.setDistinataire(distinataire);

            bool test= g.SupprimerPlan(pl);
            if(test==true)
            {msg.setText("le Plan a ete Supprimer");
             }ui->tableView->setModel(g.AfficherPlan());}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_controlerpub_clicked()
{
    connectionBD *ConnSQL= new connectionBD;
    CHEFCOMMERCIALE c;

 ui->tableView->setModel(c.AfficherPub());}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_afficher_plan_clicked()
{
    connectionBD *ConnSQL= new connectionBD;
    G_MARKETING g;

    ui->tableView->setModel(g.AfficherPlan());}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_ajoutdemande_clicked()
{

    GERER_DEMANDE gd;
    QMessageBox msg;

              qDebug()<<ui->lineEdit_id_demande->text();
              DEMANDE d

                       (   ui->lineEdit_id_demande->text() ,
                           ui->lineEdit_nom_du_clients->text(),
                           ui->lineEdit_type_de_lapplication->text(),
                           ui->lineEdit_lanquage->text(),
                           ui->TimeEdit_datee->text()
                           );

              if(ui->lineEdit_id_demande->text().isEmpty()){
                  QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE L'ID DEMANDE");
                                     ui->lineEdit_id_demande->text() ,
                                     ui->lineEdit_id_demande->setFocus(Qt::OtherFocusReason);
                                     ui->lineEdit_id_demande->setStyleSheet("background-color:#FF0000");
                     return ;}else{ if(ui->lineEdit_nom_du_clients->text().isEmpty()){
                  QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE LE NOM");
                                     ui->lineEdit_nom_du_clients->text() ,
                                     ui->lineEdit_nom_du_clients->setFocus(Qt::OtherFocusReason);
                                     ui->lineEdit_nom_du_clients->setStyleSheet("background-color:#FF0000");
                     return ;}else{ if(ui->lineEdit_type_de_lapplication->text().isEmpty()){
                  QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE LE TYPE");
                                     ui->lineEdit_type_de_lapplication->text() ,
                                     ui->lineEdit_type_de_lapplication->setFocus(Qt::OtherFocusReason);
                                     ui->lineEdit_type_de_lapplication->setStyleSheet("background-color:#FF0000");
                     return ;}else{ if(ui->lineEdit_lanquage->text().isEmpty()){
                  QMessageBox::warning(this,"Erreur","VOUS DEVEZ SAISIRE LE LANNGUAGE");
                                      ui->lineEdit_lanquage->text() ,
                                      ui->lineEdit_lanquage->setFocus(Qt::OtherFocusReason);
                                      ui->lineEdit_lanquage->setStyleSheet("background-color:#FF0000");
                     return ;}}

              qDebug()<<"votre programme fonctionne correctemet"<<d.getID_DEMANDE();
              gd.AjouterDemande(d);
              msg.setText("Ajouter avec succés");
              ui->tableView_demande->setModel(gd.AfficherDemande());
}}}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_supdemande_clicked()
{
    DEMANDE d;
    GERER_DEMANDE gd;

            QString id_demande = ui->lineEdit_id_demande->text();
            d.setID_DEMANDE(id_demande);
            d.setNOM_CLIENT(ui->lineEdit_nom_du_clients->text());

            bool test= gd.SupprimerDemande(d);
            QMessageBox::critical(this,tr("Supprimer"),tr("Publiciter Supprimer"));
            ui->tableView_demande->setModel(gd.AfficherDemande());}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_modifierdemande_clicked()
{
       DEMANDE d;
       GERER_DEMANDE gd;


               QString id_demande           = ui->lineEdit_id_demande->text();
               QString nom_cliient          = ui->lineEdit_nom_du_clients->text();
               QString type_application     = ui->lineEdit_type_de_lapplication->text();
               QString language_application = ui->lineEdit_lanquage->text();
               QString duree                = ui->TimeEdit_datee->text();

               d.setID_DEMANDE(id_demande);
               d.setNOM_CLIENT(nom_cliient);
               d.setTYPE_APPLICATION(type_application);
               d.setLANGUAGE_APPLICATION(language_application);
               d.setDATE(duree);

                gd.ModifierDemande(d);
                ui->tableView_demande->setModel(gd.AfficherDemande());}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void GESTIONNAIREMARKTING::on_pushButton_clicked()
{
    connectionBD *conneSQL=new connectionBD();
    GERER_DEMANDE gd;
    ui->tableView_demande->setModel(gd.AfficherDemande());
}
