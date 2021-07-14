#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Bullet.h"
#include "Score.h"

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT
private:
    Score * score;
public:
    // constructor
    SpaceShip(Score *score, QGraphicsItem *parent = nullptr);

    //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SPACESHIP_H
