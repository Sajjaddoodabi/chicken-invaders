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

void SaveBotton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(755, 618);

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();
}
