#include "Bullet.h"
#include <QGraphicsScene>
#include <QList>
#include "Babychichken.h"
#include "Controller.h"

// constructor
Bullet::Bullet(Score  *score, QGraphicsItem *parent)
    : QObject() , QGraphicsPixmapItem(parent), score{score}
{
    // setting level
    level = 1;

    // creating and setting sound
    bulletSound = new QMediaPlayer;
    bulletSound->setMedia(QUrl("qrc:/musics/bullet/bulletsound.wav"));

    // playing sound
    bulletSound->play();

    // setting picture
    setPixmap(QPixmap(":/images/bullet/bullet1.png"));

    // creating bulletTimer
    bulletTimer = new QTimer();

    // connecting to movetoup and starting
    connect(bulletTimer, SIGNAL(timeout()), this, SLOT(moveToUp()));
    bulletTimer->start(50);
}

// destructor
Bullet::~Bullet()
{
    // deleting pointer
    delete bulletSound;
    delete bulletTimer;
}

// adding level and setting picture
void Bullet::addLevel()
{
    // adding level
    ++level;

    // setting picture
    if(level == 2)
        setPixmap(QPixmap(":/images/bullet/bullet2.png"));
    else if(level == 3)
        setPixmap(QPixmap(":/images/bullet/bullet3.png"));
}

// lowwing-off level and setting picture
void Bullet::lowOffLevel()
{
    // lowwing-off level
    --level;

    // setting picture
    if(level == 2)
        setPixmap(QPixmap(":/images/bullet/bullet2.png"));
    else if(level == 1)
        setPixmap(QPixmap(":/images/bullet/bullet1.png"));
}

// moving bullet to up
void Bullet::moveToUp()
{
    // collecting all colliding objects in a list
    QList<QGraphicsItem *> collidingList = collidingItems();

    for(size_t i{0} ; i < collidingList.size() ; ++i){
        if(typeid (*(collidingList[i])) == typeid (BabyChicken)){
            dynamic_cast<BabyChicken *>(collidingList[i])->HealthDecrement();

            score->addToScore(5);

            scene()->removeItem(this);
            delete this;
            return;
        }
     }

    // moving to up
    setPos(x(), y() - 27);

    // deleting bullet
    if(y() <= -27){
        scene()->removeItem(this);
        delete this;
    }
}
