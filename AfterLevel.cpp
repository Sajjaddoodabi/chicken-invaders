#include "AfterLevel.h"

AfterLevel::AfterLevel() : QGraphicsView()
{
    // creating scene
    Scene = new QGraphicsScene();
    Scene->setSceneRect(0, 0, 1920, 1080);

    // adding scene
    setScene(Scene);

    // fullscreening the game window
    setWindowState(Qt::WindowFullScreen);

    // deleting scrollbars
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // adding background
    setBackgroundBrush(QBrush(QImage(":/images/menu/")));

    // creating mMedia
    Media = new QMediaPlayer();

    // setting music to mMedia
    Media->setMedia(QUrl("qrc:/musics/menu/"));

    // playing music
    Media->play();

    // creating mTimer
    Timer = new QTimer();

    // connecting mTimer to schedule
    connect(Timer , SIGNAL(timeout()) , this , SLOT(schedule()));

    // starting lTimer
    Timer->start(1000);

    //creat next level button
    nextlevelButton = new NextLevelBotton(Scene);

    //creat main menu button
    mainmenuBotton = new MainMenuBotton(Scene);

    //creat save button
    saveButton = new SaveBotton(Scene);

}

AfterLevel::~AfterLevel()
{
    delete Scene;
    delete Media;
    delete Timer;
    delete nextlevelButton;
    delete mainmenuBotton;
    delete saveButton;
    delete view;
}

void AfterLevel::schedule()
{

}
