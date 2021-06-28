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
    menuController->timer->start(100);
    connect(menuController->timer , SIGNAL(timeout()) , this , SLOT(schedule()));

    // create newgamebutton
    newGameButton = new NewGameButton(menuController->scene);
}

// destructor
Menu::~Menu()
{
    delete menuController;
    delete newGameButton;
}

void Menu::schedule()
{
    if(menuController->media->state() == QMediaPlayer::StoppedState )
                menuController->media->play();

    if(newGameButton->click == 1){
        menuController->timer->stop();
        menuController->media->stop();
        menuController->media->setMedia(QUrl("qrc:/musics/menu/click.mp3"));
        menuController->media->play();
        this->close();
    }
}

