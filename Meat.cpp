#include "Meat.h"

Meat::Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
           , QGraphicsItem *parent)
      : QObject () , QGraphicsPixmapItem (parent) ,
        meatScene(meatScene) , meatScore(meatScore) ,countMeat{0} , timeIntervals{0}
{

    //set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    //add to scene
    meatScene->addItem(this);
    setPos(20 , 50);  //ToDO

    //connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));
}

void Meat::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    countMeat++;
    if(countMeat == 30){
        countMeat = 0;
        meatScore->addToScore(50);
    }

    meatScene->removeItem(this);
    delete this;
}
