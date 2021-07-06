#include "Loading.h"

// constructor
Loading::Loading() : QGraphicsView()
{
    // create scene
    lScene = new QGraphicsScene();
    lScene->setSceneRect(0, 0, 1920, 1080);

    // add scnen
    setScene(lScene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/loading/background1.jpg")));

    //create loading music
    lMedia = new QMediaPlayer();

    // set music to lMedia
    lMedia->setMedia(QUrl("qrc:/musics/loading/music.mp3"));

    // play lMedia
    lMedia->play();

    // initialize viewTime to zero
    loadingTime = 0;

    // create timer
    lTimer = new QTimer();

    // connect to animatedBackground
    QObject::connect(lTimer, SIGNAL(timeout()), this, SLOT(animatedBackground()));

    // start timer
    lTimer->start(1000);
}

// destructor
Loading::~Loading(){
    delete lScene;
    delete lMedia;
    delete lTimer;
    delete menu;
}

// show animated background
void Loading::animatedBackground()
{
    // add one to loadingtime
    ++loadingTime;

    // change background's images
    if(loadingTime % 4 == 1)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background2.jpg")));
    else if(loadingTime % 4 == 2)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background3.jpg")));
    else if(loadingTime % 4 == 3)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background4.jpg")));
    else if(loadingTime % 4 == 0)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background1.jpg")));

    // change to menu
    if(loadingTime == 2){// change to 20
        lTimer->stop();
        lMedia->stop();
        this->close();
        menu = new Menu();
        menu->show();
    }
}
