#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Score.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>

class Meat : public QObject , public QGraphicsPixmapItem
{
private:
    QGraphicsScene *meatScene;
    Score *meatScore;
    int timeIntervals;
public:
    //constructor
    Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
         , QGraphicsItem *parent = nullptr);

};

#endif // MEAT_H
