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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QCustomPlot *customPlot;
    QCheckBox *ED_COUNTER;
    QCheckBox *ED_AF4;
    QCheckBox *ED_AF3;
    QCheckBox *ED_F7;
    QCheckBox *ED_F3;
    QCheckBox *ED_FC5;
    QCheckBox *ED_T7;
    QCheckBox *ED_P7;
    QCheckBox *ED_O1;
    QCheckBox *ED_O2;
    QCheckBox *ED_P8;
    QCheckBox *ED_T8;
    QCheckBox *ED_FC6;
    QCheckBox *ED_F4;
    QCheckBox *ED_F8;
    QLabel *label;
    QLabel *label_2;
    QCheckBox *LB_Caso1;
    QCheckBox *LB_Caso2;
    QCheckBox *LB_Caso3;
    QCheckBox *LB_Caso4;
    QCheckBox *LB_Caso5;
    QCheckBox *BT_grabar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(650, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        customPlot = new QCustomPlot(centralWidget);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        customPlot->setGeometry(QRect(10, 20, 431, 341));
        ED_COUNTER = new QCheckBox(centralWidget);
        ED_COUNTER->setObjectName(QStringLiteral("ED_COUNTER"));
        ED_COUNTER->setGeometry(QRect(450, 70, 101, 17));
        ED_COUNTER->setChecked(false);
        ED_AF4 = new QCheckBox(centralWidget);
        ED_AF4->setObjectName(QStringLiteral("ED_AF4"));
        ED_AF4->setGeometry(QRect(450, 350, 101, 17));
        ED_AF4->setChecked(true);
        ED_AF3 = new QCheckBox(centralWidget);
        ED_AF3->setObjectName(QStringLiteral("ED_AF3"));
        ED_AF3->setGeometry(QRect(450, 90, 101, 17));
        ED_AF3->setChecked(true);
        ED_F7 = new QCheckBox(centralWidget);
        ED_F7->setObjectName(QStringLiteral("ED_F7"));
        ED_F7->setGeometry(QRect(450, 110, 101, 17));
        ED_F7->setChecked(true);
        ED_F3 = new QCheckBox(centralWidget);
        ED_F3->setObjectName(QStringLiteral("ED_F3"));
        ED_F3->setGeometry(QRect(450, 130, 101, 17));
        ED_F3->setChecked(true);
        ED_FC5 = new QCheckBox(centralWidget);
        ED_FC5->setObjectName(QStringLiteral("ED_FC5"));
        ED_FC5->setGeometry(QRect(450, 150, 101, 17));
        ED_FC5->setChecked(true);
        ED_T7 = new QCheckBox(centralWidget);
        ED_T7->setObjectName(QStringLiteral("ED_T7"));
        ED_T7->setGeometry(QRect(450, 170, 101, 17));
        ED_T7->setChecked(true);
        ED_P7 = new QCheckBox(centralWidget);
        ED_P7->setObjectName(QStringLiteral("ED_P7"));
        ED_P7->setGeometry(QRect(450, 190, 101, 17));
        ED_P7->setChecked(true);
        ED_O1 = new QCheckBox(centralWidget);
        ED_O1->setObjectName(QStringLiteral("ED_O1"));
        ED_O1->setGeometry(QRect(450, 210, 101, 17));
        ED_O1->setChecked(true);
        ED_O2 = new QCheckBox(centralWidget);
        ED_O2->setObjectName(QStringLiteral("ED_O2"));
        ED_O2->setGeometry(QRect(450, 230, 101, 17));
        ED_O2->setChecked(true);
        ED_P8 = new QCheckBox(centralWidget);
        ED_P8->setObjectName(QStringLiteral("ED_P8"));
        ED_P8->setGeometry(QRect(450, 250, 101, 17));
        ED_P8->setChecked(true);
        ED_T8 = new QCheckBox(centralWidget);
        ED_T8->setObjectName(QStringLiteral("ED_T8"));
        ED_T8->setGeometry(QRect(450, 270, 101, 17));
        ED_T8->setChecked(true);
        ED_FC6 = new QCheckBox(centralWidget);
        ED_FC6->setObjectName(QStringLiteral("ED_FC6"));
        ED_FC6->setGeometry(QRect(450, 290, 101, 17));
        ED_FC6->setChecked(true);
        ED_F4 = new QCheckBox(centralWidget);
        ED_F4->setObjectName(QStringLiteral("ED_F4"));
        ED_F4->setGeometry(QRect(450, 310, 101, 17));
        ED_F4->setChecked(true);
        ED_F8 = new QCheckBox(centralWidget);
        ED_F8->setObjectName(QStringLiteral("ED_F8"));
        ED_F8->setGeometry(QRect(450, 330, 101, 17));
        ED_F8->setChecked(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 50, 47, 13));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(560, 50, 47, 13));
        LB_Caso1 = new QCheckBox(centralWidget);
        LB_Caso1->setObjectName(QStringLiteral("LB_Caso1"));
        LB_Caso1->setGeometry(QRect(560, 70, 101, 17));
        LB_Caso1->setChecked(false);
        LB_Caso2 = new QCheckBox(centralWidget);
        LB_Caso2->setObjectName(QStringLiteral("LB_Caso2"));
        LB_Caso2->setGeometry(QRect(560, 90, 101, 17));
        LB_Caso2->setChecked(false);
        LB_Caso3 = new QCheckBox(centralWidget);
        LB_Caso3->setObjectName(QStringLiteral("LB_Caso3"));
        LB_Caso3->setGeometry(QRect(560, 110, 101, 17));
        LB_Caso3->setChecked(false);
        LB_Caso4 = new QCheckBox(centralWidget);
        LB_Caso4->setObjectName(QStringLiteral("LB_Caso4"));
        LB_Caso4->setGeometry(QRect(560, 130, 101, 17));
        LB_Caso4->setChecked(false);
        LB_Caso5 = new QCheckBox(centralWidget);
        LB_Caso5->setObjectName(QStringLiteral("LB_Caso5"));
        LB_Caso5->setGeometry(QRect(560, 150, 101, 17));
        LB_Caso5->setChecked(false);
        BT_grabar = new QCheckBox(centralWidget);
        BT_grabar->setObjectName(QStringLiteral("BT_grabar"));
        BT_grabar->setGeometry(QRect(450, 20, 101, 17));
        BT_grabar->setChecked(false);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Captura ICC", 0));
        ED_COUNTER->setText(QApplication::translate("MainWindow", "Counter", 0));
        ED_AF4->setText(QApplication::translate("MainWindow", "AF4", 0));
        ED_AF3->setText(QApplication::translate("MainWindow", "AF3", 0));
        ED_F7->setText(QApplication::translate("MainWindow", "F7", 0));
        ED_F3->setText(QApplication::translate("MainWindow", "F3", 0));
        ED_FC5->setText(QApplication::translate("MainWindow", "FC5", 0));
        ED_T7->setText(QApplication::translate("MainWindow", "T7", 0));
        ED_P7->setText(QApplication::translate("MainWindow", "P7", 0));
        ED_O1->setText(QApplication::translate("MainWindow", "O1", 0));
        ED_O2->setText(QApplication::translate("MainWindow", "O2", 0));
        ED_P8->setText(QApplication::translate("MainWindow", "P8", 0));
        ED_T8->setText(QApplication::translate("MainWindow", "T8", 0));
        ED_FC6->setText(QApplication::translate("MainWindow", "FC6", 0));
        ED_F4->setText(QApplication::translate("MainWindow", "F4", 0));
        ED_F8->setText(QApplication::translate("MainWindow", "F8", 0));
        label->setText(QApplication::translate("MainWindow", "SE\303\221ALES", 0));
        label_2->setText(QApplication::translate("MainWindow", "Clase", 0));
        LB_Caso1->setText(QApplication::translate("MainWindow", "Caso 1", 0));
        LB_Caso2->setText(QApplication::translate("MainWindow", "Caso 2", 0));
        LB_Caso3->setText(QApplication::translate("MainWindow", "Caso 3", 0));
        LB_Caso4->setText(QApplication::translate("MainWindow", "Caso 4", 0));
        LB_Caso5->setText(QApplication::translate("MainWindow", "Caso 5", 0));
        BT_grabar->setText(QApplication::translate("MainWindow", "Grabar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
