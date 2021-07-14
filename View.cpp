#include "View.h"
#include <QList>
#include "Babychichken.h"

// constructor
View::View() : QGraphicsView()
{
    // creating controller
    vController = new Controller;

    // adding scene
    setScene(vController->scene);

    // fullscreening the game window
    setWindowState(Qt::WindowFullScreen);

    // deleting scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // setting background
    setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));

    // initializing vTime to zero
    vTime = 0;

    // creating vTimer
    vTimer = new QTimer();

    // connecting vTimer to animatedBackground
    QObject::connect(vTimer, SIGNAL(timeout()), this, SLOT(animatedBackground()));

    // starting vTimer
    vTimer->start(60);

    // creating vMedia
    vMedia = new QMediaPlayer();

    // adding music to vMedia
    vMedia->setMedia(QUrl("qrc:/musics/game/music.mp3"));

    // playing music
    vMedia->play();

    // hiding mouse pointer
    setCursor(Qt::BlankCursor);
}

// destructor
View::~View()
{
    // deleting pointer
    delete vController;
    delete vMedia;
    delete vTimer;
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    vController->spaceShip->setPos(event->x()-75, event->y()-90);

    // collecting all colliding objects in a list
    QList<QGraphicsItem *> collidingList = vController->spaceShip->collidingItems();

    for(size_t i{0} ; collidingList.size() ; i++){
        if(typeid (*(collidingList[i])) == typeid (BabyChicken)){

            vController->controllerLives->lowOffLive();
        }
     }
}

// showing animated background
void View::animatedBackground()
{
    // adding one to viewtime
    ++vTime;

    // changing background's images
    if(vTime % 11 == 1)
        setBackgroundBrush(QBrush(QImage(":/images/game/space2.jpg")));
    else if(vTime % 11 == 2)
        setBackgroundBrush(QBrush(QImage(":/images/game/space3.jpg")));
    else if(vTime % 11 == 3)
        setBackgroundBrush(QBrush(QImage(":/images/game/space4.jpg")));
    else if(vTime % 11 == 4)
        setBackgroundBrush(QBrush(QImage(":/images/game/space5.jpg")));
    else if(vTime % 11 == 5)
        setBackgroundBrush(QBrush(QImage(":/images/game/space6.jpg")));
    else if(vTime % 11 == 6)
        setBackgroundBrush(QBrush(QImage(":/images/game/space7.jpg")));
    else if(vTime % 11 == 7)
        setBackgroundBrush(QBrush(QImage(":/images/game/space8.jpg")));
    else if(vTime % 11 == 8)
        setBackgroundBrush(QBrush(QImage(":/images/game/space9.jpg")));
    else if(vTime % 11 == 9)
        setBackgroundBrush(QBrush(QImage(":/images/game/space10.jpg")));
    else if(vTime % 11 == 10)
        setBackgroundBrush(QBrush(QImage(":/images/game/space11.jpg")));
    else if(vTime % 11 == 0)
        setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));

    // adding babychicken
    if(vTime % 17 == 0 && vTime <= 85)
        vController->addBabyChicken(500+vTime, 0, 585+(((vTime/17)-1)*150), 160);
    else if(vTime % 17 == 0 && vTime <= 170)
        vController->addBabyChicken(500+vTime, 0, 585+(((vTime/17)-6)*150), 285);
    else if(vTime % 17 == 0 && vTime <= 255)
        vController->addBabyChicken(500+vTime, 0, 585+(((vTime/17)-11)*150), 410);
    else if(vTime % 17 == 0 && vTime <= 340)
        vController->addBabyChicken(500+vTime, 0, 585+(((vTime/17)-16)*150), 535);

    if(vTime == 352)
        vTime = 341;
}
