#include "Quitbutton.h"

// constructor
QuitButton::QuitButton(QGraphicsScene *scene) : QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/quitbutton.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(47, 938);

    // creating media
    buttonMedia = new QMediaPlayer();
}

// destructor
QuitButton::~QuitButton()
{
    // deleting pointers
    delete buttonScene;
    delete buttonMedia;
}

// muuse event (click)
void QuitButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/quitbutton2.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(102, 953);

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();
}
