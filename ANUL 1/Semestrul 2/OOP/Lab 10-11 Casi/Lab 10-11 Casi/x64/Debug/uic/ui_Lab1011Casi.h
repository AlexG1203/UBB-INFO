/********************************************************************************
** Form generated from reading UI file 'Lab1011Casi.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1011CASI_H
#define UI_LAB1011CASI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1011CasiClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1011CasiClass)
    {
        if (Lab1011CasiClass->objectName().isEmpty())
            Lab1011CasiClass->setObjectName("Lab1011CasiClass");
        Lab1011CasiClass->resize(600, 400);
        menuBar = new QMenuBar(Lab1011CasiClass);
        menuBar->setObjectName("menuBar");
        Lab1011CasiClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1011CasiClass);
        mainToolBar->setObjectName("mainToolBar");
        Lab1011CasiClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab1011CasiClass);
        centralWidget->setObjectName("centralWidget");
        Lab1011CasiClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab1011CasiClass);
        statusBar->setObjectName("statusBar");
        Lab1011CasiClass->setStatusBar(statusBar);

        retranslateUi(Lab1011CasiClass);

        QMetaObject::connectSlotsByName(Lab1011CasiClass);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1011CasiClass)
    {
        Lab1011CasiClass->setWindowTitle(QCoreApplication::translate("Lab1011CasiClass", "Lab1011Casi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab1011CasiClass: public Ui_Lab1011CasiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1011CASI_H
