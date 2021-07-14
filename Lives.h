#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>

class Lives : public QGraphicsTextItem
{
private:
    // private members
    int playerLives;

public:
    bool gameOver;
    // constructor
    explicit Lives(QGraphicsItem *parent = 0);

    // lowwing-off live function
    void lowOffLive();

    bool isOver();
};

#endif // LIVES_H
