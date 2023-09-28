#include "Practic.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo{ "input.txt" };
    Service service{ repo };
    GUI gui{ service };
    gui.show();
    return a.exec();
}
