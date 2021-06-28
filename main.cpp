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
// memory leap isnot ok
// create playbutton in loading
