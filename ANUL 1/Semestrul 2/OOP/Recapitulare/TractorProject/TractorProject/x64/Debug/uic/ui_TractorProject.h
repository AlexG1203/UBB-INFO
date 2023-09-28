/********************************************************************************
** Form generated from reading UI file 'TractorProject.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACTORPROJECT_H
#define UI_TRACTORPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TractorProjectClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TractorProjectClass)
    {
        if (TractorProjectClass->objectName().isEmpty())
            TractorProjectClass->setObjectName("TractorProjectClass");
        TractorProjectClass->resize(600, 400);
        menuBar = new QMenuBar(TractorProjectClass);
        menuBar->setObjectName("menuBar");
        TractorProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TractorProjectClass);
        mainToolBar->setObjectName("mainToolBar");
        TractorProjectClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TractorProjectClass);
        centralWidget->setObjectName("centralWidget");
        TractorProjectClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TractorProjectClass);
        statusBar->setObjectName("statusBar");
        TractorProjectClass->setStatusBar(statusBar);

        retranslateUi(TractorProjectClass);

        QMetaObject::connectSlotsByName(TractorProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *TractorProjectClass)
    {
        TractorProjectClass->setWindowTitle(QCoreApplication::translate("TractorProjectClass", "TractorProject", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TractorProjectClass: public Ui_TractorProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACTORPROJECT_H
