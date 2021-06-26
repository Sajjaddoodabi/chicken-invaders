#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // add friend classes
    friend class View;
    friend class Menu;

private:
    // private members
    QGraphicsScene * scene;
    QTimer * cTimer;
    QGraphicsRectItem * holder;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

};

#endif // CONTROLLER_H
