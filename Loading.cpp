#include "Loading.h"

// constructor
Loading::Loading() : QGraphicsView()
{
    // creating scene
    lScene = new QGraphicsScene();
    lScene->setSceneRect(0, 0, 1920, 1080);

    // adding scene
    setScene(lScene);

    // fullscreening the game window
    setWindowState(Qt::WindowFullScreen);

    // deleting scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/loading/background1.jpg")));

    // creating lMedia
    lMedia = new QMediaPlayer();

    // setting music to lMedia
    lMedia->setMedia(QUrl("qrc:/musics/loading/music.mp3"));

    // playing music
    lMedia->play();

    // initializing loadingTime to zero
    loadingTime = 0;

    // creating lTimer
    lTimer = new QTimer();

    // connecting lTimer to animatedBackground
    QObject::connect(lTimer, SIGNAL(timeout()), this, SLOT(animatedBackground()));

    // starting lTimer
    lTimer->start(1000);
}

// destructor
Loading::~Loading(){
    // deleting pointers
    delete lScene;
    delete lMedia;
    delete lTimer;
    delete menu;
}

// showing animated background
void Loading::animatedBackground()
{
    // adding one to loadingtime
    ++loadingTime;

    // changing background's images
    if(loadingTime % 4 == 1)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background2.jpg")));
    else if(loadingTime % 4 == 2)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background3.jpg")));
    else if(loadingTime % 4 == 3)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background4.jpg")));
    else if(loadingTime % 4 == 0)
        setBackgroundBrush(QBrush(QImage(":/images/loading/background1.jpg")));

    // changing to menu
    if(loadingTime == 2){// change to 20
        // stopping ltimer and music
        lTimer->stop();
        lMedia->stop();

        // closing loading's window
        this->close();

        // creating menu
        menu = new Menu();

        // showing menu's window
        menu->show();
    }
}
