#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_IncercareModel2.h"

class IncercareModel2 : public QMainWindow
{
    Q_OBJECT

public:
    IncercareModel2(QWidget *parent = nullptr);
    ~IncercareModel2();

private:
    Ui::IncercareModel2Class ui;
};
