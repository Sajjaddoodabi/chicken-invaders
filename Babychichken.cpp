#include "Babychichken.h"
#include <QGraphicsScene>

// constructor
BabyChicken::BabyChicken(Score *score, int *countBabyChicken , int x, int y, QGraphicsItem *parent)
    : QObject(), QGraphicsPixmapItem(parent), a{x}, b{y}, countBabyChicken{countBabyChicken}, score{score}
{
    // setting picture
    setPixmap(QPixmap(":/images/chickens/babychicken1.png"));

    // creating babyTimer
    babyTimer = new QTimer();

    // connecting timer to move
    connect(babyTimer, SIGNAL(timeout()), this, SLOT(move()));

    // connecting babyTimer to movetopos and starting
    connect(babyTimer, SIGNAL(timeout()), this, SLOT(moveToPos()));
    babyTimer->start(100);

    //intializing time
    time = 0;
}

// destructor
BabyChicken::~BabyChicken()
{
    // deleting pointer
    delete babyTimer;
}

// deleting BabyChicken
void BabyChicken::HealthDecrement()
{
    score->addToScore(5);
    score->addTokills(1);

    *countBabyChicken -= 1;
    // removing at scene
    scene()->removeItem(this);

    // deleting BabyChicken
    delete this;
}

// animating
void BabyChicken::move()
{
    // adding one to time
    ++time;

    // animating
    if(time % 8 == 2){
        setPixmap(QPixmap(":/images/chickens/babychicken2.png"));
        setPos(x()+5,y());
    } else if(time % 8 == 4){
        setPixmap(QPixmap(":/images/chickens/babychicken1.png"));
        setPos(x(),y()+5);
    } else if(time % 8 == 6){
        setPixmap(QPixmap(":/images/chickens/babychicken2.png"));
        setPos(x()-5,y());
    } else if(time % 8 == 0){
        setPixmap(QPixmap(":/images/chickens/babychicken1.png"));
        setPos(x(),y()-5);
        time = 0;
    }
}

// moving
void BabyChicken::moveToPos()
{
    // moving
    if (x() - a <= 27 && a - x( ) <= 27 && x() != 0)
        setPos(a, y());
    else if (x() < a)
        setPos(x()+27, y());
    else if (x() > a)
        setPos(x()-27, y());
    if (b - y() <= 27 && y() != 0)
        setPos(x(), b);
    else if (y() > b)
        setPos(x(), y()-27);
    else if (y() < b)
        setPos(x(), y()+27);
}
