/********************************************************************************
** Form generated from reading UI file 'Simulare.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULARE_H
#define UI_SIMULARE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulareClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SimulareClass)
    {
        if (SimulareClass->objectName().isEmpty())
            SimulareClass->setObjectName("SimulareClass");
        SimulareClass->resize(600, 400);
        menuBar = new QMenuBar(SimulareClass);
        menuBar->setObjectName("menuBar");
        SimulareClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SimulareClass);
        mainToolBar->setObjectName("mainToolBar");
        SimulareClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SimulareClass);
        centralWidget->setObjectName("centralWidget");
        SimulareClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SimulareClass);
        statusBar->setObjectName("statusBar");
        SimulareClass->setStatusBar(statusBar);

        retranslateUi(SimulareClass);

        QMetaObject::connectSlotsByName(SimulareClass);
    } // setupUi

    void retranslateUi(QMainWindow *SimulareClass)
    {
        SimulareClass->setWindowTitle(QCoreApplication::translate("SimulareClass", "Simulare", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SimulareClass: public Ui_SimulareClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULARE_H
