#include "Bullet.h"
#include <QGraphicsScene>

// constructor
Bullet::Bullet(QGraphicsItem *parent, QTimer *bulletTimer, QMediaPlayer *bulletSound, int x, int y)
    : QObject(), QGraphicsPixmapItem(parent), x{x}, y{y}
{
    // set level
    level = 0;

    // set sound
    bulletSound->setMedia(QUrl("qrc:/musics/bullet/bulletsound.wav"));

    // set picture
    setPixmap(QPixmap(":/images/bullet/bullet1.png"));
    setPos(x+4, y);
}
