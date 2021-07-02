#include "SpaceShip.h"

SpaceShip::SpaceShip(QTimer *timer, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // set picture
    setPixmap(QPixmap(":/images/spaceship/image1.png"));
}

void SpaceShip::move(QMouseEvent *event)
{
    setPos(x() + event->pos().x(), y() + event->pos().y());
}
