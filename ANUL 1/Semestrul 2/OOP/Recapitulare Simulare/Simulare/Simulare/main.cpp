#include "Simulare.h"
#include <QtWidgets/QApplication>
#include "GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo r{ "cutremure.txt" };
    Serv s{ r };
    GUI w{ s };
    w.show();
    return a.exec();
}
