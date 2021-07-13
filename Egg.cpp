#include "Egg.h"

Egg::Egg(QGraphicsScene *EggScene, QTimer *timer, QGraphicsItem *parent) : QObject()
  , QGraphicsPixmapItem (parent) , EggScene(EggScene)

{


}
