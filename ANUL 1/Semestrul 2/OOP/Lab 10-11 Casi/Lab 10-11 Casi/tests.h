#pragma once
#include "Medicament.h"
#include "MedicamentRepo.h"
#include "MedicamentValidator.h"
#include "MedicamentService.h"
#include "MyVector.h"
#include "Reteta.h"

class Tests {
public:
	void runAllTests();
	void testDomain();
	void testRepo();
	void testValidate();
	void testService();
	void testMyVector();
	void testReteta();
};