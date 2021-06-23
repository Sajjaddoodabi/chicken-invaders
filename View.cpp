#include "View.h"

View::View() : QGraphicsView()
{
    //create scnen
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 1400, 1000);
    setScene(scene);
}
