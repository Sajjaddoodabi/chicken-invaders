#ifndef MEATS_H
#define MEATS_H

#include <QGraphicsTextItem>
#include "Score.h"

class Meats : public QGraphicsTextItem
{
private:
    // private members
    int playerMeat;
    Score * score;
public:
    explicit Meats(Score * score, QGraphicsItem *parent = 0);
    void addToMeat(int meat);
};

#endif // MEATS_H
