#ifndef GESTIONNAIREMARKTING_H
#define GESTIONNAIREMARKTING_H

#include <QDialog>
#include<QSqlRecord>
#include "g_marketing.h"

namespace Ui {
class GESTIONNAIREMARKTING;
}

class GESTIONNAIREMARKTING : public QDialog
{
    Q_OBJECT
    
public:
    explicit GESTIONNAIREMARKTING(QWidget *parent = 0);
    ~GESTIONNAIREMARKTING();
    
private slots:
    void on_pushButton_controlerpub_clicked();

    void on_pushButton_ajoutpaln_clicked();

    void on_pushButton_suppplan_clicked();

    void on_pushButton_afficher_plan_clicked();

    void on_pushButton_ajoutdemande_clicked();

    void on_pushButton_supdemande_clicked();

    void on_pushButton_modifierdemande_clicked();

    void on_pushButton_clicked();

private:
    Ui::GESTIONNAIREMARKTING *ui;
};

#endif // GESTIONNAIREMARKTING_H
