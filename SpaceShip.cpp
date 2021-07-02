#include "SpaceShip.h"

SpaceShip::SpaceShip(QTimer *timer, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set picture
    setPixmap(QPixmap(":/images/spaceship/image1.png"));
    setPos(885, 890);
}
