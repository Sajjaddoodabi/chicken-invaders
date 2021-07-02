#include "babyChicken.h"

babyChicken::babyChicken(int speedPerPix, QTimer *timer, QGraphicsItem *parent, int Healt)
    : QObject() , QGraphicsPixmapItem(parent) , Health{Health} , speedPerPix{speedPerPix}
{
    //set picture for baby chicken
    setPixmap(QPixmap(":/image/"));

}

void babyChicken::move()
{

}
