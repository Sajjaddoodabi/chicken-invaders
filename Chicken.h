#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Chicken :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    // private members
    int Health;
    int speedPerPix;
    bool isLord;
    QMediaPlayer *chickenSound;
    
public:
    bool gameOver;
    // constructor
    Chicken(int speedPerPix, QTimer *timer , QGraphicsItem *parent , int Health , bool isLord);
    
    // destructor
    ~Chicken();

    void HeathDecrement();
    
public slots:
    // move to mid
    void move(); //ToDO
};

#endif // CHICKEN_H
