#ifndef DEMANDE_H
#define DEMANDE_H

#include <QString>
#include<QtSql>
#include<QSqlDatabase>
#include <QString>

class DEMANDE
{
private:
    QString id_demande;
    QString nom_clients;
    QString type_application;
    QString language_application;
    QString date;
public:
    DEMANDE();
    DEMANDE(QString,QString,QString,QString,QString);

    QString getID_DEMANDE();
    QString getNOM_CLIENT();
    QString getTYPE_APPLICATION();
    QString getLANGUAGE_APPLICATION();
    QString getDATE();

    void setID_DEMANDE(QString i)
    {id_demande=i;}
    void setNOM_CLIENT(QString n)
    {nom_clients=n;}
    void setTYPE_APPLICATION(QString t)
    {type_application=t;}
    void setLANGUAGE_APPLICATION(QString l)
    {language_application=l;}
    void setDATE(QString d)
    {date=d;}
};


#endif // DEMANDE_H
