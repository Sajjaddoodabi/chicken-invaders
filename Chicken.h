#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Chicken : public QGraphicsPixmapItem
{
private:
    // private members
    int Health;
    int speedPerPix;
    bool isLord;

public:
    // constructor
    Chicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent);
};

#endif // CHICKEN_H
