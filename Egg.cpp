#include "Egg.h"

Egg::Egg(QGraphicsScene *EggScene, QTimer *timer, QGraphicsItem *parent) : QObject()
  , QGraphicsPixmapItem (parent) , EggScene(EggScene)

{
    // set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO}

}
