#include "mainwindow.h"
#include <QApplication>

#include <QtWidgets/qwidget.h>

int main(int argc, char *argv[])
{
    // Start MATLAB MAIN.m
    /*QProcess* myProcess = new QProcess( this );
    myProcess->start( QString( "C:/Program Files/MATLAB/R2014b/bin/matlab.exe" ),
              QStringList() << QString( "-r C:/Users/avila_000/Google Drive/GitHub/TG1/MatLab/CodigoTG3/lecturaCSV_V3.m" )
                            << QString( "-nosplash" ) );*/

    QApplication a(argc, argv);
    MainWindow window;

    window.show();

    return a.exec();
}
