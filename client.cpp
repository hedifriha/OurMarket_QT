#include "client.h"



client::client()
{

   cin="";
   nom="hajer";
   prenom="hedi";
   email="";
   age="";
   civilite="";
   type_client="";
   activite="";


}
client::client(QString c, QString no, QString pr, QString mail, QString ac, QString ag, QString t, QString cv)
{
cin=c;
nom=no;
prenom=pr;
email=mail;
age=ag;
civilite=cv;
type_client=t;
activite=ac;



}

   QString client:: getcin()
   {return cin;}

   QString client::getnom()
   {return nom;}

   QString client ::getprenom()
   {return prenom;}

   QString client ::getemail()
   {return email;}

   QString client ::getcivilite()
   {return civilite;}

   QString client ::getage()
   {return age;}

   QString client ::getactivite()
   {return activite;}

   QString client ::gettype_client()
   {return type_client;}






