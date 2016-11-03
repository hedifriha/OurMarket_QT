#ifndef GESTIONNAIRE_CLIENT_H
#define GESTIONNAIRE_CLIENT_H

#include "client.h"
#include<QSqlDatabase>
#include"menu.h"
#include<QDialog>
class gestionnaire_client
{
public:
    gestionnaire_client();
    int Aut(QString,QString);
    void AjouterClient(client);
    bool SupprimerClient(client C);
    bool ModifierClient(client);
   QSqlQueryModel * AfficherClient();
   QSqlQueryModel * prix_max();
   QSqlQueryModel * prix_min();
   QSqlQueryModel * produit_plus_vendus();

};


#endif // GESTIONNAIRE_CLIENT_H
