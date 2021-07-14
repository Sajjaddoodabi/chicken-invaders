#include "SpaceShip.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

SpaceShip::SpaceShip(Score *score, QGraphicsItem *parent) : QObject(), QGraphicsPixmapItem(parent),
    score{score}
{
    // setting picture
    setPixmap(QPixmap(":/images/spaceship/image1.png"));
}

void SpaceShip::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::MouseButton::LeftButton){
        // creating bullet and adding to scene
        auto bullet = new Bullet(score);
        scene()->addItem(bullet);

        // setting bullet's position
        if(bullet->level == 1)
            bullet->setPos(x() + 65, y());
        else if(bullet->level == 2)
            bullet->setPos(x() + 56, y());
        else if(bullet->level == 3)
            bullet->setPos(x() + 47, y());
    }
}
