#-------------------------------------------------
#
# Project created by QtCreator 2015-08-27T14:13:07
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lecturaICC_PD
TEMPLATE = app

SOURCES += main.cpp\
        qcustomplot.cpp \
        bcidata.cpp \
        mainwindow.cpp

HEADERS  += \        
    includes/FacialExpressionDetection.h \
    includes/Iedk.h \
    includes/IedkErrorCode.h \
    includes/IEmoStateDLL.h \
    includes/MentalCommandDetection.h \
    includes/bcidata.h \
    mainwindow.h \
    qcustomplot.h \
    ui_mainwindow.h \
    ui_mainwindow.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:unix: LIBS += -L$$PWD/lib/ -ledk

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

DISTFILES += \
    debug/lecturaICC_PD.ilk \
    debug/lecturaICC_PD.pdb \
    debug/lecturaICC_PD.exe \
    lib/edk.lib \
    lib/glut32.lib \
    lib/edk.dll \
    lib/edk_utils.dll \
    lib/glut32.dll \
    lib/glut64.dll \
    lib/README.txt

RESOURCES += \
    imagenes.qrc
