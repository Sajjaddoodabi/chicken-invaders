#include "SpaceShip.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

SpaceShip::SpaceShip(QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent)
{
    // setting picture
    setPixmap(QPixmap(":/images/spaceship/image1.png"));
}

// keyboard's events
void SpaceShip::keyPressEvent(QKeyEvent *event)
{
    // moving spaceship with keyboard
    if(event->key() == Qt::Key_Left)
        setPos(x() - 10, y());
    else if(event->key() == Qt::Key_Up)
        setPos(x(), y() - 10);
    else if(event->key() == Qt::Key_Down)
        setPos(x(), y() + 10);
    else if(event->key() == Qt::Key_Right)
        setPos(x() + 10, y());

    // shooting with keyboard
    else if(event->key() == Qt::Key_Space){

        // creating bullet and adding to scene
        auto bullet = new Bullet();
        scene()->addItem(bullet);

        // setting bullet's position
        if(bullet->level == 1)
            setPos(x() + 65, y());
        else if(bullet->level == 2)
            setPos(x() + 56, y());
        else if(bullet->level == 3)
            setPos(x() + 47, y());
    }
}

void SpaceShip::mouseMoveEvent(QMouseEvent *event)
{

}

void SpaceShip::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // creating bullet and adding to scene
    auto bullet = new Bullet();
    scene()->addItem(bullet);

    // setting bullet's position
    if(bullet->level == 1)
        bullet->setPos(x() + 65, y());
    else if(bullet->level == 2)
        bullet->setPos(x() + 56, y());
    else if(bullet->level == 3)
        bullet->setPos(x() + 47, y());
}
