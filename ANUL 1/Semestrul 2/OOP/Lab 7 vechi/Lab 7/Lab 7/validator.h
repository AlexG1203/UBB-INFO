#pragma once
/*#include <string>
#include "Medicament.h"
#include <vector>

using std::vector;
using std::string;
using std::ostream;

class ValidateException {
	vector<string> msgs;
public:
	ValidateException(const vector<string>& errors) :msgs{ errors } {}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class MedicamentValidator {
public:
	void validate(const Medicament& m);
};

void testValidator();
*/

#include <exception>
#include "Medicament.h"

using std::exception;

class validate {
public:
	static const void Medicament(const Medicament& medicament) {
		char msg[100] = "";
		if (medicament.getID() < 0)
			strcat_s(msg, "ID invalid!\n");
		if (medicament.getDenumire().size() == 0)
			strcat_s(msg, "Denumire invalida!");
		if (medicament.getPret() < 0)
			strcat_s(msg, "Pret invalid!");
		if (medicament.getProducator().size() == 0)
			strcat_s(msg, "Producator invalida!");
		if (medicament.getSubstanta().size() == 0)
			strcat_s(msg, "Substanta invalida!");

		if (strlen(msg))
			throw exception(msg);
	}

	static const void id(const int& id) {
		if (id < 0)
			throw exception("ID invalid!\n");
	}

	static const void denumire(const string& denumire) {
		if (denumire.size() < 0)
			throw exception("Denumire invalida!\n");
	}

	static const void pret(const int& pret) {
		if (pret < 0)
			throw exception("Pret invalid!\n");
	}

	static const void producator(const string& producator) {
		if (producator.size() < 0)
			throw exception("Producator invalid!\n");
	}

	static const void substanta(const string& substanta) {
		if (substanta.size() < 0)
			throw exception("Substanta invalida!\n");
	}
};