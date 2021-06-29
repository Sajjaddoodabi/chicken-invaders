#ifndef LOADING_H
#define LOADING_H

#include <QGraphicsView>
#include "Menu.h"

class Loading : public QGraphicsView
{
    // macro
    Q_OBJECT

    // friend class
    friend class NewGameButton;

private:
    // private members
    Controller * loadingController;
    int loadingTime;
    Menu * menu;

public:
    // constructor
    explicit Loading();

    // destructor
    ~Loading();

public slots:
    // show animated background
    void animatedBackground();
};

#endif // LOADING_H
