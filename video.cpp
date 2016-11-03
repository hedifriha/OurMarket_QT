#include "video.h"
#include "ui_video.h"
#include<phonon/VideoPlayer>
#include "menu.h"
video::video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::video)
{
    ui->setupUi(this);
  /*  media = new Phonon::MediaObject(this);
            media->setCurrentSource(Phonon::MediaSource("A:/video/xfactor.flv"));

            Phonon::VideoWidget* fvid=new Phonon::VideoWidget(this);
            Phonon::createPath(media,fvid);
            fvid->setGeometry(20,20,122,122);
            fvid->show();

            Phonon::VideoWidget* fvid2=new Phonon::VideoWidget(this);
            Phonon::createPath(media,fvid2);
            fvid2->setGeometry(220,220,122,122);
            fvid2->show();*/
}

video::~video()
{
    delete ui;
}

void video::on_pushButton_clicked()
{
    //Phonon::VideoPlayer *player =
     //        new Phonon::VideoPlayer(Phonon::VideoCategory, ui->widget);
     //    player->play(Phonon::MediaSource ("A:/video/xfactor.flv"));}
  // Phonon::VideoPlayer *player = new Phonon::VideoPlayer(Phonon::VideoCategory, ui->widget);
  //   connect(player, SIGNAL(finished()), player, SLOT(deleteLater()));
  //   player->play(Phonon::MediaSource ("A:/video/xfactor.flv"));

}

void video::on_commandLinkButton_clicked()
{
    hide();
    menu *n=new menu();
   n->show();
}
