#include "pub.h"

PUB::PUB()
{
    nom="";
    editeur="";
    forum="";
    duree="";
}
PUB::PUB(QString n,QString e,QString f,QString d)
{nom    =n;
 editeur=e;
 forum  =f;
 duree  =d;
}
QString PUB::getNom()
{return nom;}
QString PUB::getEditeur()
{return editeur;}
QString PUB::getForum()
{return forum;}
QString PUB::getDuree()
{return duree;}
