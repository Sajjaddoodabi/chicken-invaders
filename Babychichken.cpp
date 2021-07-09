#include "Babychichken.h"
#include <QGraphicsScene>

BabyChicken::BabyChicken(int speedPerPix, QTimer *timer, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), speedPerPix{speedPerPix}
{
    // setting picture
    setPixmap(QPixmap(":/images/chickens/babychicken1.png"));

    // connecting timer to move
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    // creating BabyChickenSound
    BabyChickenSound = new QMediaPlayer();

    // adding sound
    BabyChickenSound->setMedia(QUrl("qrc:/music/"));

    // palying sound
    BabyChickenSound->play();
}

BabyChicken::~BabyChicken()
{
    delete BabyChickenSound;
}

void BabyChicken::HealthDecrement()
{
    scene()->removeItem(this);
    delete this;
}


//ToDO
void BabyChicken::move()
{

}
