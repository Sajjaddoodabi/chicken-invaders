#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include "Controller.h"

class View : public QGraphicsView
{
    // macro
    Q_OBJECT

private:
    //members class
    Controller * viewController;
    double viewTime;

public:
    // constructor
    explicit View();

    // destructor
    ~View();

public slots:
    void background();

};

#endif // VIEW_H
