#include "connectionbd.h"

/*QSqlDatabase db;
QSqlQuery req;

connectionBD::connectionBD()
{
    db= QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName("C:/Users/hadhoud/Desktop/ourMarket.sqlite");

    db.open();

}
void connectionBD::fermerConnSQL()
{
    db.close();
}

int connectionBD::conn(QString LOGIN ,QString PASSWORD ) {

        int retourFct=0;

        if(db.open())
        {
           QSqlQuery qrt;

           if(qrt.exec("SELECT * FROM login"))
           {
               while(qrt.next())
               {
                   for(int x=1; x < qrt.record().count(); ++x)
                   {
                       if ((LOGIN==qrt.value(0).toString() && PASSWORD ==qrt.value(1).toString())==true)

                       retourFct= 1;
                       break;

               }
           }
        }
        else
        {
            qDebug() << "erreur :" << db.lastError().text();

        }
        qDebug()<<"opened";

        connectionBD::fermerConnSQL();
        return retourFct;


        }
        return 0;
       }
*/
#include <QMessageBox>

connectionBD::connectionBD()
{
}


bool connectionBD::OuvrirConnexion()

{
    bool test=false;

    db=QSqlDatabase::addDatabase("QSQLITE");
 db.setDatabaseName("C:/Users/hadhoud/Desktop/ourmarket.sqlite");

    db.open();

    if(db.open())

        {
          qDebug(" Connection effectué");
          test=true;
        }

     else

        qDebug("Non connecté?");

     return test;

}

void connectionBD::closeConnexion()

{

   db.close();

}


