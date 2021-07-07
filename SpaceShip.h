#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QMouseEvent>
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
};

#endif // SPACESHIP_H
