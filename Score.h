#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score : public QGraphicsTextItem
{
private:
    // private members
    int playerScore;

public:
    // constructor
    explicit Score(QGraphicsItem *parent = 0);

    // add to score function
    void addToScore(int score);
};

#endif // SCORE_H
