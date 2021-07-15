#include "Chicken.h"
#include <QGraphicsScene>
#include "Egg.h"
#include "Meat.h"

Chicken::Chicken(Score *score, int *countChicken, int x, int y, bool isLord, QGraphicsItem *parent) :
    QObject() , QGraphicsPixmapItem(parent) , a{x}, b{y}, countChicken{countChicken}, score{score}
{
    this->isLord = isLord;

    //setiing the chicken's pic
    if(!isLord){
        setPixmap(QPixmap(":/images/chickens/chicken1.png"));
        Health = 2;
    }

    //setting the Lord's pic
    else{
        setPixmap(QPixmap(":/image/"));
        Health = 4;
    }



    // creating babyTimer
    chickenTimer = new QTimer();

    // connecting timer to move
    connect(chickenTimer, SIGNAL(timeout()), this, SLOT(move()));

    // connecting babyTimer to movetopos and starting
    connect(chickenTimer, SIGNAL(timeout()), this, SLOT(moveToPos()));
    chickenTimer->start(100);

    //intializing time
    time = 0;

}

Chicken::~Chicken()
{
    delete chickenTimer;
}

void Chicken::HealthDecrement()
{
    if(Health != 0)
        --Health;
    if(Health == 0){
        auto meat = new Meat();
        scene()->addItem(meat);
        meat->setPos(x() + 45, y() + 125);
        score->addToScore(10);
        *countChicken -= 1;
        score->addTokills(1);
        qInfo() << score->getChickenKilled();

        scene()->removeItem(this);
        delete this;
    }
}

void Chicken::addEgg()
{
    auto egg = new Egg(score);
    scene()->addItem(egg);
    egg->setPos(x() + 60, y() + 125);
}

void Chicken::move()
{
    // adding one to time
    ++time;

    if (!isLord){
        // animating
        if(time % 8 == 2){
            setPixmap(QPixmap(":/images/chickens/chicken2.png"));
            setPos(x()+5,y());
        } else if(time % 8 == 4){
            setPixmap(QPixmap(":/images/chickens/chicken1.png"));
            setPos(x(),y()+5);
        } else if(time % 8 == 6){
            setPixmap(QPixmap(":/images/chickens/chicken2.png"));
            setPos(x()-5,y());
        } else if(time % 8 == 0){
            setPixmap(QPixmap(":/images/chickens/chicken1.png"));
            setPos(x(),y()-5);
            time = 0;
        }
    }
}

// moving
void Chicken::moveToPos()
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
