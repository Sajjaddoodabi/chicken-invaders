#include "Chicken.h"

Chicken::Chicken(int speedPerPix, QTimer *timer , QGraphicsItem * parent) :
    QGraphicsPixmapItem(parent) , speedPerPix{speedPerPix}

{
    //setiing the chicken's pic
    if(isLord == false)
    setPixmap(QPixmap(":/image/invaders.png"));

    //setting the Lord's pic
    if(isLord == true)
    setPixmap(QPixmap(":/image/"));


}
