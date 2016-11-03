#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

namespace Ui {
class LOGIN;
}

class LOGIN : public QDialog
{
    Q_OBJECT
    
public:
    explicit LOGIN(QWidget *parent = 0);
    ~LOGIN();
    
private slots:
    void on_buttonBox_accepted();

private:
    Ui::LOGIN *ui;
};

#endif // LOGIN_H
