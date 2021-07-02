#include "Score.h"
#include <QFont>

// constructor
Score::Score(QGraphicsItem *parent)
  : QGraphicsTextItem (parent) , playerScore{0}
{
    // change playerScore to text
    setPlainText(QString::number(playerScore));

    // set text's color
    setDefaultTextColor(Qt::white);

    // set text's font
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
