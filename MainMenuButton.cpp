#include "MainMenuButton.h"

//contructor
MainMenuButton::MainMenuButton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(100, 100); //ToDO

    // creating media
    buttonMedia = new QMediaPlayer();
}

//destructor
MainMenuButton::~MainMenuButton()
{
    delete buttonMedia;
    delete buttonScene;
}

//mouse event
void MainMenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(755, 618);

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();
}
