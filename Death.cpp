#include "Death.h"
#include <QGraphicsScene>
#include "View.h"

Death::Death()
{
    //
    dTime = 0;

    // setting picture
    setPixmap(QPixmap(":/images/spaceship/"));

    // creating dtimer
    dTimer = new QTimer();

    connect(dTimer, SIGNAL(timeout()), this, SLOT(animated()));

    dTimer->start(500);
}

void Death::animated()
{
    ++dTime;

    if (dTime == 1)
        setPixmap(QPixmap(":/images/spaceship/"));
    else if (dTime == 2)
        setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (dTime == 3)
        setPixmap(QPixmap());
    else if (dTime == 4)
        setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (dTime == 5)
        setPixmap(QPixmap());
    else if (dTime == 6)
        setPixmap(QPixmap(":/images/spaceship/image1.png"));
    else if (dTime == 7){
        scene()->removeItem(this);
        delete this;
    }
}
