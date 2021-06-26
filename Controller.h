#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Chicken.h>

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // add class view to friend
    friend class View;

private:
    // private members
    QGraphicsScene * scene;
    QTimer * cTimer;
    QGraphicsRectItem * holder;
    //list of our enemyes
    QList<Chicken *> ChickenList;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();
};

#endif // CONTROLLER_H
