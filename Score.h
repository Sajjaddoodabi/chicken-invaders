#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
private:
    // private members
    int playerScore;

public:
    // constructor
    explicit Score(QGraphicsItem *parent = 0);

    // adding to score function
    void addToScore(int score);
};

#endif // SCORE_H
