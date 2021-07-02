#include "Loading.h"

// constructor
Loading::Loading() : QGraphicsView()
{
    // creat controller
    loadingController = new Controller;

    // add scnen
    setScene(loadingController->scene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/loading/background1.jpg")));

    //create loading music
    loadingController->media = new QMediaPlayer();
    loadingController->media->setMedia(QUrl("qrc:/musics/loading/music.mp3"));
    loadingController->media->play();

    // initialize viewTime to zero
    loadingTime = 0;

    // create timer
    QObject::connect(loadingController->cTimer, SIGNAL(timeout()), this, SLOT(animatedBackground()));
    loadingController->cTimer->start(1000);
}

// destructor
Loading::~Loading(){
    delete loadingController;
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
        loadingController->cTimer->stop();
        loadingController->media->stop();
        this->close();
        menu = new Menu();
        menu->show();
    }
}
