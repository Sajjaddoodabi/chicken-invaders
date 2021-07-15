#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QMediaPlayer>

class Score : public QGraphicsTextItem
{
    private:
    // private members
    int playerScore;
    int chickenkilled;
    int a;
    QMediaPlayer *scorePlayer;

public:
    // constructor
    explicit Score(QGraphicsItem *parent = 0);
    ~Score();

    QMediaPlayer *getScorePlayer();

    // adding to score function
    void addToScore(int score);

    int getChickenKilled();
    void addTokills(int i);
};

#endif // SCORE_H
