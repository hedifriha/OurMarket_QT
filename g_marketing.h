#ifndef G_MARKETING_H
#define G_MARKETING_H

#include <QString>
#include<QSqlDatabase>
#include<QDialog>
#include "plan.h"
#include "chefcommerciale.h"
#include "gestionnairemarkting.h"

class G_MARKETING
{
public:
    G_MARKETING();
    void AjouterPlan(PLAN);
    bool SupprimerPlan(PLAN pl);
    virtual QSqlQueryModel * AfficherPlan();
};

#endif // G_MARKETING_H
