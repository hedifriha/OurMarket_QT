#ifndef PLAN_H
#define PLAN_H

#include <QString>
#include<QtSql>
#include<QSqlDatabase>
#include <QString>

class PLAN
{
private:
    QString titre;
    QString distinataire;
    QString description;
public:
    PLAN();
    PLAN(QString,QString,QString);
    QString getTitre();
    QString getDistinataire();
    QString getDescription();
    void setTitre(QString t)
    {titre=t;}
    void setDistinataire(QString d)
    {distinataire=d;}
    void setDescription(QString de)
    {distinataire=de;}};

#endif // PLAN_H
