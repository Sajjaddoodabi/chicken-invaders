#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMouseEvent>

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members

public:
    // constructor
    SpaceShip(QTimer *timer , QGraphicsItem *parent);

    // move spaceship with mouse
    void move(QMouseEvent * event);
};

#endif // SPACESHIP_H
