#ifndef PUB_H
#define PUB_H

#include <QString>
#include<QtSql>
#include<QSqlDatabase>
#include <QString>

class PUB
{
private:
    QString nom;
    QString editeur;
    QString forum;
    QString duree;
public:
    PUB();
    PUB(QString,QString,QString,QString);
    QString getNom();
    QString getEditeur();
    QString getForum();
    QString getDuree();
    void setNom(QString n)
    {nom=n;}
    void setEditeur(QString e)
    {editeur=e;}
    void setForum(QString f)
    {forum=f;}
    void setDuree(QString d)
    {duree=d;}};

#endif // PUB_H
