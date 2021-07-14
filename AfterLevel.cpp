#include "AfterLevel.h"

AfterLevel::AfterLevel() : QGraphicsView()
{
    // creating scene
    Scene = new QGraphicsScene();
    Scene->setSceneRect(0, 0, 1920, 1080);

    // adding scene
    setScene(Scene);
}
