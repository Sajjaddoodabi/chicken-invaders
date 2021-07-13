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
    int time;
    QMediaPlayer *BabyChickenSound;

public:
    bool gameOver;
    BabyChicken(QTimer *timer , QGraphicsItem *parent);
    ~BabyChicken();

    void HealthDecrement();

public slots:
    // move
    void move(); //ToDO
};

#endif // BABYCHICKEN_H


