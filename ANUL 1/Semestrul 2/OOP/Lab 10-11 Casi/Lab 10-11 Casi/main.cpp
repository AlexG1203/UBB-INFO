#include "Lab1011Casi.h"
#include "GUI.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include "tests.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    /*Lab1011 w;
    w.show();*/
    MedicamentRepoFile repoFile{ "medicamente.txt" };
    MedicamentValidator validator{};
    Reteta reteta{};
    MedicamentService service{ repoFile, validator, reteta };
    GUI gui{ service };
    gui.show();
    return a.exec();
}
