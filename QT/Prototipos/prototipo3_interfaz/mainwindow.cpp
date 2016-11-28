#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    contador = 0;
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    connect(ui->b_parada, SIGNAL(released()), this, SLOT(resetear()));
    connect(ui->b_inicio, SIGNAL(released()), this, SLOT(iniciar()));
    timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){

}

void MainWindow::parpadeo(){

}

void MainWindow::reiniciar(){

}

void MainWindow::iniciar(){
    resetear();
    timer->start();
}

void MainWindow::resetear(){
    reiniciar();
    timer->stop();
}

