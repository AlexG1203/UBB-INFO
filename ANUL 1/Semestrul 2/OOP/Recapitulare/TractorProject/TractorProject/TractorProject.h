#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TractorProject.h"

class TractorProject : public QMainWindow
{
    Q_OBJECT

public:
    TractorProject(QWidget *parent = nullptr);
    ~TractorProject();

private:
    Ui::TractorProjectClass ui;
};
