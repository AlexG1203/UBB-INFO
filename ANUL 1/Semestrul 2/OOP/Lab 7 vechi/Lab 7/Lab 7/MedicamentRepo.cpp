#include "MedicamentRepo.h"
#include <assert.h>

//returneaza toate animalele salvate
const vector<Medicament>& MedicamentRepo::getAll() const {
	return all;
}

void MedicamentRepo::store(const Medicament& m) {
	for (const auto& Medicament : all)
		if (Medicament.getID() == m.getID()) {
			throw exception("ID deja existent!\n");
		}
	all.push_back(m);
}

void MedicamentRepo::delMedicamantRepo(int id) {
	int i = 0;
	for (const auto& Medicament : all) {
		if (Medicament.getID() == id) {
			all.erase(all.begin() + i);
			return;
		}
		i++;
	}

	throw exception("ID invalid!");
}

void MedicamentRepo::modifyMedicamentRepo(int id, const Medicament& med_de_modificat) {
	for (auto& Medicament : all)
		if (Medicament.getID() == id) {
			Medicament = med_de_modificat;
			return;
		}
	throw exception("ID invalid!");
}

const Medicament& MedicamentRepo::srcMedicamentRepo(int id) {
	if (id >= 0) {
		for (int i = 0; i < (int)all.size(); i++) {
			if (all[i].getID() == id)
				return all[i];
		}
	}
	else {
		throw exception("ID invalid!");
	}
}

/*
bool MedicamentRepo::exist(const Medicament& m) {
	try {
		find(m.getDenumire(), m.getProducator());
		return true;
	}
	catch (MedicamentRepoException&) {
		return false;
	}
}
*/

/*
Cauta
arunca exceptie daca nu exista medicament
*/
const Medicament& MedicamentRepo::find(string denumire, string producator) {
	for (const auto& Medicament : all) {
		if (Medicament.getDenumire() == denumire && Medicament.getProducator() == producator) {
			return Medicament;
		}
	}
	//daca nu exista arunca o exceptie
	throw exception("Nu exista medicamentul!");
}

/*
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
}*/