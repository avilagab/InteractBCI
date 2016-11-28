//Autor: Gabriel Ávila
//Año: 2016
//Este programa utiliza las funciones de las librerías de Emotiv con el fin de
//adquirir la información de la potencia en las 5 bandas, para su posterior entrenamiento y
//clasificación.

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
    seleccion = 5;
    contadorParpadeo = 0;
    clase = 0;
    action = false;

    ui->setupUi(this);
    ui->btParar->setVisible(false);
    ui->iconParpadeo_1->setVisible(false);
    ui->iconParpadeo_2->setVisible(false);
    ui->iconParpadeo_3->setVisible(false);
    ui->iconParpadeo_4->setVisible(false);
    ui->iconParpadeo_5->setVisible(false);

    QImage *greenImg    = new QImage(":/imagenes/green.png");
    QImage *whiteImg    = new QImage(":/imagenes/white.png");
    QImage *leftImg     = new QImage(":/imagenes/Left.png");
    QImage *rightImg    = new QImage(":/imagenes/Right.png");

    green   = QPixmap::fromImage(*greenImg, 0);
    white   = QPixmap::fromImage(*whiteImg, 0);
    left    = QPixmap::fromImage(*leftImg, 0);
    right   = QPixmap::fromImage(*rightImg, 0);

    //Información de fecha para archivo nuevo
    QDateTime fechaCompleta;
    fechaCompleta = QDateTime::currentDateTime();
    ui->fecha->setDateTime(fechaCompleta);

    //Creación de conexiones para detección de acciones en la GUI
    timer = new QTimer(this);   
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));

    connect(ui->btIniciar, SIGNAL(released()), this, SLOT(iniciar()));
    connect(ui->btParar, SIGNAL(released()), this, SLOT(parar()));


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
    onStateChanged  = false;
    ready           = false;
    batteryLevel    = 0;
    maxBatteryLevel = 0;
    isStateOk       = false;
    epochSaved      = false;

    if (IEE_EngineConnect() != EDK_OK) {
        throw std::runtime_error("Error iniciando Emotiv.");
    }

    timer->start(100);

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

MainWindow::~MainWindow(){
    IEE_EngineDisconnect();
    IEE_EmoStateFree(eState);
    IEE_EmoEngineEventFree(eEvent);

    ofs.close();

    delete ui;
}

void MainWindow::actualizar(){
    contador++;
    epochSaved = false;
    ui->label_contador->setText(QString::number(contador));

    switch (seleccion)
    {
        case 0:
            ui->lbExplicacion->setText("Cuando el ícono esté en verde intente relajarse, trate de no parpadear ni moverse.");
            if(contador%50==0)
                action = !action;
            if(action){
                ui->iconParpadeo_3->setPixmap(green);
                clase = 0;
            }
            else{
                ui->iconParpadeo_3->setPixmap(white);
                clase = 1;
            }
        break;
        case 1:
            ui->lbExplicacion->setText("Parpadea cada vez que se encienda la imagen central.");
            //Cambia cada 500ms de posición, para entrenamiento de parpadeo.
            action = true;
            if(contador%5==0)
                contadorParpadeo++;
            if(contadorParpadeo == 3)
                clase = 1;
            else
                clase = 0;
            switch(contadorParpadeo){
                case 1: ui->iconParpadeo_1->setPixmap(green);
                        ui->iconParpadeo_5->setPixmap(white);
                        break;
                case 2: ui->iconParpadeo_2->setPixmap(green);
                        ui->iconParpadeo_1->setPixmap(white);
                        break;
                case 3: ui->iconParpadeo_3->setPixmap(green);
                        ui->iconParpadeo_2->setPixmap(white);
                        break;
                case 4: ui->iconParpadeo_4->setPixmap(green);
                        ui->iconParpadeo_3->setPixmap(white);
                        break;
                case 5: ui->iconParpadeo_5->setPixmap(green);
                        ui->iconParpadeo_4->setPixmap(white);
                        contadorParpadeo = 0;
            }
            break;
        case 2:
            ui->lbExplicacion->setText("Cuando el ícono esté en verde intente moverlo, si está en blanco, puede relajarse.");
            if(contador%50==0)
                action = !action;
            if(action){
                ui->iconParpadeo_3->setPixmap(green);
                clase=1;
            }
            else{
                ui->iconParpadeo_3->setPixmap(white);
                clase=0;
            }
            break;
        case 3:
            ui->lbExplicacion->setText("Piense en mover su mano derecha o izquierda, según la flecha que aparezca.");
            if(contador%50==0){
                action = !action;
                qsrand(qrand());
                derIzqRnd = qrand() % 2;
            }
            if(action){
                if(derIzqRnd == 0){
                    clase=1;
                    ui->iconParpadeo_2->setVisible(true);
                    ui->iconParpadeo_4->setVisible(false);
                    ui->iconParpadeo_2->setPixmap(left);
                }
                else{
                    clase=2;
                    ui->iconParpadeo_2->setVisible(false);
                    ui->iconParpadeo_4->setVisible(true);
                    ui->iconParpadeo_4->setPixmap(right);
                }
            }
            else{
                ui->iconParpadeo_2->setVisible(false);
                ui->iconParpadeo_4->setVisible(false);
                clase=0;
            }
            break;
        default: break;
    }
}

void MainWindow::iniciar(){
    contador=0;
    //Nomenclatura para guardar archivos
    if(ui->chCaso1->isChecked()){
        seleccion = 0;
        tipo = "N";   //NEUTRAL
        ui->lbTipoActual->setText("NEUTRAL");
        ui->iconParpadeo_3->setVisible(true);
    }
    else if(ui->chCaso2->isChecked()){
        seleccion = 1;
        tipo = "P";   //PARPADEO
        ui->lbTipoActual->setText("PARPADEO");
        ui->iconParpadeo_1->setVisible(true);
        ui->iconParpadeo_2->setVisible(true);
        ui->iconParpadeo_3->setVisible(true);
        ui->iconParpadeo_4->setVisible(true);
        ui->iconParpadeo_5->setVisible(true);
    }
    else if(ui->chCaso3->isChecked()){
        seleccion = 2;
        tipo = "I";   //INTENCION
        ui->lbTipoActual->setText("INTENCIÓN DE MOVIMIENTO");
        ui->iconParpadeo_3->setVisible(true);
    }
    else{
        seleccion = 3;
        tipo = "M";  //MOVIMIENTO DERECHA-IZQUIERDA
        ui->lbTipoActual->setText("MOVIMIENTO DERECHA - IZQUIERDA");
        ui->iconParpadeo_2->setVisible(true);
        ui->iconParpadeo_4->setVisible(true);
    }

    //Información de fecha para archivo nuevo
    QDateTime fechaCompleta;
    fechaCompleta = QDateTime::currentDateTime();
    ui->fecha->setDateTime(fechaCompleta);

    string nombre = ui->txtNombre->text().toStdString();
    string nombreArchivo;
    int year = ui->fecha->dateTime().date().year();
    int month = ui->fecha->dateTime().date().month();
    int day = ui->fecha->dateTime().date().day();
    int hour = ui->fecha->dateTime().time().hour();
    int minute = ui->fecha->dateTime().time().minute();

    stringstream ss;

    ss << year;
    if(month < 10)
        ss << "0";
    ss << month;
    if(day < 10)
        ss << "0";
    ss << day << "_";
    if(hour < 10)
        ss << "0";
    ss << hour;
    if(minute < 10)
        ss << "0";
    ss << minute;

    if(nombre.empty())
        nombreArchivo = "archivos/Lectura_" + tipo + "_" + ss.str() + ".csv";
    else
        nombreArchivo = "archivos/" + nombre + "_" + tipo + "_" + ss.str() + ".csv";

    ofs.open(nombreArchivo, std::ios::trunc);

    ui->gpConfig->setVisible(false);
    ui->btParar->setVisible(true);
}

void MainWindow::parar(){
    ofs.close();
    ui->gpConfig->setVisible(true);
    ui->btParar->setVisible(false);

    ui->iconParpadeo_1->setVisible(false);
    ui->iconParpadeo_2->setVisible(false);
    ui->iconParpadeo_3->setVisible(false);
    ui->iconParpadeo_4->setVisible(false);
    ui->iconParpadeo_5->setVisible(false);

}

void MainWindow::realtimeDataSlot()
{
    state = IEE_EngineGetNextEvent(eEvent);

    if (state == EDK_OK)
    {
      IEE_Event_t eventType = IEE_EmoEngineEventGetType(eEvent);
      IEE_EmoEngineEventGetUserId(eEvent, &userID);

      // Log the EmoState if it has been updated
      switch (eventType) {
        case IEE_UserAdded:
            std::cout << "User added" << std::endl;
            engineUserID = 0;
            IEE_FFTSetWindowingType(engineUserID, IEE_HAMMING);
            ready = true;
            break;
        case IEE_EmoStateUpdated:
            onStateChanged = true;
            IEE_EmoEngineEventGetEmoState(eEvent, eState);
            break;
        default:
            break;
      }
    }

    if(onStateChanged){
        onStateChanged = false;
        wirelessStrength = IS_GetWirelessSignalStatus(eState);
        switch(wirelessStrength){
            case IEEG_CQ_NO_SIGNAL:
            ui->barraPotencia->setValue(0); break;
            case IEEG_CQ_VERY_BAD:
            ui->barraPotencia->setValue(25); break;
            case IEEG_CQ_POOR:
            ui->barraPotencia->setValue(50); break;
            case IEEG_CQ_FAIR:
            ui->barraPotencia->setValue(75); break;
            ready = false;
            case IEEG_CQ_GOOD:
            ui->barraPotencia->setValue(100); break;
            default:
            ui->barraPotencia->setValue(0); break;
        }

        if(wirelessStrength == IEEG_CQ_NO_SIGNAL){
            isStateOk = false;
            ui->btIniciar->setEnabled(false);
        }
        else {
            isStateOk = true;
            IS_GetBatteryChargeLevel(eState, &batteryLevel, &maxBatteryLevel);
            float porcentajeBateria = (float)batteryLevel / (float)maxBatteryLevel * 100;
            ui->barraBateria->setValue(porcentajeBateria);
            ui->btIniciar->setEnabled(true);
        }
    }

    if (ready && isStateOk && (contador%5)==0 && !epochSaved && action)
    {
        double alpha, low_beta, high_beta, gamma, theta;
        alpha = low_beta = high_beta = gamma = theta = 0;
        //cout << contador << " ------ " << endl;
        for(int i=0 ; i< sizeof(channelList)/sizeof(channelList[0]) ; ++i)
        {
            int result = IEE_GetAverageBandPowers(engineUserID, channelList[i], &theta, &alpha,
                                                     &low_beta, &high_beta, &gamma);
            if(result == EDK_OK)
            {                
                ofs << theta << "," << alpha << "," << low_beta << ",";
                ofs << high_beta << "," << gamma << ",";

                /*
                if(i != sizeof(channelList)/sizeof(channelList[0])-1)
                {
                    ofs << ",";
                }
                */
            }
        }
        ofs << clase << "," << contador << endl;
        epochSaved = true;
    }
}
