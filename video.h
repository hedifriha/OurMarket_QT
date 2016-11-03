#ifndef VIDEO_H
#define VIDEO_H
#include<phonon>
#include <QWidget>
#include <phonon/MediaObject>
#include <phonon/MediaSource>
#include<phonon/VideoPlayer>

namespace Ui {
class video;
}

class video : public QWidget
{
    Q_OBJECT
    
public:
    explicit video(QWidget *parent = 0);
    ~video();
    
private slots:
    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::video *ui;
    Phonon::MediaObject *media;
    Phonon::VideoPlayer *player;


};

#endif // VIDEO_H
