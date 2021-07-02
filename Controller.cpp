#include "Controller.h"

// constructor
Controller::Controller(QObject *parent) : QObject(parent)
{
    // create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1920, 1080);

    // create timer of the game
    cTimer = new QTimer;
    cTimer->start(); // to do

    // create holder
    holder = new QGraphicsRectItem;
    holder->setRect(0, 0, 1920, 1080);

    //create and start ctimer
    timer = new QTimer();
    timer->start(40);

}

// destructor
Controller::~Controller()
{
    delete cTimer;
    delete scene;
    delete holder;
}

void Controller::addChicken(int speed , int Health , bool isLord)
{
    ChickenList.push_back(new Chicken{speed , timer , holder , Health , isLord});
    scene->addItem(ChickenList.last());
    ChickenList.last()->setPos(0 , 0);
}

void Controller::addMeat()
{
MeatList.push_back(new Meat{scene,controllerScore,timer,holder});
}
