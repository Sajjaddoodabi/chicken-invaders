#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent)
  : QGraphicsTextItem (parent) , playerScore{0}
{
    setPlainText(QString::number(playerScore));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times", 25));


}

void Score::addToScore(int score)
{
    playerScore += score;
    setPlainText(QString::number(playerScore));
}
