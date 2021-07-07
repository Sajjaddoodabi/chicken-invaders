#include "BabyChicken.h"
#include <QGraphicsScene>

BabyChicken::BabyChicken(int speedPerPix, QTimer *timer, QGraphicsItem *parent, int Health)
    : QObject() , QGraphicsPixmapItem(parent) , Health{Health} , speedPerPix{speedPerPix}
{
    //set picture for baby chicken
    setPixmap(QPixmap(":/image/"));

    //connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

    //add sound for the chicken
    BabyChickenSound = new QMediaPlayer();
    BabyChickenSound->setMedia(QUrl("qrc:/music/"));

    if(BabyChickenSound->state() == QMediaPlayer::PlayingState){
        BabyChickenSound->setPosition(0);
    }
    else if(BabyChickenSound->state() == QMediaPlayer::StoppedState){
        BabyChickenSound->play();
    }

}

BabyChicken::~BabyChicken()
{
    delete BabyChickenSound;
}

void BabyChicken::HealthDecrement()
{
    if(Health != 0)
        --Health;
    if(Health == 0){
        scene()->removeItem(this);
        BabyChickenSound->setMedia(QUrl("qrc:/music/")); //ToDO
    }
}


//ToDO
void BabyChicken::move()
{

}
