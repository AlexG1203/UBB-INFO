#include "console.h"
#include "MedicamentStore.h"
#include "MedicamentRepo.h"
#include "validator.h"

void testAll() {
	testCtr();
	testValidator();
	testRepo();
	testReteta();
}

int main() {
	testAll();

	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
	ConsoleUI ui{ ctr };
	ui.start();
}