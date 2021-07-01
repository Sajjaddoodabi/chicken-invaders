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
    menuController->cTimer = new QTimer();
    menuController->cTimer->start(10);
    connect(menuController->cTimer , SIGNAL(timeout()) , this , SLOT(schedule()));

    // create newgamebutton
    newGameButton = new NewGameButton(menuController->scene);

    // create quitbutton
    quitButton = new QuitButton(menuController->scene);
}

// destructor
Menu::~Menu()
{
    delete menuController;
    delete newGameButton;
}

// restart music and change view
void Menu::schedule()
{
    // restart music
    if(menuController->media->state() == QMediaPlayer::StoppedState )
                menuController->media->play();

    // change view
    if(newGameButton->click == 1 || quitButton->click == 1){
        menuController->cTimer->stop();
        menuController->media->stop();
        menuController->media->setMedia(QUrl("qrc:/musics/menu/click.mp3"));
        menuController->media->play();
        this->close();
    }
}

