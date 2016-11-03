#include "gerer_demande.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "connectionbd.h"
#include "demande.h"
#include <QMessageBox>
GERER_DEMANDE::GERER_DEMANDE()
{
}

void GERER_DEMANDE::AjouterDemande(DEMANDE d)
{
    connectionBD *ConnSQL= new connectionBD;

    QSqlQuery query;
    query.prepare("INSERT INTO demande (id_demande,nom_clients,type_application,language_application,date) VALUES (:id_demande,:nom_clients,:type_application,:language_application,:date)");

    query.bindValue(":id_demande", d.getID_DEMANDE());
    query.bindValue(":nom_clients",d.getNOM_CLIENT());
    query.bindValue(":type_application",d.getTYPE_APPLICATION());
    query.bindValue(":language_application",d.getLANGUAGE_APPLICATION());
    query.bindValue(":date",d.getDATE());
    qDebug()<<"test"<<"le id_demande"<<d.getID_DEMANDE();
    query.exec();
    QMessageBox msg;
    msg.setText("La demande ajouter avec succés");
    msg.exec();}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GERER_DEMANDE::SupprimerDemande(DEMANDE d)
{
        connectionBD *ConnSQL= new connectionBD;
        QSqlQuery query;

             query.prepare("Delete from demande where id_demande =? and nom_clients =?" );
             query.bindValue(0, d.getID_DEMANDE());
             query.bindValue(1, d.getNOM_CLIENT());
             query.exec();

      qDebug()<<query.lastError().text()<<d.getID_DEMANDE()<<d.getNOM_CLIENT();
        return 0;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool GERER_DEMANDE::ModifierDemande(DEMANDE d)
{
    connectionBD *ConnSQL= new connectionBD;
    QSqlQuery query;
    QMessageBox msg;

    qDebug()<<d.getID_DEMANDE();
    query.prepare("UPDATE demande set nom_clients='"+d.getNOM_CLIENT()+"',type_application='"+d.getTYPE_APPLICATION()+"',language_application='"+d.getLANGUAGE_APPLICATION()+"'where id_demande='"+d.getID_DEMANDE()+"'");

    if (query.exec( )){
        msg.setText("VOUS AVEZ MODIFIER UN DEMANDE");
        msg.exec();
    } else{ msg.setText("ECHEC MODIFICATION");}

    qDebug()<<query.lastError().text();
return 0;}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * GERER_DEMANDE::AfficherDemande()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    connectionBD *ConnSQL= new connectionBD;
    model->setQuery("select * from demande");
    return model;
}
