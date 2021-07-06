#include "SpaceShip.h"
#include "Bullet.h"
#include <QGraphicsScene>

SpaceShip::SpaceShip(QTimer *spaceShipTimer, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent),
    spaceShipTimer{spaceShipTimer}
{
    // set picture
    setPixmap(QPixmap(":/images/spaceship/image1.png"));
}

// destructor
SpaceShip::~SpaceShip()
{
    delete spaceShipTimer;
    delete spaceShipMedia;
    delete bullet;
}

void SpaceShip::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        setPos(x() - 10, y());
    else if(event->key() == Qt::Key_Up)
        setPos(x(), y() - 10);
    else if(event->key() == Qt::Key_Down)
        setPos(x(), y() + 10);
    else if(event->key() == Qt::Key_Right)
        setPos(x() + 10, y());
    else if(event->key() == Qt::Key_Space){
        auto bullet = new Bullet(spaceShipTimer, spaceShipMedia);
        scene()->addItem(bullet);
        setPos(x() + 65, y());
    }
}
