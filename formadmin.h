#ifndef FORMADMIN_H
#define FORMADMIN_H

#include <QDialog>
#include<QSqlRecord>
#include "chefcommerciale.h"

namespace Ui {
class FORMADMIN;
}

class FORMADMIN : public QDialog
{
    Q_OBJECT
    
public:
    explicit FORMADMIN(QWidget *parent = 0);
    ~FORMADMIN();
    
private slots:
    void on_pushButton_ajouterpub_clicked();

    void on_pushButton_modifierpub_clicked();

    void on_pushButton_supprimerpub_clicked();

    void on_pushButton_afficherpub_clicked();


private:
    Ui::FORMADMIN *ui;
};

#endif // FORMADMIN_H
