#include "Menu.h"

// constructor
Menu::Menu() : QGraphicsView()
{
    // create controller
    menuController = new Controller;

    // add scene
    setScene(menuController->scene);

    // fullsceenig the game window
    setWindowState(Qt::WindowFullScreen);

    // delete scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/menu/background1.jpeg")));

    // add music
    menuController->media = new QMediaPlayer();
    menuController->media->setMedia(QUrl("qrc:/musics/menu/music.mp3"));
    menuController->media->play();

    // add timer
    menuController->timer = new QTimer();
    menuController->timer->start(1000);
    connect(menuController->timer , SIGNAL(timeout()) , this , SLOT(schedule()));
}

// destructor
Menu::~Menu()
{
    delete menuController;
}

void Menu::schedule()
{
    if(menuController->media->state() == QMediaPlayer::StoppedState )
                menuController->media->play();
}

