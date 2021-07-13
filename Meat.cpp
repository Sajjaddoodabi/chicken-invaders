#include "Meat.h"

// constructor
Meat::Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
           , QGraphicsItem *parent)
      : QObject () , QGraphicsPixmapItem (parent) ,
        meatScene(meatScene) , meatScore(meatScore) ,countMeat{0} , timeIntervals{0}
{
    // set meat picture
    setPixmap(QPixmap(":/images/invadres.png")); //ToDO

    // add to scene
    meatScene->addItem(this);
    setPos(20 , 50);  //ToDO

    //creating timer
    timer = new QTimer;

    // connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

    //start the timer
    timer->start();//ToDO

    countMeat = 0;
}

Meat::~Meat()
{
    delete meatScene;
    delete meatScore;
}

void Meat::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
     countMeat++;

    meatScore->getScorePlayer()->play();

    meatScene->removeItem(this);
    delete this;

    if(countMeat == 30){
        meatScore->addToScore(50);
        countMeat = 0;
    }
}

void Meat::move()
{
   ++timeIntervals;
    setPos(x() , y()+6);

    if(x() > 1080)
    {
        meatScene->removeItem(this);
        delete this;
    }
}
