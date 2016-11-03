#ifndef MENU1_H
#define MENU1_H

#include <QWidget>

namespace Ui {
class menu1;
}

class menu1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit menu1(QWidget *parent = 0);
    ~menu1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();
private:
    Ui::menu1 *ui;
};

#endif // MENU1_H
