QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Babychichken.cpp \
    Bullet.cpp \
    Chicken.cpp \
    Controller.cpp \
    Egg.cpp \
    Gift.cpp \
    Lives.cpp \
    MainMenuButton.cpp \
    Meat.cpp \
    Meats.cpp \
    Score.cpp \
    SpaceShip.cpp \
    Loading.cpp \
    Menu.cpp \
    NewGameButton.cpp \
    QuitButton.cpp \
    View.cpp \
    main.cpp

HEADERS += \
    Babychichken.h \
    Bullet.h \
    Chicken.h \
    Controller.h \
    Egg.h \
    Gift.h \
    Lives.h \
    MainMenuButton.h \
    Meat.h \
    Meats.h \
    Score.h \
    SpaceShip.h \
    Loading.h \
    Menu.h \
    NewGameButton.h \
    QuitButton.h \
    View.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RC.qrc
