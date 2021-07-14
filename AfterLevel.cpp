#include "AfterLevel.h"

AfterLevel::AfterLevel(int season , int level) : QGraphicsView() , level{1} , season{1}
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
    nextlevelButton = new NextLevelButton(Scene , season , level);

    //creat main menu button
    mainmenuButton = new MainMenuButton(Scene);

    //creat save button
    saveButton = new SaveButton(Scene);
}

AfterLevel::~AfterLevel()
{
    delete Scene;
    delete Media;
    delete Timer;
    delete nextlevelButton;
    delete mainmenuButton;
    delete saveButton;
    delete view;
}

void AfterLevel::schedule()
{
    // restarting music
    if(Media->state() == QMediaPlayer::StoppedState )
        Media->play();

    //change window
    if(mainmenuButton->click == 1){
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
