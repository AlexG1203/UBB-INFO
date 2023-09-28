#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ModelSimulare1.h"

class ModelSimulare1 : public QMainWindow
{
    Q_OBJECT

public:
    ModelSimulare1(QWidget *parent = nullptr);
    ~ModelSimulare1();

private:
    Ui::ModelSimulare1Class ui;
};
