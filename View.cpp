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
