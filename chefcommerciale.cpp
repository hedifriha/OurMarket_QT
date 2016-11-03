#include "chefcommerciale.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "connectionbd.h"
#include "pub.h"

CHEFCOMMERCIALE::CHEFCOMMERCIALE()
{}

void CHEFCOMMERCIALE::AjouterPub(PUB p)
{
    connectionBD *ConnSQL= new connectionBD;

    QSqlQuery query;
    query.prepare("INSERT INTO pub ( nom, editeur, forum,duree) VALUES (:nom,:editeur,:forum,:duree)");

    query.bindValue(":nom", p.getNom());
    query.bindValue(":editeur",p.getEditeur());
    query.bindValue(":forum", p.getForum());
    query.bindValue(":duree",p.getDuree());
    qDebug()<<"test"<<"le nom"<<p.getNom();
    query.exec();}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool CHEFCOMMERCIALE::SupprimerPub(PUB p)
{
    connectionBD *ConnSQL= new connectionBD;
    QSqlQuery query;

         query.prepare("Delete from pub where nom =? and forum =?" );
         query.bindValue(0, p.getNom());
         query.bindValue(1, p.getForum());
         query.exec();

         qDebug()<<query.lastError().text()<<p.getNom()<<p.getForum();
    return 0;}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool CHEFCOMMERCIALE::ModifierPub(PUB p)
{
    connectionBD *ConnSQL= new connectionBD;
    QSqlQuery query;
     QMessageBox msg;

    qDebug()<<p.getNom();
    query.prepare("UPDATE pub set editeur='"+p.getEditeur()+"',forum='"+p.getForum()+"',duree='"+p.getDuree()+"'where nom='"+p.getNom()+"'");

    if (query.exec( )){
        msg.setText("VOUS AVEZ MODIFIER UNE PUBLICITER");
        msg.exec();}
    else
    { msg.setText("ECHEC MODIFICATION");}

    qDebug()<<query.lastError().text();
return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * CHEFCOMMERCIALE::AfficherPub()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    connectionBD *ConnSQL= new connectionBD;
    model->setQuery("select * from pub");
    return model;
}







