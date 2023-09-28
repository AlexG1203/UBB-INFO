#include "Proiect2.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
#include "StudentGUI.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    //AExamenSesiuneStudenti w;
    //w.show();
    //Tests t;
    //t.testAll();
    Repo repo{ "MainFile.txt" };
    Service serv{ repo };
    StudentGUI gui{ serv };
    gui.show();
    a.setStyle("fusion");
    return a.exec();
    //return 0;
}
