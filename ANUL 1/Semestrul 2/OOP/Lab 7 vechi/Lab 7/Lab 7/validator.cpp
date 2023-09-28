#include "validator.h"
#include <assert.h>

/*
void testValidator() {
	MedicamentValidator v;
	Medicament m{ -1,"",-5,"","" };
	try {
		v.validate(m);
	}
	catch (const ValidateException& ex) {
		std::stringstream sout;
		sout << ex;
		auto mesaj = sout.str();
		assert(mesaj.find("invalid") >= 0);
	}
}*/