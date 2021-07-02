#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Score.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

class Meat : public QObject , public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    QGraphicsScene *meatScene;
    Score *meatScore;
    int countMeat;
    int timeIntervals;

public:
    // constructor
    Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
         , QGraphicsItem *parent = nullptr);

    // destructor
    ~Meat();

    // a mouse event to get meats score
    void mousePressEvent(QGraphicsSceneMouseEvent *event); // to do

public slots:
    // move down
    void move();
};

#endif // MEAT_H
