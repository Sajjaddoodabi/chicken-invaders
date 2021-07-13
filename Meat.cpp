#include "Meat.h"

// constructor
Meat::Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
           , QGraphicsItem *parent)
      : QObject () , QGraphicsPixmapItem (parent) ,
        meatScene(meatScene) , meatScore(meatScore) ,countMeat{0} , timeIntervals{0}
{
    // set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    // add to scene
    meatScene->addItem(this);
    setPos(20 , 50);  //ToDO

    //creating timer
    timer = new QTimer;

    // connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));

    //start the timer
    timer->start();//ToDO
}

Meat::~Meat()
{
    delete meatScene;
    delete meatScore;
}

void Meat::move()
{
   ++timeIntervals;
    setPos(x() , y()+6);

    //if(//ToDO)
    {
        meatScene->removeItem(this);
        delete this;
    }
}
