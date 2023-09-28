#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab1011Casi.h"

class Lab1011Casi : public QMainWindow
{
    Q_OBJECT

public:
    Lab1011Casi(QWidget *parent = nullptr);
    ~Lab1011Casi();

private:
    Ui::Lab1011CasiClass ui;
};
