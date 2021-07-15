#include "NextLevelButton.h"
#include "View.h"

//constructor
NextLevelButton::NextLevelButton(int season , int level) : QGraphicsPixmapItem()
  , click{0} , season{season} , level{level}
{
    // setting picture
    setPixmap(QPixmap(":/images/menu/newgamebutton.jpg"));

    // creating media
    buttonMedia = new QMediaPlayer();
}

//destructor
NextLevelButton::~NextLevelButton()
{
    delete buttonMedia;
}

//mouse event
void NextLevelButton::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    // changing click to 1
    click = 1;

    // setting picture
    setPixmap(QPixmap(":/images/menu/newgamebutton2.jpg"));

    // setting clicksound to mMedia
    buttonMedia->setMedia(QUrl("qrc:/musics/menu/click.mp3"));

    // playing clicksound
    buttonMedia->play();

    if(season == 1 && level == 1 ){

        auto myView = new View(1,2);
        myView->show();
    }

    if(season == 1 && level == 2 ){
        auto myView = new View(2 , 1);
        myView->show();
    }

    if(season == 2 && level == 1 ){
        auto myView = new View(2 , 2);
        myView->show();
    }

    if(season == 2 && level == 2 ){
        auto myView = new View(3 , 1);
        myView->show();
    }

    if(season == 3 && level == 1 ){
        auto myView = new View(3 , 2);
        myView->show();
    }
}

