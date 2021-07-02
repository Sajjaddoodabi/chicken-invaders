#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
  : QGraphicsTextItem (parent) , playerScore{0}
{
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::white);
    setFont(QFont("times", 20));
}

// add to score function
void Score::addToScore(int score)
{
    // add to score
    playerScore += score;

    // print
    setPlainText(QString::number(playerScore));
}
