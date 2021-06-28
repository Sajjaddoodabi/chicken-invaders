#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Health;
    int speedPerPix;
    bool isLord;
public:
    Chicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent);

signals:

};

#endif // CHICKEN_H
