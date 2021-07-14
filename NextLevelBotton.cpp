#include "NextLevelBotton.h"

NextLevelBotton::NextLevelBotton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/"));
}
