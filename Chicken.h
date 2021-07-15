#ifndef CHICKEN_H
#define CHICKEN_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QMediaPlayer>

class Chicken : public QObject, public QGraphicsPixmapItem
{
    // macro
    Q_OBJECT

private:
    // private members
    int time, a, b, Health;
    int *countChicken;
    bool isLord;
    QTimer * chickenTimer;
    
public:
    bool gameOver;
    // constructor
    Chicken(int *countChicken, QTimer *timer, int x, int y, bool isLord, QGraphicsItem *parent = nullptr);
    
    // destructor
    ~Chicken();

    void HealthDecrement();
    
public slots:
    // move to mid
    void move(); //ToDO

    void moveToPos();
};

#endif // CHICKEN_H
