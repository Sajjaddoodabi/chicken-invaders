#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Score : public QGraphicsTextItem
{
    private:
    // private members
    int playerScore;
    QMediaPlayer *scorePlayer;

public:
    // constructor
    explicit Score(QGraphicsItem *parent = 0);
    ~Score();

    QMediaPlayer *getScorePlayer();

    // adding to score function
    void addToScore(int score);
};

#endif // SCORE_H
