#include "View.h"
#include <QList>
#include "Babychichken.h"
#include "Menu.h"
#include "Egg.h"
#include "Gift.h"


// constructor
View::View() : QGraphicsView(), level{0}
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

    // connecting vTimer to schedule
    connect(vTimer, SIGNAL(timeout()), this, SLOT(schedule()));

    // starting vTimer
    vTimer->start(50);

    // creating vMedia
    vMedia = new QMediaPlayer();

    // adding music to vMedia
    vMedia->setMedia(QUrl("qrc:/musics/game/music.mp3"));

    // playing music
    vMedia->play();

    //gameover music
    gameOverMusic = new QMediaPlayer();
    gameOverMusic->setMedia(QUrl("qrc:/musics/GO.mp3"));

    //win music
    winMusic = new QMediaPlayer();
    winMusic->setMedia(QUrl("qrc:/musics/VIC.mp3"));

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

    ExitTime = 0;
}

// destructor
View::~View()
{
    // deleting pointer
    delete vController;
    delete vMedia;
    delete vTimer;
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    if (vTimer->isActive())
        vController->spaceShip->setPos(event->x()-75, event->y()-90);
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

            dynamic_cast<BabyChicken *>(spaceShipCollidingList[i])->HealthDecrement();

            deathMedia->stop();
            deathMedia->play();

            vController->controllerLives->lowOffLive();

            vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/death.png"));

            deathTimer->start(500);
        }else if(typeid (*(spaceShipCollidingList[i])) == typeid (Egg) && !(deathTimer->isActive())){

            dynamic_cast<Egg *>(spaceShipCollidingList[i])->HealthDecrement();

            deathMedia->stop();
            deathMedia->play();

            vController->controllerLives->lowOffLive();

            vController->spaceShip->setPixmap(QPixmap(":/images/spaceship/death.png"));

            deathTimer->start(500);
        }else if(typeid (*(spaceShipCollidingList[i])) == typeid (Meat)){
        scene()->removeItem(dynamic_cast<Meat *>(spaceShipCollidingList[i]));
        delete dynamic_cast<Meat *>(spaceShipCollidingList[i]);

        vController->controllerMeats->addToMeat(1);
    }else if(typeid (*(spaceShipCollidingList[i])) == typeid (Gift)){
        scene()->removeItem(dynamic_cast<Gift *>(spaceShipCollidingList[i]));
        delete dynamic_cast<Gift *>(spaceShipCollidingList[i]);

//        vController->bullet->increaseLevel();
    }
  }

    if(vController->controllerScore->getChickenKilled() == 155){
        ExitTime++;
                vMedia->stop();
                winMusic->play();

                auto gameover = new QGraphicsTextItem();
                gameover->setPlainText("V I C T O R Y");
                gameover->setDefaultTextColor(Qt::white);
                gameover->setFont(QFont("times", 100));
                vController->scene->addItem(gameover);
                gameover->setPos(500,400);


<<<<<<< HEAD
                if(ExitTime == 5)
                    exit(0);
=======
        ExitTime++;
        vMedia->stop();
        winMusic->play();

        auto gameover = new QGraphicsTextItem();
        gameover->setPlainText("VICTORY");
        gameover->setDefaultTextColor(Qt::white);
        gameover->setFont(QFont("times", 100));
        vController->scene->addItem(gameover);
        gameover->setPos(500,400);


        if(ExitTime == 5)
            exit(0);

>>>>>>> 669e41dd8299472d85cd057a6b50689cdd0cce4f
    }else if(vController->controllerScore->getChickenKilled() >= 128){
        if(vTime == 112)
            vTime = 101;

        if (vTime%11==0 && level==4){
            vTime = 0;
            ++level;
        }

        // adding babychicken
        if(vTime == 80)
            for (int i = 0; i < 9 ; ++i)
                vController->addChicken(1000+vTime, 0, 285+(i*150), 160, true);
        else if(vTime == 90)
            for (int i = 0; i < 9 ; ++i)
                vController->addChicken(1000+vTime, 0, 285+(i*150), 285, true);
        else if(vTime == 100)
            for (int i = 0; i < 9 ; ++i)
                vController->addChicken(1000+vTime, 0, 285+(i*150), 410, true);

    }else if(vController->controllerScore->getChickenKilled() >= 110){
        if(vTime == 312)
            vTime = 301;

        if (vTime == 300){
                auto gift = new Gift();
                scene()->addItem(gift);
                gift->setPos(500, 0);
        }

        if (vTime%11==0 && level==3){
            vTime = 0;
            ++level;
        }

        // adding babychicken
        if(vTime == 80)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1000+vTime, 0, 435+(i*300), 160, true);
        else if(vTime == 90)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1000+vTime, 0, 435+(i*300), 285, true);
        else if(vTime == 100)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1000+vTime, 0, 435+(i*300), 410, true);

        // adding chicken
        if(vTime == 80)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1500+vTime, 0, 285+(i*300), 160, false);
        else if(vTime == 90)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1500+vTime, 0, 285+(i*300), 285, false);
        else if(vTime == 100)
            for (int i = 0; i < 3 ; ++i)
                vController->addChicken(1500+vTime, 0, 285+(i*300), 410, false);
    }else if(vController->controllerScore->getChickenKilled() >= 80){
        if(vTime == 112)
            vTime = 101;

        if (vTime%11==0 && level==2){
            vTime = 0;
            ++level;
        }

        // adding babychicken
        if(vTime == 80)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1000+vTime, 0, 285+(i*450), 160);
        else if(vTime == 90)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1000+vTime, 0, 285+(i*450), 285);
        else if(vTime == 100)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1000+vTime, 0, 285+(i*450), 410);

        // adding chicken
        if(vTime == 80)
            for (int i = 0; i < 3 ; ++i){
                vController->addChicken(1500+vTime, 0, 435+(i*450), 160, false);
                vController->addChicken(1500+vTime, 0, 585+(i*450), 160, false);
        }else if(vTime == 90)
            for (int i = 0; i < 3 ; ++i){
                vController->addChicken(1500+vTime, 0, 435+(i*450), 285, false);
                vController->addChicken(1500+vTime, 0, 585+(i*450), 285, false);
        }else if(vTime == 100)
            for (int i = 0; i < 3 ; ++i){
                vController->addChicken(1500+vTime, 0, 435+(i*450), 410, false);
                vController->addChicken(1500+vTime, 0, 585+(i*450), 410, false);
            }
    }else if(vController->controllerScore->getChickenKilled() >= 56){
        if(vTime == 112)
            vTime = 101;

        if (vTime%11==0 && level==1){
            vTime = 0;
            ++level;
        }

        // adding babychicken
        if(vTime == 80)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+(i*300), 160);
        else if(vTime == 90)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+(i*300), 285);
        else if(vTime == 100)
            for (int i = 0; i < 4 ; ++i)
                vController->addBabyChicken(1500+vTime, 0, 285+(i*300), 410);

        // adding chicken
        if(vTime == 80)
            for (int i = 0; i < 4 ; ++i)
                vController->addChicken(1500+vTime, 0, 435+(i*300), 160, false);
        else if(vTime == 90)
            for (int i = 0; i < 4 ; ++i)
                vController->addChicken(1500+vTime, 0, 435+(i*300), 285, false);
        else if(vTime == 100)
            for (int i = 0; i < 4 ; ++i)
                vController->addChicken(1500+vTime, 0, 435+(i*300), 410, false);

    }else if(vController->controllerScore->getChickenKilled() >= 20){
        if(vTime == 122)
            vTime = 111;

        if (vTime%11==0 && level==0){
            vTime = 0;
            ++level;
        }
            // adding babychicken
            if(vTime == 80)
                for (int i = 0; i < 9 ; ++i)
                    vController->addBabyChicken(1500+vTime, 0, 285+((i)*150), 160);
            else if(vTime == 90)
                for (int i = 9; i < 18 ; ++i)
                    vController->addBabyChicken(1500+vTime, 0, 285+((i-9)*150), 285);
            else if(vTime == 100)
                for (int i = 18; i < 27 ; ++i)
                    vController->addBabyChicken(1500+vTime, 0, 285+((i-18)*150), 410);
            else if(vTime == 110)
                for (int i = 27; i < 36 ; ++i)
                    vController->addBabyChicken(1500+vTime, 0, 285+((i-27)*150), 535);


        }else if(vController->controllerScore->getChickenKilled() >= 0){
            // adding babychicken
            if(vTime == 80)
                for (int i = 0; i < 5 ; ++i)
                    vController->addBabyChicken(500, 0, 585+((i)*150), 160);
            else if(vTime == 90)
                for (int i = 5; i < 10 ; ++i)
                    vController->addBabyChicken(500, 0, 585+((i-5)*150), 285);
            else if(vTime == 100)
                for (int i = 10; i < 15 ; ++i)
                    vController->addBabyChicken(500, 0, 585+((i-10)*150), 410);
            else if(vTime == 110)
                for (int i = 15; i < 20 ; ++i)
                    vController->addBabyChicken(500, 0, 585+((i-15)*150), 535);

            if(vTime == 122)
                vTime = 111;
        }

    // game over scene
    if(vController->controllerLives->isOver()){
        ExitTime++;

<<<<<<< HEAD
                 vTimer->stop();
                 vMedia->stop();
                 gameOverMusic->play();

                 auto gameover = new QGraphicsTextItem();
                 gameover->setPlainText("G A M E  O V E R");
                 gameover->setDefaultTextColor(Qt::white);
                 gameover->setFont(QFont("times", 100));
                 vController->scene->addItem(gameover);
                 gameover->setPos(500,400);

                 if(ExitTime == 5)
                     exit(0);

=======
         vTimer->stop();
         vMedia->stop();
         gameOverMusic->play();

         auto gameover = new QGraphicsTextItem();
         gameover->setPlainText("GAME OVER");
         gameover->setDefaultTextColor(Qt::white);
         gameover->setFont(QFont("times", 100));
         vController->scene->addItem(gameover);
         gameover->setPos(500,400);

         if(ExitTime == 5)
             exit(0);



>>>>>>> 669e41dd8299472d85cd057a6b50689cdd0cce4f
    }
}
