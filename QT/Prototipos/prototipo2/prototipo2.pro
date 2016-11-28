#-------------------------------------------------
#
# Project created by QtCreator 2016-11-01T10:30:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prototipo1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    includes/bcidata.cpp

HEADERS  += mainwindow.h \
    includes/bcidata.h \
    includes/Iedk.h \
    includes/IedkErrorCode.h \
    includes/IEmoStateDLL.h \
    includes/FacialExpressionDetection.h \
    includes/MentalCommandDetection.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:unix: LIBS += -L$$PWD/lib/ -ledk

DISTFILES += \
    lib/edk.lib \
    lib/glut32.lib \
    lib/edk.dll \
    lib/edk_utils.dll \
    lib/glut32.dll \
    lib/glut64.dll \
    lib/README.txt
