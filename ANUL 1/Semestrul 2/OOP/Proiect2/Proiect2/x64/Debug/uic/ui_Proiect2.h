/********************************************************************************
** Form generated from reading UI file 'Proiect2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROIECT2_H
#define UI_PROIECT2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Proiect2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Proiect2Class)
    {
        if (Proiect2Class->objectName().isEmpty())
            Proiect2Class->setObjectName("Proiect2Class");
        Proiect2Class->resize(600, 400);
        menuBar = new QMenuBar(Proiect2Class);
        menuBar->setObjectName("menuBar");
        Proiect2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Proiect2Class);
        mainToolBar->setObjectName("mainToolBar");
        Proiect2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Proiect2Class);
        centralWidget->setObjectName("centralWidget");
        Proiect2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Proiect2Class);
        statusBar->setObjectName("statusBar");
        Proiect2Class->setStatusBar(statusBar);

        retranslateUi(Proiect2Class);

        QMetaObject::connectSlotsByName(Proiect2Class);
    } // setupUi

    void retranslateUi(QMainWindow *Proiect2Class)
    {
        Proiect2Class->setWindowTitle(QCoreApplication::translate("Proiect2Class", "Proiect2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Proiect2Class: public Ui_Proiect2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROIECT2_H
