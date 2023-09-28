#include "validator.h"
#include <assert.h>
#include <sstream>

void MedicamentValidator::validate(const Medicament& m) {
	vector<string> msgs;
	if (m.getID() < 0)
		msgs.push_back("ID invalid!");
	if (m.getDenumire().size() == 0)
		msgs.push_back("Denumire invalida!");
	if (m.getPret() < 0)
		msgs.push_back("Pret invalid!");
	if (m.getProducator().size() == 0)
		msgs.push_back("Producator invalida!");
	if (m.getSubstanta().size() == 0)
		msgs.push_back("Substanta invalida!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

ostream& operator<<(ostream& out, const ValidateException& ex) {
	for (const auto& msg : ex.msgs) {
		out << msg << " ";
	}
	return out;
}

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
}