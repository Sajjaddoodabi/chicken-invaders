#ifndef MEAT_H
#define MEAT_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "Score.h"
#include <QTimer>
#include <QGraphicsScene>

class Meat : public QObject , public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    QTimer * meatTimer;
    Score * meatScore;
    int time;

public:
    // constructor
    Meat(Score *score, QGraphicsItem *parent = nullptr);

    // destructor
    ~Meat();

public slots:
    // move down
    void move();
};

#endif // MEAT_H
