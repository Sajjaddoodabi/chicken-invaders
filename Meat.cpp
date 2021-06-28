#include "Meat.h"

Meat::Meat(QGraphicsScene *meatScene , Score *meatScore , QTimer *timer
           , QGraphicsItem *parent)
      : QObject () , QGraphicsPixmapItem (parent) ,
        meatScene(meatScene) , meatScore(meatScore) , timeIntervals{0}
{

    //set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    //add to scene
    meatScene->addItem(this);
   // setPos();  ToDO

    //connect timer to move
    connect(timer , SIGNAL(timeout()) , this , SLOT(move()));
}

void Meat::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
