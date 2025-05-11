QT       += core gui
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game.cpp \
    loseend.cpp \
    main.cpp \
    more.cpp \
    mypushbutton.cpp \
    set.cpp \
    shadewindow.cpp \
    startwindow.cpp \
    winend.cpp \
    winend2.cpp \
    winend3.cpp \
    winend4.cpp \
    winend5.cpp

HEADERS += \
    game.h \
    loseend.h \
    more.h \
    mypushbutton.h \
    set.h \
    shadewindow.h \
    startwindow.h \
    winend.h \
    winend2.h \
    winend3.h \
    winend4.h \
    winend5.h

FORMS += \
    game.ui \
    loseend.ui \
    startwindow.ui \
    winend.ui \
    winend2.ui \
    winend3.ui \
    winend4.ui \
    winend5.ui

TRANSLATIONS +=
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
