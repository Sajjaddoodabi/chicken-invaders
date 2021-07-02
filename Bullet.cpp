#include "Bullet.h"
#include <QGraphicsScene>

// constructor
Bullet::Bullet(QGraphicsItem *parent, QTimer *bulletTimer, QMediaPlayer *bulletSound, int x, int y)
    : QObject(), QGraphicsPixmapItem(parent), x{x}, y{y}
{
    // set level
    level = 0;
}

