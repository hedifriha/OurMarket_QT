#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include<QtSql>
#include<QSqlDatabase>
#include <QString>

class client
{
private:
    QString cin;
    QString nom;
    QString prenom;
    QString email;
    QString civilite;
    QString age;
    QString type_client;
    QString activite;


public:
    client();
    client (QString, QString,QString,QString,QString, QString,QString,QString);

    QString getcin();
    QString getnom();
    QString getprenom();
    QString getemail();
    QString getcivilite();
    QString getage();
    QString getactivite();
    QString gettype_client();
    void Setcin(QString c)
    {cin=c;}
    void Setnom(QString n)
    {nom=n;}
    void Setprenom(QString p)
    {prenom=p;}
    void Setemail(QString e)
    {email=e;}

    void Setcivilite(QString cv)
    {civilite=cv;}
    void Settype_client(QString t)
    {type_client=t;}
    void Setage(QString ag)
    {age=ag;}
    void Setactivite(QString ac)
    {activite=ac;}

};

#endif // CLIENT_H
