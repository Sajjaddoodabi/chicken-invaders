#ifndef CHICKEN_H
#define CHICKEN_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QMediaPlayer>

class Chicken : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Health;
    int speedPerPix;
    bool isLord;
    QMediaPlayer *chickenSound;
public:
    bool gameOver;

    Chicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent , int Health , bool isLord);

public slots:
    void move();


};

#endif // CHICKEN_H
