#ifndef BABYCHICKEN_H
#define BABYCHICKEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class BabyChicken : public QObject , public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    int time, a, b;
    int *countBabyChicken;
    QTimer * babyTimer;

public:
    bool gameOver;
    // constructor
    BabyChicken(int *countBabyChicken ,QTimer * timer, int x, int y, QGraphicsItem *parent = nullptr);

    // destructor
    ~BabyChicken();

    // deleting BabyChicken
    void HealthDecrement();

public slots:
    // animating
    void move();
    // moving
    void moveToPos();
};

#endif // BABYCHICKEN_H


