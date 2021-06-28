#ifndef LOADING_H
#define LOADING_H

#include <QGraphicsView>
#include "Controller.h"
#include "Menu.h"

class Loading : public QGraphicsView
{
    // macro
    Q_OBJECT

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
