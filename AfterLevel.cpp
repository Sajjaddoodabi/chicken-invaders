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
    nextlevelButton = new NextLevelButton(Scene);

    //creat main menu button
    mainmenuBotton = new MainMenuButton(Scene);

    //creat save button
    saveButton = new SaveButton(Scene);

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
    // restarting music
    if(Media->state() == QMediaPlayer::StoppedState )
        Media->play();

    //change window
    if(mainmenuBotton->click == 1){
        Media->stop();
        Timer->stop();

        this->close();

        menu->getView()->show();
    }

    if(nextlevelButton->click == 1){

    }

    if(saveButton->click == 1){

    }
}
