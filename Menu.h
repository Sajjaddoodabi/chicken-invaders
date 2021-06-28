#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include "View.h"

class Menu : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    Controller * menuController;

public:
    // constructor
    explicit Menu();

    // destructor
    ~Menu();

public slots:
    void schedule();

};

#endif // MENU_H
