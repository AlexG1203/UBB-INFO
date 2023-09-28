#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ProduseProject.h"

class ProduseProject : public QMainWindow
{
    Q_OBJECT

public:
    ProduseProject(QWidget *parent = nullptr);
    ~ProduseProject();

private:
    Ui::ProduseProjectClass ui;
};
