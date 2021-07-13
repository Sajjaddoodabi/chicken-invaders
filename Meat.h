#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Score.h"
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QMediaPlayer>

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

    void mousePressEvent(QGraphicsSceneMouseEvent *event);

public slots:
    // move down
    void move();
};

#endif // MEAT_H
