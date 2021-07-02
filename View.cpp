#include "View.h"

// constructor
View::View() : QGraphicsView()
{
    // creat controller
    viewController = new Controller;

    // add scnen
    setScene(viewController->scene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));

    // initialize viewTime to zero
    viewTime = 0;

    // create timer
    QObject::connect(viewController->timer, SIGNAL(timeout()), this, SLOT(animatedBackground()));
    viewController->timer->start(60);

    // add music
    viewController->media = new QMediaPlayer();
    viewController->media->setMedia(QUrl("qrc:/musics/game/music.mp3"));
    viewController->media->play();

    // add scoreboard
    viewController->scoreBoard = new QGraphicsPixmapItem;
    viewController->scoreBoard->setPixmap(QPixmap(":/images/scoreboard.png"));
    viewController->scene->addItem(viewController->scoreBoard);
    viewController->scoreBoard->setPos(0, 0);

    //add score
    viewController->controllerScore = new Score();
    viewController->scene->addItem(viewController->controllerScore);
    viewController->controllerScore->setPos(30, 0);

    // add liveboard
    viewController->liveBoard = new QGraphicsPixmapItem;
    viewController->liveBoard->setPixmap(QPixmap(":/images/liveboard.png"));
    viewController->scene->addItem(viewController->liveBoard);
    viewController->liveBoard->setPos(0, 1020);

    // add lives
    viewController->controllerLives = new Lives();
    viewController->scene->addItem(viewController->controllerLives);
    viewController->controllerLives->setPos(45, 1035);

    // add spaceship
    viewController->scene->addItem(viewController->spaceShip);
    viewController->spaceShip->setPos(885, 890);

    // hide mouse pointer
    setCursor(Qt::BlankCursor);
}

// destructor
View::~View()
{
    delete viewController;
}

// show animated background
void View::animatedBackground()
{
    // add one to viewtime
    ++viewTime;

    // change background's images
    if(viewTime % 11 == 1)
        setBackgroundBrush(QBrush(QImage(":/images/game/space2.jpg")));
    else if(viewTime % 11 == 2)
        setBackgroundBrush(QBrush(QImage(":/images/game/space3.jpg")));
    else if(viewTime % 11 == 3)
        setBackgroundBrush(QBrush(QImage(":/images/game/space4.jpg")));
    else if(viewTime % 11 == 4)
        setBackgroundBrush(QBrush(QImage(":/images/game/space5.jpg")));
    else if(viewTime % 11 == 5)
        setBackgroundBrush(QBrush(QImage(":/images/game/space6.jpg")));
    else if(viewTime % 11 == 6)
        setBackgroundBrush(QBrush(QImage(":/images/game/space7.jpg")));
    else if(viewTime % 11 == 7)
        setBackgroundBrush(QBrush(QImage(":/images/game/space8.jpg")));
    else if(viewTime % 11 == 8)
        setBackgroundBrush(QBrush(QImage(":/images/game/space9.jpg")));
    else if(viewTime % 11 == 9)
        setBackgroundBrush(QBrush(QImage(":/images/game/space10.jpg")));
    else if(viewTime % 11 == 10)
        setBackgroundBrush(QBrush(QImage(":/images/game/space11.jpg")));
    else if(viewTime % 11 == 0)
        setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));
}
