#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QGraphicsItem>

class SpaceShip
{
private:
    int Lives;
    int bulletLevel;

public:
    SpaceShip(int Lives , int bulletLevel , QTimer *timer , QGraphicsItem *parent);
};

#endif // SPACESHIP_H
