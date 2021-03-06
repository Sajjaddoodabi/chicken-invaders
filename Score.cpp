#include "Score.h"
#include <QFont>

// constructor
Score::Score(QGraphicsItem *parent)
    : QGraphicsTextItem (parent) , playerScore{0}
{
    // changing playerScore to text and printing
    setPlainText(QString::number(playerScore));

    // setting text's color
    setDefaultTextColor(Qt::white);

    // setting text's font
    setFont(QFont("times", 20));

    //media
    scorePlayer = new QMediaPlayer;
    scorePlayer->setMedia(QUrl("qrc:/musics/")); //ToDo

    chickenkilled = 0;
}

Score::~Score()
{
    delete scorePlayer;
}

QMediaPlayer *Score::getScorePlayer()
{
    return scorePlayer;
}

// adding to score function
void Score::addToScore(int score)
{
    // adding to score
    playerScore += score;

    // printing
    setPlainText(QString::number(playerScore));
}

int Score::getChickenKilled()
{
    return chickenkilled;
}

void Score::addTokills(int i)
{
    chickenkilled += i;
}
