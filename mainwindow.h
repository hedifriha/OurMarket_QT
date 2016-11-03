#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include <phonon/VideoPlayer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *music;
   // Phonon::VideoPlayer *player;
};

#endif // MAINWINDOW_H
