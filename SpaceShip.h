#ifndef SPACESHIP_H
#define SPACESHIP_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QKeyEvent>
#include <QTimer>

class SpaceShip : public QGraphicsPixmapItem
{
private:
    int Lives;
    int bulletLevel;

public:
    SpaceShip(int Lives , int bulletLevel , QTimer *timer , QGraphicsItem *parent);

    void keyPressEvent(QKeyEvent * event);

};

#endif // SPACESHIP_H
