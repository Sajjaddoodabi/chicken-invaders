#include "Gift.h"

Gift::Gift(QGraphicsItem *parent) : QObject() ,
       QGraphicsPixmapItem (parent)
{
    // set meat picture
    setPixmap(QPixmap(":/images/gift.png"));

    //timer
    giftTimer = new QTimer;

    //connect timer with move
    connect(giftTimer , SIGNAL(timeout()) , this , SLOT(move()));

    //start the timer
    giftTimer -> start(); //ToDO
}

Gift::~Gift()
{
    delete giftTimer;
}

void Gift::move()
{
    setPos(x(), y() + 27);

     if(y() >= 1080)
     {
         scene()->removeItem(this);
         delete this;
     }
}
