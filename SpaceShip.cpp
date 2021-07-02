#include "SpaceShip.h"
#include <QGraphicsItem>

SpaceShip::SpaceShip(int Lives, int bulletLevel, QTimer *timer, QGraphicsItem *parent)
    : Lives{Lives} , bulletLevel{bulletLevel} , QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/image/game/ship.png"));
    setPos(600,600);
}

//moving spaceShip with keyboard
void SpaceShip::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left)
    {
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        setPos(x()+10,y());
    }
    else if (event->key() == Qt::Key_Space)
    {
        //ToDO
    }
}
