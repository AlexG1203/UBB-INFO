/********************************************************************************
** Form generated from reading UI file 'ModelSimulare2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELSIMULARE2_H
#define UI_MODELSIMULARE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelSimulare2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelSimulare2Class)
    {
        if (ModelSimulare2Class->objectName().isEmpty())
            ModelSimulare2Class->setObjectName("ModelSimulare2Class");
        ModelSimulare2Class->resize(600, 400);
        menuBar = new QMenuBar(ModelSimulare2Class);
        menuBar->setObjectName("menuBar");
        ModelSimulare2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelSimulare2Class);
        mainToolBar->setObjectName("mainToolBar");
        ModelSimulare2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(ModelSimulare2Class);
        centralWidget->setObjectName("centralWidget");
        ModelSimulare2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ModelSimulare2Class);
        statusBar->setObjectName("statusBar");
        ModelSimulare2Class->setStatusBar(statusBar);

        retranslateUi(ModelSimulare2Class);

        QMetaObject::connectSlotsByName(ModelSimulare2Class);
    } // setupUi

    void retranslateUi(QMainWindow *ModelSimulare2Class)
    {
        ModelSimulare2Class->setWindowTitle(QCoreApplication::translate("ModelSimulare2Class", "ModelSimulare2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelSimulare2Class: public Ui_ModelSimulare2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELSIMULARE2_H
