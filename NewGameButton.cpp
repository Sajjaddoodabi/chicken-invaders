#include "NewGameButton.h"

NewGameButton::NewGameButton() :  QGraphicsPixmapItem()
{
    // create controller
    buttonController = new Controller;

    // add music
    buttonController->media = new QMediaPlayer();
    buttonController->media->setMedia(QUrl(":qrc/musics/menu/click.mp3"));
    buttonController->media->play();
}

NewGameButton::~NewGameButton()
{
    delete buttonController;
}

void NewGameButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}
