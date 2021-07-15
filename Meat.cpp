#include "Meat.h"

// constructor
Meat::Meat(Score *score, QGraphicsItem *parent)
    : QObject () , QGraphicsPixmapItem (parent), meatScore{score}
{
    // set meat picture
    setPixmap(QPixmap(":/images/meat.png"));

    // creating bulletTimer
    meatTimer = new QTimer();

    // connecting to movetoup and starting
    connect(meatTimer, SIGNAL(timeout()), this, SLOT(move()));
    meatTimer->start(50);

    time = 0;
}

Meat::~Meat()
{
    delete meatTimer;
}

void Meat::move()
{
    // moving to up
    setPos(x(), y() + 27);

    // deleting bullet
    if(y() >= 1080){
        scene()->removeItem(this);
        delete this;
    }
}
