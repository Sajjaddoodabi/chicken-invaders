#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QTimer>

class Chicken : public QObject , QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Health;
    int speedPerPix;
public:
    Chicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent);

signals:

};

#endif // CHICKEN_H
