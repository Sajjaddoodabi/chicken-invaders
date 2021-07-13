#include "Egg.h"

Egg::Egg(QGraphicsScene *EggScene, QTimer *timer, QGraphicsItem *parent) : QObject()
  , QGraphicsPixmapItem (parent) , EggScene(EggScene)

{
    // set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    //scene
    EggScene = new QGraphicsScene;
    EggScene->addItem(this);
    setPos(20 , 50);  //ToDO


}
