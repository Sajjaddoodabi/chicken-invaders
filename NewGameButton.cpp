#include "NewGameButton.h"

// constructor
NewGameButton::NewGameButton(QGraphicsScene *scene) :  QGraphicsPixmapItem(), buttonScene{scene}, click{0}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/newgamebutton.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(665, 603);

    // creating media
    buttonMedia = new QMediaPlayer();
}

// destructor
NewGameButton::~NewGameButton()
{
    // deleting pointers
    delete buttonScene;
}

// muuse event (click)
void NewGameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/newgamebutton2.jpg"));

    // adding to scene
    buttonScene->addItem(this);
    setPos(755, 618);

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();
}
