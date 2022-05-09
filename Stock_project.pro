QT       += core gui
QT       += core gui charts
QT += sql
QT       += core gui sql printsupport
QT       += network
QT +=multimedia  multimediawidgets
QT += charts svg
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connexion.cpp \
    dialog.cpp \
    exporttoexcel.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    stateduact.cpp \
    stock.cpp

HEADERS += \
    arduino.h \
    connexion.h \
    dialog.h \
    exporttoexcel.h \
    mainwindow.h \
    personnel.h \
    stateduact.h \
    stock.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    stateduact.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
