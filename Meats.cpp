#include "Meats.h"
#include <QFont>

Meats::Meats(Score *score, QGraphicsItem *parent)
    : QGraphicsTextItem (parent) , playerMeats{0}, score{score}
  {
      // changing playerScore to text and printing
      setPlainText(QString::number(playerMeats));

      // setting text's color
      setDefaultTextColor(Qt::white);

      // setting text's font
      setFont(QFont("times", 20));
}

void Meats::addMeat(int meat)
{
    // adding to score
    playerMeats += meat;

    // printing
    setPlainText(QString::number(playerMeats));

    if (playerMeats >= 30){
        playerMeats -= 30;
        score->addToScore(50);
    }
}
