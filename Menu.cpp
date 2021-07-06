#include "Menu.h"

// constructor
Menu::Menu() : QGraphicsView()
{
    // creating scene
    mScene = new QGraphicsScene();
    mScene->setSceneRect(0, 0, 1920, 1080);

    // adding scene
    setScene(mScene);

    // fullscreening the game window
    setWindowState(Qt::WindowFullScreen);

    // deleting scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/menu/background1.jpeg")));

    // creating mMedia
    mMedia = new QMediaPlayer();

    // setting music to mMedia
    mMedia->setMedia(QUrl("qrc:/musics/menu/music.mp3"));

    // playing music
    mMedia->play();

    // creating mTimer
    mTimer = new QTimer();

    // connecting mTimer to schedule
    connect(mTimer , SIGNAL(timeout()) , this , SLOT(schedule()));

    // starting lTimer
    mTimer->start(10);

    // creating newgamebutton
    newGameButton = new NewGameButton(mScene);

    // creating quitbutton
    quitButton = new QuitButton(mScene);
}

// destructor
Menu::~Menu()
{
    // deleting pointers
    delete mScene;
    delete mMedia;
    delete mTimer;
    delete newGameButton;
    delete quitButton;
}

// restarting music and change window
void Menu::schedule()
{
    // restarting music
    if(mMedia->state() == QMediaPlayer::StoppedState )
        mMedia->play();

    // changing window
    if(newGameButton->click == 1){

        // stopping mTimer and music
        mTimer->stop();
        mMedia->stop();

        // setting clicksound to mMedia
        mMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

        // playing clicksound
        mMedia->play();

        // closing menu's window
        this->close();
    }
}

