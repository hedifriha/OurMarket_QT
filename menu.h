#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include"QSqlDatabase"
#include<QFileDialog>
#include<QtSql/QtSql>
#include<QTextDocument>
#include<QPrintDialog>
#include <QAxBase>
#include <QAxObject>
#include <QAxWidget>
#include <QDesktopServices>
#include <QUrl>
#include <QAxClass>
#include <QAxAggregated>
#include <QtNetwork>
namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT
    
public:
    explicit menu(QWidget *parent = 0);
    ~menu();

private slots:
//    void on_ajouter_accepted();

    void on_delete_2_clicked();

    void on_load_table_clicked();

    void on_ajouter_clicked(bool checked);

    void on_modification_clicked();

    void on_load_table_2_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_5_clicked();


    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_label_19_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    //void on_dateTimeEdit_editingFinished();

    //void on_ajouter_clicked(bool checked);

    void on_pushButton_9_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
