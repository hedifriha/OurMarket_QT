#ifndef CHEFCOMMERCIALE_H
#define CHEFCOMMERCIALE_H

#include <QString>
#include<QSqlDatabase>
#include<QDialog>
#include "pub.h"
#include"formadmin.h"

class CHEFCOMMERCIALE
{

public:
    CHEFCOMMERCIALE();
    void AjouterPub(PUB);
    bool SupprimerPub(PUB p);
    virtual QSqlQueryModel * AfficherPub();
    bool ModifierPub(PUB p);

};

#endif // CHEFCOMMERCIALE_H
