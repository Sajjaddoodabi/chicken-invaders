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

    // connect to movetoup
    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(moveToUp()));
    bulletTimer->start(25);
}

// move bullet to up
void Bullet::moveToUp()
{
    // move to up
    y -= 12;
    setPos(x, y);

    // delete bullet
    if(y == 0){
        scene()->removeItem(this);
        delete this;
    }
}
