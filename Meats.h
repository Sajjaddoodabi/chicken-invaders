#ifndef MEATS_H
#define MEATS_H

#include <QGraphicsTextItem>
#include "Score.h"

class Meats : public QGraphicsTextItem
{
private:
    // private members
    int playerMeats;
    Score * score;
public:
    // constructor
    explicit Meats(Score *score, QGraphicsItem *parent = 0);

    // lowwing-off live function
    void addMeat(int meat);
};

#endif // MEATS_H
