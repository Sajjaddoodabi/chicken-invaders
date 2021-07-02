#ifndef LIVES_H
#define LIVES_H


#include <QGraphicsSimpleTextItem>

class Lives : public QGraphicsTextItem
{
private:
    // private members
    int playerLives;

public:
    // constructor
    explicit Lives(QGraphicsItem *parent = 0);
};

#endif // LIVES_H
