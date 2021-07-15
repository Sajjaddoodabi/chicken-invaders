#include "Gift.h"

Gift::Gift(QGraphicsScene *GiftScene, QTimer *timer, QGraphicsItem *parent) : QObject() ,
       QGraphicsPixmapItem (parent) , GiftScene(GiftScene)
{
    // set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    //scene
    GiftScene = new QGraphicsScene;
    GiftScene->addItem(this);
    setPos(20 , 50);  //ToDO

    //timer
    timer = new QTimer;

    //connect timer with move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

    //start the timer
    timer -> start(); //ToDO

    timeIntervals = 0;
}

Gift::~Gift()
{
    delete GiftScene;
}

void Gift::move()
{
    ++timeIntervals;
    setPos(x(), y() + 27);

     if(y() >= 1080)
     {
         GiftScene->removeItem(this);
         delete this;
     }
}
