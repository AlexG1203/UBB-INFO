#include "TractorProject.h"
#include <QtWidgets/QApplication>
#include "Tests.h"
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Tests tests;
    //tests.runAllTests();
    Repo repo{ "file.txt" };
    Service service{ repo };
    GUI gui{ service };
    gui.show();
    return a.exec();
}
