#include <QApplication>

#include "Loading.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // creating loading and showing
    auto loading = new Loading();
    loading->show();

    return a.exec();
}
// memory leap is not ok
// loadingtime shoud be 20
// create continuebutton
// create stopview in game and savebutton and quitbutton and continuebutton
// fasele close ta show ziade
// set random in controller
// set velocity in view
// delete lists in controller
