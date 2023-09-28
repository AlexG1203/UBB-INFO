/********************************************************************************
** Form generated from reading UI file 'ProduseProject.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUSEPROJECT_H
#define UI_PRODUSEPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProduseProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ProduseProjectClass)
    {
        if (ProduseProjectClass->objectName().isEmpty())
            ProduseProjectClass->setObjectName("ProduseProjectClass");
        ProduseProjectClass->resize(600, 400);
        menuBar = new QMenuBar(ProduseProjectClass);
        menuBar->setObjectName("menuBar");
        ProduseProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ProduseProjectClass);
        mainToolBar->setObjectName("mainToolBar");
        ProduseProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(ProduseProjectClass);
        centralWidget->setObjectName("centralWidget");
        ProduseProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(ProduseProjectClass);
        statusBar->setObjectName("statusBar");
        ProduseProjectClass->setStatusBar(statusBar);

        retranslateUi(ProduseProjectClass);

        QMetaObject::connectSlotsByName(ProduseProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *ProduseProjectClass)
    {
        ProduseProjectClass->setWindowTitle(QCoreApplication::translate("ProduseProjectClass", "ProduseProject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProduseProjectClass: public Ui_ProduseProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUSEPROJECT_H
