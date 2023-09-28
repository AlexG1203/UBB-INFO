#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ModelSimulare2.h"

class ModelSimulare2 : public QMainWindow
{
    Q_OBJECT

public:
    ModelSimulare2(QWidget *parent = nullptr);
    ~ModelSimulare2();

private:
    Ui::ModelSimulare2Class ui;
};
