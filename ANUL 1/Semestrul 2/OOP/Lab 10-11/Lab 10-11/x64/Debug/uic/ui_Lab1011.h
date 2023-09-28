/********************************************************************************
** Form generated from reading UI file 'Lab1011.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAB1011_H
#define UI_LAB1011_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lab1011Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Lab1011Class)
    {
        if (Lab1011Class->objectName().isEmpty())
            Lab1011Class->setObjectName("Lab1011Class");
        Lab1011Class->resize(600, 400);
        menuBar = new QMenuBar(Lab1011Class);
        menuBar->setObjectName("menuBar");
        Lab1011Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Lab1011Class);
        mainToolBar->setObjectName("mainToolBar");
        Lab1011Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Lab1011Class);
        centralWidget->setObjectName("centralWidget");
        Lab1011Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Lab1011Class);
        statusBar->setObjectName("statusBar");
        Lab1011Class->setStatusBar(statusBar);

        retranslateUi(Lab1011Class);

        QMetaObject::connectSlotsByName(Lab1011Class);
    } // setupUi

    void retranslateUi(QMainWindow *Lab1011Class)
    {
        Lab1011Class->setWindowTitle(QCoreApplication::translate("Lab1011Class", "Lab1011", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lab1011Class: public Ui_Lab1011Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAB1011_H
