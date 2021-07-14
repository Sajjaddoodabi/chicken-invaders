#include "View.h"
#include <QList>
#include "Babychichken.h"

// constructor
View::View(int season , int level) : QGraphicsView() ,  level{level} , season{season}
{
    // creating controller
    vController = new Controller;

    // adding scene
    setScene(vController->scene);

    // fullscreening the game window
    setWindowState(Qt::WindowFullScreen);

    // deleting scroll bar
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // setting background
    setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));

    // initializing vTime to zero
    vTime = 0;

    // creating vTimer
    vTimer = new QTimer();

    // connecting vTimer to animatedBackground
    connect(vTimer, SIGNAL(timeout()), this, SLOT(animatedBackground()));
    connect(vTimer, SIGNAL(timeout()), this, SLOT(schedule()));

    // starting vTimer
    vTimer->start(60);

    // creating vMedia
    vMedia = new QMediaPlayer();

    // adding music to vMedia
    vMedia->setMedia(QUrl("qrc:/musics/game/music.mp3"));

    // playing music
    vMedia->play();

    //gameover music
    gameOverMusic = new QMediaPlayer();
    gameOverMusic->setMedia(QUrl("qrc:/musics/game/"));

    //win music
    winMusic = new QMediaPlayer();
    winMusic->setMedia(QUrl("qrc:/musics/game/"));

    // hiding mouse pointer
    setCursor(Qt::BlankCursor);

    //
    deathTime = 0;

    //
    deathTimer = new QTimer();
    connect(deathTimer, SIGNAL(timeout()), this, SLOT(death()));

    //
    deathMedia = new QMediaPlayer();
    deathMedia->setMedia(QUrl("qrc:/musics/spaceship/deathsound.mp3"));
}

// destructor
View::~View()
{
    // deleting pointer
    delete vController;
    delete vMedia;
    delete vTimer;
}

void View::stopGame()
{
    vTimer->stop();
    vController->timer->stop();
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    if (vTimer->isActive())
        vController->spaceShip->setPos(event->x()-75, event->y()-90);
}

// showing animated background
void View::animatedBackground()
{
    // adding one to viewtime
    ++vTime;

    // changing background's images
    if(vTime % 11 == 1)
        setBackgroundBrush(QBrush(QImage(":/images/game/space2.jpg")));
    else if(vTime % 11 == 2)
        setBackgroundBrush(QBrush(QImage(":/images/game/space3.jpg")));
    else if(vTime % 11 == 3)
        setBackgroundBrush(QBrush(QImage(":/images/game/space4.jpg")));
    else if(vTime % 11 == 4)
        setBackgroundBrush(QBrush(QImage(":/images/game/space5.jpg")));
    else if(vTime % 11 == 5)
        setBackgroundBrush(QBrush(QImage(":/images/game/space6.jpg")));
    else if(vTime % 11 == 6)
        setBackgroundBrush(QBrush(QImage(":/images/game/space7.jpg")));
    else if(vTime % 11 == 7)
        setBackgroundBrush(QBrush(QImage(":/images/game/space8.jpg")));
    else if(vTime % 11 == 8)
        setBackgroundBrush(QBrush(QImage(":/images/game/space9.jpg")));
    else if(vTime % 11 == 9)
        setBackgroundBrush(QBrush(QImage(":/images/game/space10.jpg")));
    else if(vTime % 11 == 10)
        setBackgroundBrush(QBrush(QImage(":/images/game/space11.jpg")));
    else if(vTime % 11 == 0)
        setBackgroundBrush(QBrush(QImage(":/images/game/space1.jpg")));

    // collecting all colliding objects in a list
    QList<QGraphicsItem *> spaceShipCollidingList = vController->spaceShip->collidingItems();

    for(size_t i{0} ; i < spaceShipCollidingList.size() ; i++){
        if(typeid (*(spaceShipCollidingList[i])) == typeid (BabyChicken) && !(deathTimer->isActive())){

            scene()->removeItem(dynamic_cast<BabyChicken *>(spaceShipCollidingList[i]));
            delete dynamic_cast<BabyChicken *>(spaceShipCollidingList[i]);

            deathMedia->stop();
            deathMedia->play();

            vController->controllerLives->lowOffLive();

            vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/death.png"));

            deathTimer->start(500);
        }
     }
}

void View::death()
{
    ++deathTime;

    if (deathTime == 1)
        vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (deathTime == 2)
        vController->spaceShip->setPixmap(QPixmap());
    else if (deathTime == 3)
        vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (deathTime == 4)
        vController->spaceShip->setPixmap(QPixmap());
    else if (deathTime == 5)
        vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (deathTime == 6)
        vController->spaceShip->setPixmap(QPixmap());
    else if (deathTime == 7){
        vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/image1.png"));
        deathTimer->stop();
        deathTime = 0;
    }
}

void View::schedule()
{

    if(season == 1 && level == 1){
        // adding babychicken
        if(vTime % 17 == 0 && vTime <= 17)
            for (int i = 0; i < 5 ; ++i)
                vController->addBabyChicken(500+vTime, 0, 585+((i)*150), 160);
        else if(vTime % 17 == 0 && vTime <= 34)
            for (int i = 5; i < 10 ; ++i)
                vController->addBabyChicken(500+vTime, 0, 585+((i-5)*150), 285);
        else if(vTime % 17 == 0 && vTime <= 51)
            for (int i = 10; i < 15 ; ++i)
                vController->addBabyChicken(500+vTime, 0, 585+((i-10)*150), 410);
        else if(vTime % 17 == 0 && vTime <= 68)
            for (int i = 15; i < 20 ; ++i)
                vController->addBabyChicken(500+vTime, 0, 585+((i-15)*150), 535);

        if(vTime == 80)
            vTime = 69;
    }

    if(season == 1 && level == 2){
        // adding babychicken
        if(vTime % 17 == 0 && vTime <= 17)
            for (int i = 0; i < 9 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+((i)*150), 160);
        else if(vTime % 17 == 0 && vTime <= 34)
            for (int i = 9; i < 18 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+((i-5)*150), 285);
        else if(vTime % 17 == 0 && vTime <= 51)
            for (int i = 18; i < 27 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+((i-10)*150), 410);
        else if(vTime % 17 == 0 && vTime <= 68)
            for (int i = 27; i < 36 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+((i-15)*150), 535);

        if(vTime == 80)
            vTime = 69;

    }

    if(season == 2 && level == 1){}
    if(season == 2 && level == 2){}
    if(season == 3 && level == 1){}
    if(season == 3 && level == 2){}

    //game over scene
    if(vController->controllerLives->isOver()){
         stopGame();
         vMedia->stop();
         gameOverMusic->play();

         QGraphicsPixmapItem * gameover = new QGraphicsPixmapItem();
         gameover->setPixmap(QPixmap(":/images/.png"));
         vController->scene->addItem(gameover);
         gameover->setPos(0,0);

         mainmenuButton = new MainMenuButton(vController->scene);
         saveButton = new SaveButton(vController->scene);

         // showing mouse pointer
         setCursor(Qt::ArrowCursor);
    }

    //win scene
    if(*vController->countBabyChicken == 0 && vTime > 60){
         stopGame();
         vMedia->stop();
         winMusic->play();

         QGraphicsPixmapItem * win = new QGraphicsPixmapItem();
         win->setPixmap(QPixmap(":/images/.png"));
         vController->scene->addItem(win);
         win->setPos(0,0);

         nextlevelButton = new NextLevelButton(vController->scene , season , level);
         mainmenuButton = new MainMenuButton(vController->scene);
         saveButton = new SaveButton(vController->scene);

         // showing mouse pointer
         setCursor(Qt::ArrowCursor);
    }
}
