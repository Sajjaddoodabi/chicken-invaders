#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsSimpleTextItem>

class Score : public QGraphicsTextItem
{
private:
    int playerScore;
public:
    explicit Score(QGraphicsItem *parent = 0);
    void addToScore(int score);

signals:

};

#endif // SCORE_H
