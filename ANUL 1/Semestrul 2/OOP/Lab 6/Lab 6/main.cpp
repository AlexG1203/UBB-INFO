#include "console.h"
#include "MedicamentStore.h"
#include "MedicamentRepo.h"
#include "validator.h"

void testAll() {
	testCtr();
	testValidator();
	testRepo();
}

int main() {
	testAll();

	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ConsoleUI ui{ ctr };
	//ui.start();
}