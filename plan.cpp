#include "plan.h"

PLAN::PLAN()
{
    titre=" ";
    distinataire=" ";
    description=" ";
}

PLAN::PLAN(QString t,QString d,QString de)
{titre=t;
distinataire=d;
description=de;}

QString PLAN::getTitre()
{return titre;}
QString PLAN::getDistinataire()
{return distinataire;}
QString PLAN::getDescription()
{return description;}
