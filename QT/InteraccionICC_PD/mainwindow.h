#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTimer>
#include <qcustomplot.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>
#include <time.h>

//Data Structures
#include <vector>
#include <deque>

#include "includes/IEmoStateDLL.h"
#include "includes/Iedk.h"
#include "includes/IedkErrorCode.h"
#include "includes/bcidata.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setupRealtimeData(QCustomPlot *customPlot);

    int contador;
    int contadorParpadeo;
    int seleccion;
    int clase;
    int derIzqRnd;
    string tipo;
    string fecha;
    bool action;

    //Variables necesarias para el funcionamiento del Emotiv
    EmoEngineEventHandle eEvent;
    EmoStateHandle eState;
    unsigned int userID;
    unsigned int engineUserID;
    unsigned short composerPort;
    float secs;
    unsigned int datarate;
    bool readytocollect;
    int option;
    int state;
    bool ready;    
    DataHandle hData;
    bool epochSaved;
    //Variables necesarias para verificar nivel de señal y batería
    bool onStateChanged;
    bool isStateOk;
    IEE_SignalStrength_t wirelessStrength;
    int batteryLevel;
    int maxBatteryLevel;

    BCIData bciData;

    QPixmap green;
    QPixmap white;
    QPixmap left;
    QPixmap right;

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer dataTimer;

private slots:
    void realtimeDataSlot();
    void actualizar();
    void iniciar();
    void parar();
};

#endif // MAINWINDOW_H
