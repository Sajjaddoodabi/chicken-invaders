#include "MainMenuBotton.h"

MainMenuBotton::MainMenuBotton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/"));
}
