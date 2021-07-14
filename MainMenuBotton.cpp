#include "MainMenuBotton.h"

MainMenuBotton::MainMenuBotton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(0, 0); //ToDO

    // creating media
    buttonMedia = new QMediaPlayer();
}

MainMenuBotton::~MainMenuBotton()
{
    delete buttonMedia;
    delete buttonScene;
}


