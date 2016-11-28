#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QDateTime>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>

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
    int contador;
    char letra;
    void reiniciar();

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

    BCIData bciData;

private slots:
    void update();
    void iniciar();
    void parar();
    void intencion();
    void realtimeDataSlot();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer dataTimer;


};

#endif // MAINWINDOW_H
