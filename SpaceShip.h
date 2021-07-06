#ifndef SPACESHIP_H
#define SPACESHIP_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QMediaPlayer>
#include "Bullet.h"

class SpaceShip : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    QTimer * spaceShipTimer;
    QMediaPlayer * spaceShipMedia;
    Bullet * bullet;

public:
    // constructor
    SpaceShip(QTimer *spaceShipTimer, QGraphicsItem *parent = nullptr);

    // destructor
    ~SpaceShip();

    void keyPressEvent(QKeyEvent * event);
};

#endif // SPACESHIP_H
