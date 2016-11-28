//Autor: Gabriel Ávila
//Año: 2016
//Este programa utiliza las funciones de las librerías de Emotiv con el fin de
//adquirir la información cruda, de cada uno de los diferentes sensores,
//para su posterior entrenamiento y clasificación.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <time.h>
#include <fstream>
#include <vector>
#include <deque>

EE_DataChannel_t targetChannelList[] = {
        ED_COUNTER,
        ED_AF3, ED_F7, ED_F3, ED_FC5, ED_T7,
        ED_P7, ED_O1, ED_O2, ED_P8, ED_T8,
        ED_FC6, ED_F4, ED_F8, ED_AF4, ED_GYROX, ED_GYROY, ED_TIMESTAMP,
        ED_FUNC_ID, ED_FUNC_VALUE, ED_MARKER, ED_SYNC_SIGNAL
    };

const char header[] = "TIME, ED_COUNTER, AF3, F7, F3, FC5, T7, P7, O1, O2, P8, T8, FC6, F4, F8, AF4, LABEL";

std::ofstream ofs;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //CREACIÓN DE ARCHIVO DE LECTURA, SEGÚN FECHA.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    std::string nombreArchivo;
    std::stringstream ss;

    ss << tm.tm_year + 1900;
    if(tm.tm_mon < 10)
        ss << "0";
    ss << tm.tm_mon + 1;
    if(tm.tm_mday < 10)
        ss << "0";
    ss << tm.tm_mday << "_";
    if(tm.tm_hour < 10)
        ss << "0";
    ss << tm.tm_hour;
    if(tm.tm_min == 0)
        ss << "0";
    if(tm.tm_min < 10)
        ss << "0";
    ss << tm.tm_min;

    nombreArchivo = "Lectura" + ss.str() + ".csv";
    ofs.open(nombreArchivo, std::ios::trunc);

    //SETUP DE LA UI
    ui->setupUi(this);
    setGeometry(400, 250, 542, 390);
    //setGeometry(400, 250, 542, 390);

    setupRealtimeData(ui->customPlot);

    setWindowTitle("Captura ICC - Tiempo Real");
    statusBar()->clearMessage();

    //Configuración del Emotiv
    eEvent			= EE_EmoEngineEventCreate();
    eState			= EE_EmoStateCreate();
    userID          = 0;
    composerPort	= 1726;
    secs			= 1;
    datarate		= 0;
    readytocollect	= false;
    option			= 0;
    state			= 0;

    if (EE_EngineConnect() != EDK_OK) {
        throw std::runtime_error("Error iniciando Emotiv.");
    }

    hData = EE_DataCreate();
    EE_DataSetBufferSizeInSec(secs);

    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    ofs.close();
    delete ui;
}

void MainWindow::setupRealtimeData(QCustomPlot *customPlot)
{
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  QMessageBox::critical(this, "", "You're using Qt < 4.7, the realtime data demo needs functions that are available with Qt 4.7 to work properly");
#endif

  customPlot->addGraph(); // Púrpura
  customPlot->graph(0)->setPen(QPen("#DE17DA"));
  customPlot->addGraph(); // Amarillo
  customPlot->graph(1)->setPen(QPen("#FFCA1B"));
  customPlot->addGraph(); // Rojo
  customPlot->graph(2)->setPen(QPen("#FF2423"));
  customPlot->addGraph(); // Color?
  customPlot->graph(3)->setPen(QPen("#13F2B3"));
  customPlot->addGraph(); // Color?
  customPlot->graph(4)->setPen(QPen("#189BFF"));
  customPlot->addGraph(); // Color?
  customPlot->graph(5)->setPen(QPen("#18FF89"));
  customPlot->addGraph(); // Color?
  customPlot->graph(6)->setPen(QPen("#FF9B89"));
  customPlot->addGraph(); // Color?
  customPlot->graph(7)->setPen(QPen("#13FF23"));
  customPlot->addGraph(); // Color?
  customPlot->graph(8)->setPen(QPen("#1324FF"));
  customPlot->addGraph(); // Color?
  customPlot->graph(9)->setPen(QPen("#18FFB3"));
  customPlot->addGraph(); // Color?
  customPlot->graph(10)->setPen(QPen("#189BFF"));
  customPlot->addGraph(); // Color?
  customPlot->graph(11)->setPen(QPen("#FF2389"));
  customPlot->addGraph(); // Color?
  customPlot->graph(12)->setPen(QPen("#23FF89"));
  customPlot->addGraph(); // Color?
  customPlot->graph(13)->setPen(QPen("#899BFF"));
  customPlot->addGraph(); // Color?
  customPlot->graph(14)->setPen(QPen("#189BFF"));

  customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
  customPlot->xAxis->setDateTimeFormat("hh:mm:ss");
  customPlot->xAxis->setAutoTickStep(false);
  customPlot->xAxis->setTickStep(4);
  customPlot->axisRect()->setupFullAxesBox();

  // make left and bottom axes transfer their ranges to right and top axes:
  connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
  dataTimer.start(0); // Interval 0 means to refresh as fast as possible

}

void MainWindow::realtimeDataSlot()
{
  // calculate two new data points:
#if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
  double key = 0;
#else
  double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
#endif
  static double lastPointKey = 0;

  float emoEngagement = 0;
  float emoFrustration = 0;
  float emoMeditation = 0;
  float emoExcitement = 0;
  float emoSmile = 0;

  if (key-lastPointKey > 0.01) // at most add point every 10 ms
  {
    state = EE_EngineGetNextEvent(eEvent);

    if (state == EDK_OK)
    {
      EE_Event_t eventType = EE_EmoEngineEventGetType(eEvent);
      EE_EmoEngineEventGetUserId(eEvent, &userID);
      EE_EmoEngineEventGetEmoState(eEvent, eState);

      // Log the EmoState if it has been updated
      if (eventType == EE_UserAdded)
      {
        std::cout << "User added";
        EE_DataAcquisitionEnable(userID,true);
        readytocollect = true;
      }
    }

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    if (readytocollect)
    {
      EE_DataUpdateHandle(0, hData);

      unsigned int nSamplesTaken=0;
      EE_DataGetNumberOfSample(hData,&nSamplesTaken);

      std::cout << "Updated " << nSamplesTaken << std::endl;

      //Lectura de datos
      if (nSamplesTaken != 0)
      {
        double* data = new double[nSamplesTaken];        
        for (int sampleIdx=0 ; sampleIdx<(int)nSamplesTaken ; ++ sampleIdx)
        {
          for (int i = 0 ; i<15 ; i++)
          {
            EE_DataGet(hData, targetChannelList[i], data, nSamplesTaken);

            if(ui->BT_grabar->isChecked())
            {
                ofs << data[sampleIdx] << ",";
                std::cout << data[sampleIdx] << ",";
            }

            //Tomado de:
            //https://github.com/codehunks/emotiv/blob/master/Tic-Tac-Toe/main.cpp
            emoEngagement = ES_AffectivGetEngagementBoredomScore(eState);
            emoFrustration = ES_AffectivGetFrustrationScore(eState);
            emoMeditation = ES_AffectivGetMeditationScore(eState);
            emoExcitement = ES_AffectivGetExcitementShortTermScore(eState);
            emoSmile = ES_AffectivGetValenceScore(eState);

            //std::cout << emoEngagement << ", " << emoFrustration << ", " << emoMeditation << ", " << emoExcitement << ", " << emoSmile << endl;

            bciData.setData(i, data[sampleIdx]);

            switch(i)
            {
                case 0: if(ui->ED_COUNTER->isChecked()) {
                        ui->customPlot->graph(0)->addData(key, bciData.getData(i)); }
                        break;
                case 1: if(ui->ED_AF3->isChecked()) {
                        ui->customPlot->graph(1)->addData(key, bciData.getData(i)); }
                        break;
                case 2: if(ui->ED_F7->isChecked()) {
                        ui->customPlot->graph(2)->addData(key, bciData.getData(i)); }
                        break;
                case 3: if(ui->ED_F3->isChecked()) {
                        ui->customPlot->graph(3)->addData(key, bciData.getData(i)); }
                        break;
                case 4: if(ui->ED_FC5->isChecked()) {
                        ui->customPlot->graph(4)->addData(key, bciData.getData(i)); }
                        break;
                case 5: if(ui->ED_T7->isChecked()) {
                        ui->customPlot->graph(5)->addData(key, bciData.getData(i)); }
                        break;
                case 6: if(ui->ED_P7->isChecked()) {
                        ui->customPlot->graph(6)->addData(key, bciData.getData(i)); }
                        break;
                case 7: if(ui->ED_O1->isChecked()) {
                        ui->customPlot->graph(7)->addData(key, bciData.getData(i)); }
                        break;
                case 8: if(ui->ED_O2->isChecked()) {
                        ui->customPlot->graph(8)->addData(key, bciData.getData(i)); }
                        break;
                case 9: if(ui->ED_P8->isChecked()) {
                        ui->customPlot->graph(9)->addData(key, bciData.getData(i)); }
                        break;
                case 10:if(ui->ED_T8->isChecked()) {
                        ui->customPlot->graph(10)->addData(key, bciData.getData(i)); }
                        break;
                case 11:if(ui->ED_FC6->isChecked()) {
                        ui->customPlot->graph(11)->addData(key, bciData.getData(i)); }
                        break;
                case 12:if(ui->ED_F4->isChecked()) {
                        ui->customPlot->graph(12)->addData(key, bciData.getData(i)); }
                        break;
                case 13:if(ui->ED_F8->isChecked()) {
                        ui->customPlot->graph(13)->addData(key, bciData.getData(i)); }
                        break;
                case 14:if(ui->ED_AF4->isChecked()) {
                        ui->customPlot->graph(14)->addData(key, bciData.getData(i)); }
                        break;
            }
          }
          if(ui->BT_grabar->isChecked())
          {
          if(ui->LB_Caso1->isChecked())
              ofs << "1";
          else if(ui->LB_Caso2->isChecked())
              ofs << "2";
          else if(ui->LB_Caso3->isChecked())
              ofs << "3";
          else if(ui->LB_Caso4->isChecked())
              ofs << "4";
          else if(ui->LB_Caso5->isChecked())
              ofs << "5";
          else
              ofs << "0";
          ofs << std::endl;
          std::cout << std::endl;
          }
          bciData.addToBuffer(bciData.getCurrentData());
        }

        delete[] data;
      }      
      //EE_DataFree(hData);
    }    

    for(int gp = 0; gp < 15; ++gp)
    {
        // add data to lines:
        ui->customPlot->graph(gp)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->customPlot->graph(gp)->rescaleValueAxis(true);
    }

    lastPointKey = key;
  }

  // make key axis range scroll with the data (at a constant range size of 8):
  ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
  ui->customPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    ui->statusBar->showMessage(
          QString("Estado: %1 %2")
          .arg(state)
          .arg(ui->customPlot->graph(0)->data()->count()+ui->customPlot->graph(1)->data()->count())
          , 0);
    lastFpsKey = key;
    frameCount = 0;
  }
}
