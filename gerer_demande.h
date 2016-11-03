#ifndef GERER_DEMANDE_H
#define GERER_DEMANDE_H

#include <QString>
#include<QSqlDatabase>
#include<QDialog>
#include "demande.h"

class GERER_DEMANDE
{
public:
    GERER_DEMANDE();
    void AjouterDemande(DEMANDE);
    bool SupprimerDemande(DEMANDE d);
    virtual QSqlQueryModel * AfficherDemande();
    bool ModifierDemande(DEMANDE d);
};

#endif // GERER_DEMANDE_H
