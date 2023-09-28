/********************************************************************************
** Form generated from reading UI file 'ModelSimulare1.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODELSIMULARE1_H
#define UI_MODELSIMULARE1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModelSimulare1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ModelSimulare1Class)
    {
        if (ModelSimulare1Class->objectName().isEmpty())
            ModelSimulare1Class->setObjectName("ModelSimulare1Class");
        ModelSimulare1Class->resize(600, 400);
        menuBar = new QMenuBar(ModelSimulare1Class);
        menuBar->setObjectName("menuBar");
        ModelSimulare1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ModelSimulare1Class);
        mainToolBar->setObjectName("mainToolBar");
        ModelSimulare1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(ModelSimulare1Class);
        centralWidget->setObjectName("centralWidget");
        ModelSimulare1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ModelSimulare1Class);
        statusBar->setObjectName("statusBar");
        ModelSimulare1Class->setStatusBar(statusBar);

        retranslateUi(ModelSimulare1Class);

        QMetaObject::connectSlotsByName(ModelSimulare1Class);
    } // setupUi

    void retranslateUi(QMainWindow *ModelSimulare1Class)
    {
        ModelSimulare1Class->setWindowTitle(QCoreApplication::translate("ModelSimulare1Class", "ModelSimulare1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ModelSimulare1Class: public Ui_ModelSimulare1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODELSIMULARE1_H
