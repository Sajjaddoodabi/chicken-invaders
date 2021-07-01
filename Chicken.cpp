#include "Chicken.h"

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

}

void Chicken::move()
{

}
