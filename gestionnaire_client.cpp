
#include "gestionnaire_client.h"
#include <string>
#include <QMessageBox>
#include "connectionbd.h"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "client.h"


gestionnaire_client::gestionnaire_client()
{
}

//S'autentifier
int gestionnaire_client::Aut(QString login,QString mdp)
{

        connectionBD C;
        C.OuvrirConnexion();

           int test=0;
           QSqlQuery qry;
           qry.prepare("SELECT * FROM login WHERE LOGIN='"+login+"' and PASSWORD='"+mdp+"'");
           QString str="SELECT * FROM login WHERE LOGIN='"+login+"' and PASSWORD='"+mdp+"'";
           qDebug()<<str;

           if(qry.exec())
           {
               qDebug()<<str;
               int count=0;

                 while(qry.next())
               {
                   test++;
                   count++;
               }

               return count;
            }
       //  C.closeConnexion();
 qDebug()<<qry.lastError().text();
               return test;

}
void gestionnaire_client::AjouterClient(client C)
{
connectionBD *conneSQL=new connectionBD();
//connectionBD C;


QSqlQuery query2;
query2.prepare("INSERT INTO client (cin, nom, prenom, email, civilite, age, activite, type_client) "
              "VALUES (:cin, :nom, :prenom, :email, :civilite, :age , :activite , :type_client)");

query2.bindValue(":cin", C.getcin());
query2.bindValue(":nom", C.getnom());
query2.bindValue(":prenom", C.getprenom());
query2.bindValue(":email",C.getemail());
query2.bindValue(":civilite",C.getcivilite());
query2.bindValue(":age",C.getage());
query2.bindValue(":activite",C.getactivite());
query2.bindValue(":type_client",C.gettype_client());

qDebug()<<"test"<<"le nom"<<C.getnom();
bool test=query2.exec();
qDebug()<<test;
qDebug()<<query2.lastError().text();


    if(   query2.exec())
        qDebug("ouiiii");
    else
        qDebug("nonnnn");
    QMessageBox msg;
    msg.setText("Le client ajouter avec succés");
    msg.setWindowTitle("ajout!");
    msg.setWindowIcon(QIcon("A:/test2/ok.jpg"));
    msg.exec();



}

bool gestionnaire_client::SupprimerClient(client C)
{
    connectionBD *conneSQL=new connectionBD();


    QSqlQuery query;
    QMessageBox msg;

     query.prepare("Delete from client where cin =?" );
     query.bindValue(0, C.getcin());

     if(query.exec()){

    msg.setText("Le client supprimer avec succés");
    msg.setWindowTitle("suppresion!");
    msg.setWindowIcon(QIcon("A:/test2/ok.jpg"));
    msg.exec();
}else     msg.setText("Le client supprimer avec succés");


return 0;
}
bool gestionnaire_client::ModifierClient(client C)
{

    connectionBD *conneSQL=new connectionBD();

    QSqlQuery query;
    query.prepare("UPDATE client set nom='"+C.getnom()+"',prenom='"+C.getprenom()+"',email='"+C.getemail()+"',civilite='"+C.getcivilite()+"',age='"+C.getage()+"',activite='"+C.getactivite()+"',type_client='"+C.gettype_client()+"' where cin='"+C.getcin()+"'");

    QMessageBox msg;

    if (query.exec( )){
        msg.setText("Le client update avec succés");
        msg.setWindowTitle("update!");
        msg.setWindowIcon(QIcon("A:/test2/ok.jpg"));
        msg.exec();

    }
    else {
        msg.setText("Le client non update");

    }

}
QSqlQueryModel * gestionnaire_client::AfficherClient()
{
    connectionBD *conneSQL=new connectionBD();
    QSqlQuery* qrt=new QSqlQuery;
    QSqlQueryModel * model=new QSqlQueryModel();


    qrt->exec("Select * from client");
    model->setQuery(*qrt);
return model;
}
QSqlQueryModel * gestionnaire_client::prix_max()
{
    connectionBD *connSQL=new connectionBD();
    QSqlQuery* query=new QSqlQuery;
    QSqlQueryModel * model=new QSqlQueryModel();

    bool a=query->exec("SELECT id_application,nom_application,prix FROM application WHERE  prix=(SELECT MAX(prix) FROM application);");
    model->setQuery(*query);
    return model;
}
QSqlQueryModel * gestionnaire_client::prix_min()
{
    QSqlQuery* query=new QSqlQuery;
    QSqlQueryModel * model=new QSqlQueryModel();

    bool a=query->exec("SELECT id_application,nom_application,prix FROM application WHERE  prix=(SELECT MIN(prix) FROM application);");
    model->setQuery(*query);
    return model;


}
QSqlQueryModel * gestionnaire_client::produit_plus_vendus()
{

    QSqlQuery* query=new QSqlQuery;
    QSqlQueryModel * model=new QSqlQueryModel();

    bool a=query->exec("SELECT id_application,nom_application,nombre_achat FROM application WHERE nombre_achat=(SELECT MAX(nombre_achat) from application );");
    model->setQuery(*query);
    return model;

}


