#include "SaveBotton.h"

// constructor
SaveBotton::SaveBotton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(47, 938);

    // creating media
    buttonMedia = new QMediaPlayer();
}
