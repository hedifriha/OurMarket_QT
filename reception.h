#ifndef RECEPTION_H
#define RECEPTION_H

#include <QWidget>

namespace Ui {
class reception;
}

class reception : public QWidget
{
    Q_OBJECT
    
public:
    explicit reception(QWidget *parent = 0);
    ~reception();
    
private:
    Ui::reception *ui;
};

#endif // RECEPTION_H
