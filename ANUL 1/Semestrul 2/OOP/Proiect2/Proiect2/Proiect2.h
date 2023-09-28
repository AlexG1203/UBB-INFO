#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Proiect2.h"

class Proiect2 : public QMainWindow
{
    Q_OBJECT

public:
    Proiect2(QWidget *parent = nullptr);
    ~Proiect2();

private:
    Ui::Proiect2Class ui;
};
