#include "demande.h"

DEMANDE::DEMANDE()
{
    id_demande="";
    nom_clients="";
    type_application="";
    language_application="";
    date="";
}

DEMANDE::DEMANDE(QString i,QString n,QString t,QString l,QString d)
{id_demande=i;
nom_clients=n;
type_application=t;
language_application=l;
date=d;}

QString DEMANDE::getID_DEMANDE()
{return id_demande;}
QString DEMANDE::getNOM_CLIENT()
{return nom_clients;}
QString DEMANDE::getTYPE_APPLICATION()
{return type_application;}
QString DEMANDE::getLANGUAGE_APPLICATION()
{return language_application;}
QString DEMANDE::getDATE()
{return date;}
