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
    mMedia = new QMediaPlayer();

    // setting music to mMedia
    mMedia->setMedia(QUrl("qrc:/musics/menu/"));

    // playing music
    mMedia->play();

    // creating mTimer
    mTimer = new QTimer();

    // connecting mTimer to schedule
    connect(mTimer , SIGNAL(timeout()) , this , SLOT(schedule()));

    // starting lTimer
    mTimer->start(1000);

    //creat next level button
    nextlevelButton = new NextLevelBotton(Scene);

    //creat main menu button
    mainmenuBotton = new MainMenuBotton(Scene);

    //creat save button
    saveButton = new SaveBotton(Scene);

}

void AfterLevel::schedule()
{

}
