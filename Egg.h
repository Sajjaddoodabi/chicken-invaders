#ifndef EGG_H
#define EGG_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "Score.h"

class Egg : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QTimer * eggTimer;
    int time;
    Score * score;
public:
    Egg(Score *score, QGraphicsItem *parent = nullptr);
    ~Egg();

    void HealthDecrement();
public slots:
    // move down
    void move();

};

#endif // EGG_H
