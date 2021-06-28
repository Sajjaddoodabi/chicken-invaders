#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsRectItem>
#include <QMediaPlayer>

class Controller : public QObject
{
    // macro
    Q_OBJECT

    // add friend classes
    friend class Loading;
    friend class Menu;
    friend class View;
    friend class NewGameButton;

private:
    // private members
    QGraphicsScene * scene;
    QTimer * timer;
    QGraphicsRectItem * holder;
    QMediaPlayer * media;

public:
    // constructor
    explicit Controller(QObject *parent = nullptr);

    // destructor
    ~Controller();

};

#endif // CONTROLLER_H
