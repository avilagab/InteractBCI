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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *label_4;
    QPushButton *b_parada;
    QLabel *label_0;
    QLabel *label_3;
    QLabel *label_9;
    QPushButton *b_inicio;
    QLabel *label_2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_1;
    QLabel *label_5;
    QLabel *label_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(766, 415);
        MainWindow->setStyleSheet(QStringLiteral("QLabel { background: lightgray }"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(380, 250, 40, 40));
        QFont font;
        font.setPointSize(22);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        b_parada = new QPushButton(centralWidget);
        b_parada->setObjectName(QStringLiteral("b_parada"));
        b_parada->setGeometry(QRect(40, 310, 75, 23));
        label_0 = new QLabel(centralWidget);
        label_0->setObjectName(QStringLiteral("label_0"));
        label_0->setGeometry(QRect(380, 90, 40, 40));
        label_0->setFont(font);
        label_0->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(430, 220, 40, 40));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(330, 90, 40, 40));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);
        b_inicio = new QPushButton(centralWidget);
        b_inicio->setObjectName(QStringLiteral("b_inicio"));
        b_inicio->setGeometry(QRect(40, 290, 75, 23));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 170, 40, 40));
        label_2->setFont(font);
        label_2->setStyleSheet(QStringLiteral(""));
        label_2->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(260, 170, 40, 40));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(280, 120, 40, 40));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);
        label_1 = new QLabel(centralWidget);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(430, 120, 40, 40));
        label_1->setFont(font);
        label_1->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(330, 250, 40, 40));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 220, 40, 40));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Prototipo - Teclado", 0));
        label_4->setText(QApplication::translate("MainWindow", "4", 0));
        b_parada->setText(QApplication::translate("MainWindow", "PARAR", 0));
        label_0->setText(QApplication::translate("MainWindow", "0", 0));
        label_3->setText(QApplication::translate("MainWindow", "3", 0));
        label_9->setText(QApplication::translate("MainWindow", "9", 0));
        b_inicio->setText(QApplication::translate("MainWindow", "INICIAR", 0));
        label_2->setText(QApplication::translate("MainWindow", "2", 0));
        label_7->setText(QApplication::translate("MainWindow", "7", 0));
        label_8->setText(QApplication::translate("MainWindow", "8", 0));
        label_1->setText(QApplication::translate("MainWindow", "1", 0));
        label_5->setText(QApplication::translate("MainWindow", "5", 0));
        label_6->setText(QApplication::translate("MainWindow", "6", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
