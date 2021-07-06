#ifndef LIVES_H
#define LIVES_H

#include <QGraphicsTextItem>

class Lives : public QGraphicsTextItem
{
private:
    // private members
    int playerLives;

public:
    // constructor
    explicit Lives(QGraphicsItem *parent = 0);

    // lowwing-off live function
    void lowOffLive();
};

#endif // LIVES_H
