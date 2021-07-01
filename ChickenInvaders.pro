QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Chicken.cpp \
    Controller.cpp \
    Meat.cpp \
    Score.cpp \
    SpaceShip.cpp \
    Loading.cpp \
    Menu.cpp \
    NewGameButton.cpp \
    QuitButton.cpp \
    View.cpp \
    main.cpp

HEADERS += \
    Chicken.h \
    Controller.h \
    Meat.h \
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
    rs.qrc

FORMS +=
