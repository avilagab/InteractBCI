#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <qcustomplot.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <stdio.h>

//Data Structures
#include <vector>
#include <deque>

#include "EmoStateDLL.h"
#include "edk.h"
#include "edkErrorCode.h"
#include "bcidata.h"

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

    EmoEngineEventHandle eEvent;
    EmoStateHandle eState;
    unsigned int userID;
    unsigned short composerPort;
    float secs;
    unsigned int datarate;
    bool readytocollect;
    int option;
    int state;
    DataHandle hData;

    BCIData bciData;

private:
    Ui::MainWindow *ui;
    QTimer dataTimer;

private slots:
    void realtimeDataSlot();
};

#endif // MAINWINDOW_H
