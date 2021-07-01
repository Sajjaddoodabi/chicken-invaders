#include "Controller.h"

// constructor
Controller::Controller(QObject *parent) : QObject(parent)
{
    // create scene
    scene = new QGraphicsScene;
    scene->setSceneRect(0, 0, 1920, 1080);

    // create timer of the game
    timer = new QTimer;
    timer->start(); // to do

    // create holder
    holder = new QGraphicsRectItem;
    holder->setRect(0, 0, 1920, 1080);

    //create and start ctimer
    timer = new QTimer();
    timer->start(40);

    //add scoreBoard
    scoreBoard = new QGraphicsPixmapItem();
    scoreBoard->setPixmap(QPixmap(":/images/")); //ToDO
    scene->addItem(scoreBoard);
    //scoreBoard->setPos(0,0);

    //add score
    controllerScore = new Score();
    scene->addItem(controllerScore);
   //controllerScore->setPos(50,100);
}

// destructor
Controller::~Controller()
{
    delete timer;
    delete scene;
    delete holder;
}

void Controller::addChicken(int speed)
{
    ChickenList.push_back(new Chicken{speed , timer , holder});
    scene->addItem(ChickenList.last());
    ChickenList.last()->setPos(0 , 0);
}

void Controller::addMeat()
{
MeatList.push_back(new Meat{scene,controllerScore,timer,holder});
}
