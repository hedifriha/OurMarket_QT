#include "g_marketing.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "connectionbd.h"
#include "plan.h"

G_MARKETING::G_MARKETING()
{
}

void G_MARKETING::AjouterPlan(PLAN pl)
{
    connectionBD *ConnSQL= new connectionBD;

    QSqlQuery query;
    query.prepare("INSERT INTO plan (titre,distinataire,description) VALUES (:titre , :distinataire,:description)");

    query.bindValue(":titre", pl.getTitre());
    query.bindValue(":distinataire",pl.getDistinataire());
    query.bindValue(":description",pl.getDescription());
    qDebug()<<"test"<<"le titre"<<pl.getTitre();
    query.exec();
    QMessageBox msg;
    msg.setText("Le plan ajouter avec succés");
    msg.exec();}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool G_MARKETING::SupprimerPlan(PLAN pl)
{
    connectionBD *ConnSQL= new connectionBD;
    QSqlQuery query;

         query.prepare("Delete from plan where titre =? and distinataire =?" );
         query.bindValue(0, pl.getTitre());
         query.bindValue(1, pl.getDistinataire());
         query.exec();

        QMessageBox msg;
        msg.setText("Le plan supprimer avec succés");
        msg.exec();
    return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
QSqlQueryModel * G_MARKETING::AfficherPlan()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    connectionBD *ConnSQL= new connectionBD;
    model->setQuery("select * from plan");
    return model;
}
