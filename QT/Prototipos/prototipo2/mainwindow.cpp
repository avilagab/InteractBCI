#include "mainwindow.h"
#include "ui_mainwindow.h"

IEE_DataChannel_t channelList[] = {
        IED_AF3, IED_F7, IED_F3, IED_FC5, IED_T7,
        IED_P7, IED_O1, IED_O2, IED_P8, IED_T8,
        IED_FC6, IED_F4, IED_F8, IED_AF4
    };

ofstream ofs;

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    contador = 0;
    ui->setupUi(this);

    //CREACIÓN DE ARCHIVO DE LECTURA, SEGÚN FECHA.
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    string nombreArchivo;
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

    nombreArchivo = "archivos/Lectura" + ss.str() + ".csv";
    ofs.open(nombreArchivo, std::ios::trunc);

    //Creación de conexiones para detección de acciones en la GUI
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->b_inicio, SIGNAL(released()), this, SLOT(iniciar()));
    connect(ui->b_parada, SIGNAL(released()), this, SLOT(parar()));

    //Configuración del Emotiv
    eEvent			= IEE_EmoEngineEventCreate();
    eState			= IEE_EmoStateCreate();
    userID          = 0;
    engineUserID    = -1;
    composerPort	= 1726;
    secs			= 1;
    datarate		= 0;
    readytocollect	= false;
    option			= 0;
    state			= 0;
    ready           = false;

    if (IEE_EngineConnect() != EDK_OK) {
        throw std::runtime_error("Error iniciando Emotiv.");
    }

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

MainWindow::~MainWindow()
{
    IEE_EngineDisconnect();
    IEE_EmoStateFree(eState);
    IEE_EmoEngineEventFree(eEvent);



    delete ui;
}

void MainWindow::update(){
    switch (contador)
    {
        case 1: ui->label_0->setStyleSheet("background-color: orange");
                ui->label_9->setStyleSheet("background-color: lightGray"); break;
        case 2: ui->label_0->setStyleSheet("background-color: lightGray");
                ui->label_1->setStyleSheet("background-color: orange"); break;
        case 3: ui->label_1->setStyleSheet("background-color: lightGray");
                ui->label_2->setStyleSheet("background-color: orange"); break;
        case 4: ui->label_2->setStyleSheet("background-color: lightGray");
                ui->label_3->setStyleSheet("background-color: orange"); break;
        case 5: ui->label_3->setStyleSheet("background-color: lightGray");
                ui->label_4->setStyleSheet("background-color: orange"); break;
        case 6: ui->label_4->setStyleSheet("background-color: lightGray");
                ui->label_5->setStyleSheet("background-color: orange"); break;
        case 7: ui->label_5->setStyleSheet("background-color: lightGray");
                ui->label_6->setStyleSheet("background-color: orange"); break;
        case 8: ui->label_6->setStyleSheet("background-color: lightGray");
                ui->label_7->setStyleSheet("background-color: orange"); break;
        case 9: ui->label_7->setStyleSheet("background-color: lightGray");
                ui->label_8->setStyleSheet("background-color: orange"); break;
        case 10: ui->label_8->setStyleSheet("background-color: lightGray");
                 ui->label_9->setStyleSheet("background-color: orange");
                 contador = 0; break;
    }
    contador++;
}

void MainWindow::intencion(){
   QString texto = "";
    switch (contador - 1){
        case 1: texto = "0"; break;
        case 2: texto = "1"; break;
        case 3: texto = "2"; break;
        case 4: texto = "3"; break;
        case 5: texto = "4"; break;
        case 6: texto = "5"; break;
        case 7: texto = "6"; break;
        case 8: texto = "7"; break;
        case 9: texto = "8"; break;
        case 10: texto = "9"; break;
    }
    ui->statusBar->showMessage("Selección" + texto, 1000);
}

void MainWindow::iniciar(){
    timer->start(500);
}

void MainWindow::parar(){
    timer->stop();
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

  if (key-lastPointKey > 0.01) // at most add point every 10 ms
  {
    state = IEE_EngineGetNextEvent(eEvent);

    if (state == EDK_OK)
    {
      IEE_Event_t eventType = IEE_EmoEngineEventGetType(eEvent);
      IEE_EmoEngineEventGetUserId(eEvent, &userID);

      // Log the EmoState if it has been updated
      if (eventType == IEE_UserAdded) {
        std::cout << "User added" << std::endl;
        engineUserID = 0;
        IEE_FFTSetWindowingType(engineUserID, IEE_HAMMING);

        ready = true;
      }
    }

    if (ready)
    {
        double alpha, low_beta, high_beta, gamma, theta;
        alpha = low_beta = high_beta = gamma = theta = 0;
        bool escritura = false;

        for(int i=0 ; i< sizeof(channelList)/sizeof(channelList[0]) ; ++i)
        {
            int result = IEE_GetAverageBandPowers(engineUserID, channelList[i], &theta, &alpha,
                                                     &low_beta, &high_beta, &gamma);

            if(result == EDK_OK)
            {                
                cout << theta << "," << alpha << "," << low_beta << ",";
                cout << high_beta << "," << gamma;

                ofs << theta << "," << alpha << "," << low_beta << ",";
                ofs << high_beta << "," << gamma;
            }
            if(i != sizeof(channelList)/sizeof(channelList[0])-1)
            {
                cout << ",";
                ofs << ",";
            }
        }
        ofs << endl;
    }

    lastPointKey = key;
  }
}

