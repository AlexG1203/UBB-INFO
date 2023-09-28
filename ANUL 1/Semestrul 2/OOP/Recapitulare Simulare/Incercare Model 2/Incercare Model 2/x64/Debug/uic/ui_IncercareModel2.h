/********************************************************************************
** Form generated from reading UI file 'IncercareModel2.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INCERCAREMODEL2_H
#define UI_INCERCAREMODEL2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_IncercareModel2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *IncercareModel2Class)
    {
        if (IncercareModel2Class->objectName().isEmpty())
            IncercareModel2Class->setObjectName("IncercareModel2Class");
        IncercareModel2Class->resize(600, 400);
        menuBar = new QMenuBar(IncercareModel2Class);
        menuBar->setObjectName("menuBar");
        IncercareModel2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(IncercareModel2Class);
        mainToolBar->setObjectName("mainToolBar");
        IncercareModel2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(IncercareModel2Class);
        centralWidget->setObjectName("centralWidget");
        IncercareModel2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(IncercareModel2Class);
        statusBar->setObjectName("statusBar");
        IncercareModel2Class->setStatusBar(statusBar);

        retranslateUi(IncercareModel2Class);

        QMetaObject::connectSlotsByName(IncercareModel2Class);
    } // setupUi

    void retranslateUi(QMainWindow *IncercareModel2Class)
    {
        IncercareModel2Class->setWindowTitle(QCoreApplication::translate("IncercareModel2Class", "IncercareModel2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IncercareModel2Class: public Ui_IncercareModel2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INCERCAREMODEL2_H
