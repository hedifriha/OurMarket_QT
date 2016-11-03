#ifndef RECEPT_H
#define RECEPT_H

#include <QWidget>

namespace Ui {
class recept;
}

class recept : public QWidget
{
    Q_OBJECT
    
public:
    explicit recept(QWidget *parent = 0);
    ~recept();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::recept *ui;
};

#endif // RECEPT_H
