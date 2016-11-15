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
    connect(ui->b_parpadeo, SIGNAL(released()), this, SLOT(parpadeo()));
    connect(ui->b_parada, SIGNAL(released()), this, SLOT(resetear()));
    connect(ui->b_inicio, SIGNAL(released()), this, SLOT(iniciar()));
    timer->start(500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update(){
    switch (contador)
    {
        case 0: ui->label_espacio->setStyleSheet("background-color: lightGray"); break;
        case 1: ui->label_espacio->setStyleSheet("background-color: orange"); break;
        case 2: ui->label_espacio->setStyleSheet("background-color: lightGray");
                ui->label_e->setStyleSheet("background-color: orange"); break;
        case 3: ui->label_e->setStyleSheet("background-color: lightGray");
                ui->label_a->setStyleSheet("background-color: orange"); break;
        case 4: ui->label_a->setStyleSheet("background-color: lightGray");
                ui->label_o->setStyleSheet("background-color: orange"); break;
        case 5: ui->label_o->setStyleSheet("background-color: lightGray");
                ui->label_s->setStyleSheet("background-color: orange"); break;
        case 6: ui->label_s->setStyleSheet("background-color: lightGray");
                ui->label_r->setStyleSheet("background-color: orange"); break;
        case 7: ui->label_r->setStyleSheet("background-color: lightGray");
                ui->label_n->setStyleSheet("background-color: orange"); break;
        case 8: ui->label_n->setStyleSheet("background-color: lightGray");
                ui->label_i->setStyleSheet("background-color: orange"); break;
        case 9: ui->label_i->setStyleSheet("background-color: lightGray");
                ui->label_d->setStyleSheet("background-color: orange"); break;
        case 10: ui->label_d->setStyleSheet("background-color: lightGray");
                 ui->label_l->setStyleSheet("background-color: orange"); break;
        case 11: ui->label_l->setStyleSheet("background-color: lightGray");
                 ui->label_c->setStyleSheet("background-color: orange"); break;
        case 12: ui->label_c->setStyleSheet("background-color: lightGray");
                 ui->label_t->setStyleSheet("background-color: orange"); break;
        case 13: ui->label_t->setStyleSheet("background-color: lightGray");
                 ui->label_u->setStyleSheet("background-color: orange"); break;
        case 14: ui->label_u->setStyleSheet("background-color: lightGray");
                 ui->label_m->setStyleSheet("background-color: orange"); break;
        case 15: ui->label_m->setStyleSheet("background-color: lightGray");
                 ui->label_p->setStyleSheet("background-color: orange"); break;
        case 16: ui->label_p->setStyleSheet("background-color: lightGray");
                 ui->label_b->setStyleSheet("background-color: orange"); break;
        case 17: ui->label_b->setStyleSheet("background-color: lightGray");
                 ui->label_g->setStyleSheet("background-color: orange"); break;
        case 18: ui->label_g->setStyleSheet("background-color: lightGray");
                 ui->label_v->setStyleSheet("background-color: orange"); break;
        case 19: ui->label_v->setStyleSheet("background-color: lightGray");
                 ui->label_y->setStyleSheet("background-color: orange"); break;
        case 20: ui->label_y->setStyleSheet("background-color: lightGray");
                 ui->label_q->setStyleSheet("background-color: orange"); break;
        case 21: ui->label_q->setStyleSheet("background-color: lightGray");
                 ui->label_h->setStyleSheet("background-color: orange"); break;
        case 22: ui->label_h->setStyleSheet("background-color: lightGray");
                 ui->label_f->setStyleSheet("background-color: orange"); break;
        case 23: ui->label_f->setStyleSheet("background-color: lightGray");
                 ui->label_z->setStyleSheet("background-color: orange"); break;
        case 24: ui->label_z->setStyleSheet("background-color: lightGray");
                 ui->label_j->setStyleSheet("background-color: orange"); break;
        case 25: ui->label_j->setStyleSheet("background-color: lightGray");
                 ui->label_ng->setStyleSheet("background-color: orange"); break;
        case 26: ui->label_ng->setStyleSheet("background-color: lightGray");
                 ui->label_x->setStyleSheet("background-color: orange"); break;
        case 27: ui->label_x->setStyleSheet("background-color: lightGray");
                 ui->label_w->setStyleSheet("background-color: orange"); break;
        case 28: ui->label_w->setStyleSheet("background-color: lightGray");
                 ui->label_k->setStyleSheet("background-color: orange"); break;
        case 29: ui->label_k->setStyleSheet("background-color: lightGray");
                 contador = -1;
    }
    contador++;
}

void MainWindow::parpadeo(){
   QString texto = "";
    switch (contador - 1){
        case 1: texto = " "; break;
        case 2: texto = "e"; break;
        case 3: texto = "a"; break;
        case 4: texto = "o"; break;
        case 5: texto = "s"; break;
        case 6: texto = "r"; break;
        case 7: texto = "n"; break;
        case 8: texto = "i"; break;
        case 9: texto = "d"; break;
        case 10: texto = "l"; break;
        case 11: texto = "c"; break;
        case 12: texto = "t"; break;
        case 13: texto = "u"; break;
        case 14: texto = "m"; break;
        case 15: texto = "p"; break;
        case 16: texto = "b"; break;
        case 17: texto = "g"; break;
        case 18: texto = "v"; break;
        case 19: texto = "y"; break;
        case 20: texto = "q"; break;
        case 21: texto = "h"; break;
        case 22: texto = "f"; break;
        case 23: texto = "z"; break;
        case 24: texto = "j"; break;
        case 25: texto = "ñ"; break;
        case 26: texto = "x"; break;
        case 27: texto = "w"; break;
        case 28: texto = "k"; break;
    }
    ui->texto->setText(ui->texto->text() + texto);
    reiniciar();
}

void MainWindow::reiniciar(){
    contador = 0;
    ui->label_espacio->setStyleSheet("background-color: lightGray");
    ui->label_e->setStyleSheet("background-color: lightGray");
    ui->label_a->setStyleSheet("background-color: lightGray");
    ui->label_o->setStyleSheet("background-color: lightGray");
    ui->label_s->setStyleSheet("background-color: lightGray");
    ui->label_r->setStyleSheet("background-color: lightGray");
    ui->label_n->setStyleSheet("background-color: lightGray");
    ui->label_i->setStyleSheet("background-color: lightGray");
    ui->label_d->setStyleSheet("background-color: lightGray");
    ui->label_l->setStyleSheet("background-color: lightGray");
    ui->label_c->setStyleSheet("background-color: lightGray");
    ui->label_t->setStyleSheet("background-color: lightGray");
    ui->label_u->setStyleSheet("background-color: lightGray");
    ui->label_m->setStyleSheet("background-color: lightGray");
    ui->label_p->setStyleSheet("background-color: lightGray");
    ui->label_b->setStyleSheet("background-color: lightGray");
    ui->label_g->setStyleSheet("background-color: lightGray");
    ui->label_v->setStyleSheet("background-color: lightGray");
    ui->label_y->setStyleSheet("background-color: lightGray");
    ui->label_q->setStyleSheet("background-color: lightGray");
    ui->label_h->setStyleSheet("background-color: lightGray");
    ui->label_f->setStyleSheet("background-color: lightGray");
    ui->label_z->setStyleSheet("background-color: lightGray");
    ui->label_j->setStyleSheet("background-color: lightGray");
    ui->label_ng->setStyleSheet("background-color: lightGray");
    ui->label_x->setStyleSheet("background-color: lightGray");
    ui->label_w->setStyleSheet("background-color: lightGray");
    ui->label_k->setStyleSheet("background-color: lightGray");
}

void MainWindow::iniciar(){
    ui->texto->setText("");
    resetear();
    timer->start();
}

void MainWindow::resetear(){
    reiniciar();
    timer->stop();
}

