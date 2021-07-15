#include "MainMenuButton.h"
#include "Menu.h"

//contructor
MainMenuButton::MainMenuButton() : QGraphicsPixmapItem(), click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/quitbutton.jpg"));

    // creating media
    buttonMedia = new QMediaPlayer();
}

//destructor
MainMenuButton::~MainMenuButton()
{
    delete buttonMedia;
}

//mouse event
void MainMenuButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/quitbutton2.jpg"));

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();

    auto myMenu = new Menu();
    myMenu->show();
}
