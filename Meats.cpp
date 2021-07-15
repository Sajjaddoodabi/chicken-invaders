#include "Meats.h"
#include <QFont>

Meats::Meats(Score * score, QGraphicsItem *parent)
    : QGraphicsTextItem (parent) , playerMeat{0}, score{score}
{
    // changing playerScore to text and printing
    setPlainText(QString::number(playerMeat));

    // setting text's color
    setDefaultTextColor(Qt::white);

    // setting text's font
    setFont(QFont("times", 20));
}

void Meats::addToMeat(int meat)
{
    // adding to score
    playerMeat += meat;

    // printing
    setPlainText(QString::number(playerMeat));

    if (playerMeat >= 30){
        playerMeat -= 30;
        score->addToScore(50);
    }
}
