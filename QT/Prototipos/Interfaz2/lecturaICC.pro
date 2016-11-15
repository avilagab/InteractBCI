#-------------------------------------------------
#
# Project created by QtCreator 2015-08-27T14:13:07
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PruebaQt01
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
        qcustomplot.cpp \
        bcidata.cpp

HEADERS  += mainwindow.h \
        qcustomplot.h \
        edk.h \
        edkErrorCode.h \
        elsClient.h \
        EmoStateDLL.h \
        DspFilters/Bessel.h \
    DspFilters/Biquad.h \
    DspFilters/Butterworth.h \
    DspFilters/Cascade.h \
    DspFilters/ChebyshevI.h \
    DspFilters/ChebyshevII.h \
    DspFilters/Common.h \
    DspFilters/Custom.h \
    DspFilters/Design.h \
    DspFilters/Dsp.h \
    DspFilters/Elliptic.h \
    DspFilters/Filter.h \
    DspFilters/Layout.h \
    DspFilters/Legendre.h \
    DspFilters/MathSupplement.h \
    DspFilters/Params.h \
    DspFilters/PoleFilter.h \
    DspFilters/RBJ.h \
    DspFilters/RootFinder.h \
    DspFilters/SmoothedFilter.h \
    DspFilters/State.h \
    DspFilters/Types.h \
    DspFilters/Utilities.h \
    ui_mainwindow.h \
    bcidata.h

FORMS    += mainwindow.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/lib/ -ledk
else:unix: LIBS += -L$$PWD/lib/ -ledk

INCLUDEPATH += $$PWD/
DEPENDPATH += $$PWD/

DISTFILES += \
    debug/PruebaQt01.ilk \
    debug/PruebaQt01.pdb \
    lib/edk.lib \
    lib/glut32.lib \
    debug/PruebaQt01.exe \
    lib/edk.dll \
    lib/edk_utils.dll \
    lib/glut32.dll \
    lib/glut64.dll \
    DatosGabriel.zip \
    DatosSantiago.zip \
    Lectura20160919_1133.txt \
    Lectura20160919_1143.txt \
    Lectura20160919_1155.txt \
    Lectura20160919_1156.txt \
    Lectura20160919_1157.txt \
    Lectura20160919_1158_Gabriel_Relajado.txt \
    Lectura20160919_1200_Gabriel_Cuerpo.txt \
    Lectura20160919_1202_Gabriel_Enfocado.txt \
    Lectura20160919_1206_Gabriel_Parpadeo.txt \
    Lectura20160919_1209_Gabriel_Cabeza.txt \
    Lectura20160919_1211_Gabriel_Ojos.txt \
    Lectura20160919_1222_Santiago_Relajado.txt \
    Lectura20160919_1224_Santiago_Cuerpo.txt \
    Lectura20160919_1226_Santiago_Enfocado.txt \
    Lectura20160919_1228_Santiago_Parpadeo.txt \
    Lectura20160919_1230_Santiago_Cabeza.txt \
    Lectura20160919_1232_Santiago_Ojos.txt \
    Lectura20160928_1505.txt \
    Lectura20160928_1512.txt \
    Lectura20160928_1519.txt \
    Lectura20160928_1523.txt
