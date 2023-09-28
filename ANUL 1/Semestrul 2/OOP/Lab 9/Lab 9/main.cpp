#include "console.h"
#include "MedicamentStore.h"
#include "MedicamentRepo.h"
#include "validator.h"
#include "MedicamentRepoFile.h"

void testAll() {
	testCtr();
	testValidator();
	testRepo();
	testReteta();
}

int main() {
	testAll();
	
	MedicamentRepoFile fileRepo{ "medicamente.txt" };
	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ fileRepo,val,reteta };
	ConsoleUI ui{ ctr };
	ui.start();
}