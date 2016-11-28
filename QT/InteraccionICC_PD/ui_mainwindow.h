/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *gpConfig;
    QPushButton *btIniciar;
    QRadioButton *chCaso3;
    QRadioButton *chCaso1;
    QRadioButton *chCaso4;
    QLabel *lbTipo;
    QLabel *lbNombre;
    QLineEdit *txtNombre;
    QLabel *lbNombre_2;
    QDateTimeEdit *fecha;
    QRadioButton *chCaso2;
    QLabel *lbTipo_2;
    QLabel *lbTipoActual;
    QLabel *label_contador;
    QProgressBar *barraBateria;
    QLabel *label;
    QProgressBar *barraPotencia;
    QLabel *label_2;
    QLabel *lbExplicacion;
    QLabel *iconParpadeo_1;
    QLabel *iconParpadeo_2;
    QLabel *iconParpadeo_3;
    QLabel *iconParpadeo_4;
    QLabel *iconParpadeo_5;
    QPushButton *btParar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(632, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gpConfig = new QGroupBox(centralWidget);
        gpConfig->setObjectName(QStringLiteral("gpConfig"));
        gpConfig->setEnabled(true);
        gpConfig->setGeometry(QRect(210, 80, 211, 241));
        btIniciar = new QPushButton(gpConfig);
        btIniciar->setObjectName(QStringLiteral("btIniciar"));
        btIniciar->setGeometry(QRect(20, 210, 181, 23));
        chCaso3 = new QRadioButton(gpConfig);
        chCaso3->setObjectName(QStringLiteral("chCaso3"));
        chCaso3->setGeometry(QRect(20, 170, 181, 17));
        chCaso3->setChecked(false);
        chCaso1 = new QRadioButton(gpConfig);
        chCaso1->setObjectName(QStringLiteral("chCaso1"));
        chCaso1->setGeometry(QRect(20, 130, 181, 17));
        chCaso1->setChecked(true);
        chCaso4 = new QRadioButton(gpConfig);
        chCaso4->setObjectName(QStringLiteral("chCaso4"));
        chCaso4->setGeometry(QRect(20, 190, 181, 17));
        chCaso4->setChecked(false);
        lbTipo = new QLabel(gpConfig);
        lbTipo->setObjectName(QStringLiteral("lbTipo"));
        lbTipo->setGeometry(QRect(20, 110, 81, 16));
        lbNombre = new QLabel(gpConfig);
        lbNombre->setObjectName(QStringLiteral("lbNombre"));
        lbNombre->setGeometry(QRect(20, 20, 101, 16));
        txtNombre = new QLineEdit(gpConfig);
        txtNombre->setObjectName(QStringLiteral("txtNombre"));
        txtNombre->setGeometry(QRect(20, 40, 181, 20));
        txtNombre->setMaxLength(50);
        lbNombre_2 = new QLabel(gpConfig);
        lbNombre_2->setObjectName(QStringLiteral("lbNombre_2"));
        lbNombre_2->setGeometry(QRect(20, 60, 101, 16));
        fecha = new QDateTimeEdit(gpConfig);
        fecha->setObjectName(QStringLiteral("fecha"));
        fecha->setGeometry(QRect(20, 80, 181, 22));
        chCaso2 = new QRadioButton(gpConfig);
        chCaso2->setObjectName(QStringLiteral("chCaso2"));
        chCaso2->setGeometry(QRect(20, 150, 181, 17));
        chCaso2->setChecked(false);
        btIniciar->raise();
        chCaso3->raise();
        chCaso1->raise();
        chCaso4->raise();
        lbTipo->raise();
        lbNombre->raise();
        txtNombre->raise();
        lbNombre_2->raise();
        fecha->raise();
        chCaso2->raise();
        lbTipo_2 = new QLabel(centralWidget);
        lbTipo_2->setObjectName(QStringLiteral("lbTipo_2"));
        lbTipo_2->setGeometry(QRect(20, 10, 91, 16));
        lbTipoActual = new QLabel(centralWidget);
        lbTipoActual->setObjectName(QStringLiteral("lbTipoActual"));
        lbTipoActual->setGeometry(QRect(20, 30, 601, 16));
        label_contador = new QLabel(centralWidget);
        label_contador->setObjectName(QStringLiteral("label_contador"));
        label_contador->setGeometry(QRect(570, 360, 47, 13));
        label_contador->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        barraBateria = new QProgressBar(centralWidget);
        barraBateria->setObjectName(QStringLiteral("barraBateria"));
        barraBateria->setGeometry(QRect(510, 10, 118, 16));
        barraBateria->setValue(0);
        barraBateria->setOrientation(Qt::Horizontal);
        barraBateria->setTextDirection(QProgressBar::TopToBottom);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(280, 10, 47, 13));
        barraPotencia = new QProgressBar(centralWidget);
        barraPotencia->setObjectName(QStringLiteral("barraPotencia"));
        barraPotencia->setGeometry(QRect(330, 10, 118, 16));
        barraPotencia->setValue(0);
        barraPotencia->setTextVisible(true);
        barraPotencia->setOrientation(Qt::Horizontal);
        barraPotencia->setInvertedAppearance(false);
        barraPotencia->setTextDirection(QProgressBar::TopToBottom);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(460, 10, 47, 13));
        lbExplicacion = new QLabel(centralWidget);
        lbExplicacion->setObjectName(QStringLiteral("lbExplicacion"));
        lbExplicacion->setGeometry(QRect(20, 50, 591, 16));
        iconParpadeo_1 = new QLabel(centralWidget);
        iconParpadeo_1->setObjectName(QStringLiteral("iconParpadeo_1"));
        iconParpadeo_1->setEnabled(true);
        iconParpadeo_1->setGeometry(QRect(80, 130, 60, 60));
        iconParpadeo_1->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0)"));
        iconParpadeo_1->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/white.png")));
        iconParpadeo_1->setScaledContents(true);
        iconParpadeo_2 = new QLabel(centralWidget);
        iconParpadeo_2->setObjectName(QStringLiteral("iconParpadeo_2"));
        iconParpadeo_2->setEnabled(true);
        iconParpadeo_2->setGeometry(QRect(180, 130, 60, 60));
        iconParpadeo_2->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0)"));
        iconParpadeo_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/white.png")));
        iconParpadeo_2->setScaledContents(true);
        iconParpadeo_3 = new QLabel(centralWidget);
        iconParpadeo_3->setObjectName(QStringLiteral("iconParpadeo_3"));
        iconParpadeo_3->setGeometry(QRect(280, 130, 60, 60));
        iconParpadeo_3->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0)"));
        iconParpadeo_3->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/white.png")));
        iconParpadeo_3->setScaledContents(true);
        iconParpadeo_4 = new QLabel(centralWidget);
        iconParpadeo_4->setObjectName(QStringLiteral("iconParpadeo_4"));
        iconParpadeo_4->setEnabled(true);
        iconParpadeo_4->setGeometry(QRect(380, 130, 60, 60));
        iconParpadeo_4->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0)"));
        iconParpadeo_4->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/white.png")));
        iconParpadeo_4->setScaledContents(true);
        iconParpadeo_5 = new QLabel(centralWidget);
        iconParpadeo_5->setObjectName(QStringLiteral("iconParpadeo_5"));
        iconParpadeo_5->setEnabled(true);
        iconParpadeo_5->setGeometry(QRect(480, 130, 60, 60));
        iconParpadeo_5->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 0)"));
        iconParpadeo_5->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/white.png")));
        iconParpadeo_5->setScaledContents(true);
        btParar = new QPushButton(centralWidget);
        btParar->setObjectName(QStringLiteral("btParar"));
        btParar->setEnabled(true);
        btParar->setGeometry(QRect(230, 290, 181, 23));
        MainWindow->setCentralWidget(centralWidget);
        gpConfig->raise();
        lbTipo_2->raise();
        lbTipoActual->raise();
        label_contador->raise();
        barraBateria->raise();
        label->raise();
        barraPotencia->raise();
        label_2->raise();
        lbExplicacion->raise();
        iconParpadeo_1->raise();
        chCaso3->raise();
        iconParpadeo_2->raise();
        iconParpadeo_3->raise();
        iconParpadeo_4->raise();
        iconParpadeo_5->raise();
        btParar->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Captura ICC", 0));
        gpConfig->setTitle(QApplication::translate("MainWindow", "Configuraci\303\263n Inicial", 0));
        btIniciar->setText(QApplication::translate("MainWindow", "Iniciar", 0));
        chCaso3->setText(QApplication::translate("MainWindow", "Intenci\303\263n de movimiento", 0));
        chCaso1->setText(QApplication::translate("MainWindow", "Neutral", 0));
        chCaso4->setText(QApplication::translate("MainWindow", "Movimiento izq-der", 0));
        lbTipo->setText(QApplication::translate("MainWindow", "Tipo de lectura:", 0));
        lbNombre->setText(QApplication::translate("MainWindow", "Nombre:", 0));
        lbNombre_2->setText(QApplication::translate("MainWindow", "Fecha:", 0));
        chCaso2->setText(QApplication::translate("MainWindow", "Parpadeo", 0));
        lbTipo_2->setText(QApplication::translate("MainWindow", "Tipo de lectura:", 0));
        lbTipoActual->setText(QString());
        label_contador->setText(QApplication::translate("MainWindow", "0", 0));
        barraBateria->setFormat(QApplication::translate("MainWindow", "%p%", 0));
        label->setText(QApplication::translate("MainWindow", "Se\303\261al:", 0));
        barraPotencia->setFormat(QApplication::translate("MainWindow", "%p%", 0));
        label_2->setText(QApplication::translate("MainWindow", "Bater\303\255a", 0));
        lbExplicacion->setText(QString());
        iconParpadeo_1->setText(QString());
        iconParpadeo_2->setText(QString());
        iconParpadeo_3->setText(QString());
        iconParpadeo_4->setText(QString());
        iconParpadeo_5->setText(QString());
        btParar->setText(QApplication::translate("MainWindow", "Parar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
