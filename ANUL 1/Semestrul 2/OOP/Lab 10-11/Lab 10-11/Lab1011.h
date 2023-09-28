#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011.h"

class Lab1011 : public QMainWindow
{
    Q_OBJECT

public:
    Lab1011(QWidget *parent = nullptr);
    ~Lab1011();

private:
    Ui::Lab1011Class ui;
};
