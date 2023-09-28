#include "Lab1011.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include "console.h"
#include "MedicamentStore.h"
#include "MedicamentRepo.h"
#include "validator.h"
#include "MedicamentRepoFile.h"
#include "GUI.h"

void testAll() {
	testCtr();
	testValidator();
	testRepo();
	testReteta();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*Lab1011 w;
    w.show();*/
	MedicamentRepoFile fileRepo{ "medicamente.txt" };
	MedicamentValidator val{};
	Reteta reteta{};
	MedicamentStore ctr{ fileRepo,val,reteta };
	GUI gui{ ctr };
	gui.show();
    return a.exec();
}
