#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Bullet.h"

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

public:
    // constructor
    SpaceShip(QGraphicsItem *parent = nullptr);

    //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SPACESHIP_H
