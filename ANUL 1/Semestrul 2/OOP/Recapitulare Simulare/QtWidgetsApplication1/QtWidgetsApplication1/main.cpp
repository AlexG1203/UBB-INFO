#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qformlayout.h>
#include <QtWidgets/qlistwidget.h>
#include <vector>
#include <string>
#include "ProductGUI.h"

using std::vector;
using std::string;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProductGUI gui;
    gui.show();
    

    /*QLabel lbl{"Hello world!"};
    lbl.show();
    
    QPushButton btn{ "Say Hello!" };
    btn.show();*/
    
    return a.exec();
}
