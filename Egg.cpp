#include "Egg.h"
#include <QGraphicsScene>

Egg::Egg(Score *score, QGraphicsItem *parent) : QObject()
  , QGraphicsPixmapItem (parent), score{score}

{
    // setting picture
    setPixmap(QPixmap(":/images/egg1.png"));

    // creating bulletTimer
    eggTimer = new QTimer();

    // connecting to movetoup and starting
    connect(eggTimer, SIGNAL(timeout()), this, SLOT(move()));
    eggTimer->start(200);

    time = 0;
}

Egg::~Egg()
{
    delete eggTimer;
}

void Egg::HealthDecrement()
{
    score->addToScore(5);

    // removing at scene
    scene()->removeItem(this);

    // deleting BabyChicken
    delete this;
}

void Egg::move()
{
    // moving to up
    setPos(x(), y() + 27);

    // deleting bullet
    if(y() >= 1065){
        setPos(x(), 1065);
        setPixmap(QPixmap(":/images/egg2.png"));
        ++time;
    }

    if (time == 6){
        scene()->removeItem(this);
        delete this;
    }
}
