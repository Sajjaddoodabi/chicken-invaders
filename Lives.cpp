#include "Lives.h"
#include <QFont>

// constructor
Lives::Lives(QGraphicsItem *parent)
  : QGraphicsTextItem (parent) , playerLives{3}
{
    // changing playerScore to text and printing
    setPlainText(QString::number(playerLives));

    // setting text's color
    setDefaultTextColor(Qt::white);

    // setting text's font
    setFont(QFont("times", 20));

    gameOver = false;
}

// lowwing-off live function
void Lives::lowOffLive()
{
    // lowwing-off pleyerLives
    --playerLives;

    // printing
    setPlainText(QString::number(playerLives));

}

bool Lives::isOver()
{
    if(playerLives == 0){
        gameOver = true;
    }
    return gameOver;
}
