#include "Chicken.h"

Chicken::Chicken(int speedPerPix, QTimer *timer , QGraphicsItem * parent) :
    QObject() , QGraphicsPixmapItem(parent) , speedPerPix{speedPerPix}

{
    //setiing the chicken's pic
    setPixmap(QPixmap(":/image/invaders.png"));


}
