#include "Lives.h"
#include <QFont>

// constructor
Lives::Lives(QGraphicsItem *parent)
  : QGraphicsTextItem (parent) , playerLives{3}
{
    // change playerScore to text
    setPlainText(QString::number(playerLives));

    // set text's color
    setDefaultTextColor(Qt::white);

    // set text's font
    setFont(QFont("times", 20));
}


// low-off live function
void Lives::lowOffLive()
{
    // low-off pleyerLives
    --playerLives;

    // print
    setPlainText(QString::number(playerLives));
}
