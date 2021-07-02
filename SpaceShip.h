#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members

public:
    // constructor
    SpaceShip(QTimer *timer , QGraphicsItem *parent);
};

#endif // SPACESHIP_H
