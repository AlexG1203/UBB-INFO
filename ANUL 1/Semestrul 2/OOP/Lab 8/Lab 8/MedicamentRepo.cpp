#include "MedicamentRepo.h"
#include <assert.h>
#include <iostream>
#include <sstream>

using std::ostream;
using std::stringstream;

void MedicamentRepo::store(const Medicament& m) {
	if (exist(m)) {
		throw MedicamentRepoException("Exista deja medicamentul " + m.getDenumire() + " produs de " + m.getProducator());
	}
	all.push_back(m);
}

void MedicamentRepo::delMedicamantRepo(int id) {
	if (id >= 0) {
		int poz_elem_del;
		for (int i = 0; i < (int)all.size(); i++) {
			if (all[i].getID() == id) {
				poz_elem_del = i;
				break;
			}
		}
		if (poz_elem_del == 0)
			all.erase(all.begin(), all.begin() + 1);
		else {
			all.erase(all.begin() + poz_elem_del);
		}
	}
	else {
		throw MedicamentRepoException("ID invalid!");
	}
}

void MedicamentRepo::modifyMedicamentRepo(int id, const Medicament& med_de_modificat) {
	if (id >= 0) {
		for (int i = 0; i < (int)all.size(); i++) {
			if (all[i].getID() == id) {
				all[i] = med_de_modificat;
				break;
			}
		}
	}
	else {
		throw MedicamentRepoException("ID invalid!");
	}
}

const Medicament& MedicamentRepo::srcMedicamentRepo(int id) {
	/*if (id >= 0) {
		for (int i = 0; i < (int)all.size(); i++) {
			if (all[i].getID() == id)
				return all[i];
		}
	}
	else {
		throw MedicamentRepoException("ID invalid!");
	}*/
	const auto it = std::find_if(all.begin(), all.end(), [&](const Medicament& med) {
		return med.getID() == id;
		});
	if (it != all.end()) {
		return *it;
	}
	throw MedicamentRepoException("ID invalid!");
}

bool MedicamentRepo::exist(const Medicament& m) const {
	try {
		find(m.getDenumire(), m.getProducator());
		return true;
	}
	catch (MedicamentRepoException&) {
		return false;
	}
}

/*
Cauta
arunca exceptie daca nu exista medicament
*/
const Medicament& MedicamentRepo::find(string denumire, string producator) const {
	for (const auto& m : all) {
		if (m.getDenumire() == denumire && m.getProducator() == producator) {
			return m;
		}
	}
	//daca nu exista arunca o exceptie
	throw MedicamentRepoException("Nu exista medicamentul " + denumire + " produs de " + producator);
}

/*
Medicament MedicamentRepo::getMedicament_denumire(string denumire) {
	for (auto m : all) {
		if (m.getDenumire() == denumire)
			return m;
	}
	throw MedicamentRepoException("Denumire invalida!");
}
*/

//returneaza toate animalele salvate
const vector<Medicament>& MedicamentRepo::getAll() const noexcept {
	return all;
}

ostream& operator<<(ostream& out, const MedicamentRepoException& ex) {
	out << ex.msg;
	return out;
}

void testAdauga() {
	MedicamentRepo rep;
	rep.store(Medicament{ 1, "Nurofen", 15, "MedFarm", "snurofen" });
	assert(rep.getAll().size() == 1);
	assert(rep.find("Nurofen", "MedFarm").getDenumire() == "Nurofen");

	rep.store(Medicament{ 2, "Nurofen2", 152, "MedFarm2", "snurofen2" });
	assert(rep.getAll().size() == 2);

	try {
		rep.store(Medicament{ 1, "Nurofen", 15, "MedFarm", "snurofen" });
		assert(false);
	}
	catch (const MedicamentRepoException&) {
		assert(true);
	}

	try {
		rep.find("adas", "asdsd");
		assert(false);
	}
	catch (const MedicamentRepoException& e) {
		stringstream os;
		os << e;
		assert(os.str().find("exista") >= 0);
	}


}

void testSterge() {
	MedicamentRepo rep;
	rep.store(Medicament{ 1, "Nurofen", 15, "MedFarm", "snurofen" });
	assert(rep.getAll().size() == 1);
	assert(rep.find("Nurofen", "MedFarm").getDenumire() == "Nurofen");

	rep.store(Medicament{ 2, "Nurofen2", 152, "MedFarm2", "snurofen2" });
	assert(rep.getAll().size() == 2);

	try {
		rep.delMedicamantRepo(-3);
		assert(false);
	}
	catch (const MedicamentRepoException&) {
		assert(true);
	}
}

void testModifica() {
	MedicamentRepo rep;
	rep.store(Medicament{ 1, "Nurofen", 15, "MedFarm", "snurofen" });
	assert(rep.getAll().size() == 1);
	assert(rep.find("Nurofen", "MedFarm").getDenumire() == "Nurofen");

	rep.store(Medicament{ 2, "Nurofen2", 152, "MedFarm2", "snurofen2" });
	assert(rep.getAll().size() == 2);

	try {
		rep.modifyMedicamentRepo(-3, Medicament{ 3,"ad",5,"asd","asd" });
		assert(false);
	}
	catch (const MedicamentRepoException&) {
		assert(true);
	}
}

void testCauta() {
	MedicamentRepo rep;
	rep.store(Medicament{ 1, "Nurofen", 15, "MedFarm", "snurofen" });
	assert(rep.getAll().size() == 1);

	rep.store(Medicament{ 2, "Nurofen2", 152, "MedFarm2", "snurofen2" });
	assert(rep.getAll().size() == 2);

	try {
		rep.srcMedicamentRepo(-3);
		assert(false);
	}
	catch (MedicamentRepoException&) {
		assert(true);
	}
}

void testRepo() {
	testAdauga();
	testSterge();
	testModifica();
	testCauta();
}