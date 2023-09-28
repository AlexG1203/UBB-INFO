#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Simulare.h"

class Simulare : public QMainWindow
{
    Q_OBJECT

public:
    Simulare(QWidget *parent = nullptr);
    ~Simulare();

private:
    Ui::SimulareClass ui;
};
