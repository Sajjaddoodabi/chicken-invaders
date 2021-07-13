#include "Babychichken.h"
#include <QGraphicsScene>

BabyChicken::BabyChicken(QTimer *timer, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent)
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

    //intializing time
    time = 0;
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
    ++time;

    if(time % 6 == 0)
        setPixmap(QPixmap(":/images/chickens/babychicken2.png"));
    else if(time % 6 == 2)
        setPixmap(QPixmap(":/images/chickens/babychicken1.png"));
}
