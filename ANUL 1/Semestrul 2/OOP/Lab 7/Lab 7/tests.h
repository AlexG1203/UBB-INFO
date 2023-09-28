#pragma once
#include "Medicament.h"
#include "MedicamentRepo.h"
#include "validator.h"
#include "MedicamentStore.h"
#include "Vector.h"

class Tests {
public:
	void runAllTests();
	void testDomain();
	void testRepo();
	void testValidate();
	void testService();
	void testMyVector();
};