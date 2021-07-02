#include "Chicken.h"
#include <QGraphicsScene>

Chicken::Chicken(int speedPerPix, QTimer *timer , QGraphicsItem * parent , int Health , bool isLord) :
    QObject() , QGraphicsPixmapItem(parent) , Health{Health} , speedPerPix{speedPerPix} , isLord{isLord}

{
    //setiing the chicken's pic
    if(isLord == false)
    setPixmap(QPixmap(":/image/invaders.png"));

    //setting the Lord's pic
    if(isLord == true)
    setPixmap(QPixmap(":/image/"));

    //connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

    //add sound for the chicken
    chickenSound = new QMediaPlayer();
    chickenSound->setMedia(QUrl("qrc:/music/"));

    if(chickenSound->state() == QMediaPlayer::PlayingState){
        chickenSound->setPosition(0);
    }
    else if(chickenSound->state() == QMediaPlayer::StoppedState){
        chickenSound->play();
    }

}

Chicken::~Chicken()
{
    delete chickenSound;
}

void Chicken::HeathDecrement()
{
    if(Health != 0)
        --Health;
    if(Health == 0){
        scene()->removeItem(this);
        chickenSound->setMedia(QUrl("qrc:/music/")); //ToDO
    }
}

void Chicken::move()
{

}
