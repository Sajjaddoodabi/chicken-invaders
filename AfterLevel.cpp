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

}
