#include <QApplication>

#include "Loading.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create loading and show
    auto loading = new Loading();
    loading->show();

    return a.exec();
}
// memory leap is not ok
// create animated button
// loadingtime shoud be 20
// create continuebutton
// create stopview in game and savebutton and quitbutton and continuebutton
