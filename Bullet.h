#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

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

public:
    // constructor
    explicit Bullet(QGraphicsItem *parent = nullptr);

    // destructor
    ~Bullet();

    // adding level and setting picture
    void addLevel();

    // lowwing-off level and setting picture
    void lowOffLevel();

    void increaseLevel();

public slots:
    // moving bullet to up
    void moveToUp();
};

#endif // BULLET_H
