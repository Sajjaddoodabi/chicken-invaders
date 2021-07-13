#include "Gift.h"

Gift::Gift(QGraphicsScene *GiftScene, QTimer *timer, QGraphicsItem *parent) : QObject() ,
       QGraphicsPixmapItem (parent) , GiftScene(GiftScene)
{
    // set meat picture
    setPixmap(QPixmap(":/images/")); //ToDO

    //scene
    GiftScene = new QGraphicsScene;
    GiftScene->addItem(this);
    setPos(20 , 50);  //ToDO
}
