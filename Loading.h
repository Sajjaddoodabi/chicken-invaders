#ifndef LOADING_H
#define LOADING_H

#include <QGraphicsView>
#include "Menu.h"

class Loading : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    // private members
    QGraphicsScene * lScene;
    QMediaPlayer * lMedia;
    QTimer * lTimer;
    int loadingTime;
    Menu * menu;

public:
    // constructor
    explicit Loading();

    // destructor
    ~Loading();

public slots:
    // showing animated background
    void animatedBackground();
};

#endif // LOADING_H
