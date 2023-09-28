#include <iostream>
#include "tests.h"
#include "Console.h"

int main() {
	Tests tests;
	tests.runAllTests();

	MedicamentRepo repo;
	MedicamentValidator validator;
	MedicamentService service(repo, validator);

	Console ui(service);
	ui.run();

	return 0;
}