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
    int Health;
    int speedPerPix;
    QMediaPlayer *BabyChickenSound;

public:
    bool gameOver;
    BabyChicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent , int Health);
    ~BabyChicken();

    void HealthDecrement();

public slots:
    // move
    void move(); //ToDO
};

#endif // BABYCHICKEN_H
