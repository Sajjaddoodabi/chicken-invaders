#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QKeyEvent>
#include "Bullet.h"

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

public:
    // constructor
    SpaceShip(QGraphicsItem *parent = nullptr);

    // keyboard's events
    void keyPressEvent(QKeyEvent * event);

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SPACESHIP_H
