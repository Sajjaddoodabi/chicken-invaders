#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>
#include "Score.h"

class Bullet : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

    // friend class
    friend class SpaceShip;

private:
    // private members
    int level;
    QMediaPlayer * bulletSound;
    QTimer * bulletTimer;
    Score  * score;

public:
    // constructor
    explicit Bullet(Score  *score, QGraphicsItem *parent = nullptr);

    // destructor
    ~Bullet();

    // adding level and setting picture
    void addLevel();

    // lowwing-off level and setting picture
    void lowOffLevel();

public slots:
    // moving bullet to up
    void moveToUp();
};

#endif // BULLET_H
