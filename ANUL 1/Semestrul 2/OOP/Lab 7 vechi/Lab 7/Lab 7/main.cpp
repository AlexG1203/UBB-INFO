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
	MedicamentStore ctr{ rep };
	ConsoleUI ui{ ctr };
	ui.start();
}