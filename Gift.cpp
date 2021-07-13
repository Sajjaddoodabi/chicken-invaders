#include "Gift.h"

Gift::Gift(QGraphicsScene *GiftScene, QTimer *timer, QGraphicsItem *parent) : QObject() ,
       QGraphicsPixmapItem (parent) , GiftScene(GiftScene)
{

}
