#include "MedicamentStore.h"
#include <functional>
#include <algorithm>
#include <assert.h>

const vector<Medicament>& MedicamentStore::getAll() const {
	return rep.getAll();
}

vector<Medicament> MedicamentStore::generalSort(bool(*maiMicF)(const Medicament&, const Medicament&)) {
	vector<Medicament> v{ rep.getAll() };//fac o copie	
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = i + 1; j < v.size(); j++) {
			if (!maiMicF(v[i], v[j])) {
				//interschimbam
				Medicament aux = v[i];
				v[i] = v[j];
				v[j] = aux;
			}
		}
	}
	return v;
}

/*
Adauga un nou medicament
arunca exceptie daca: nu se poate salva, nu este valid
*/
void MedicamentStore::addMedicament(int id, const string denumire, int pret, const string producator, const string substanta) {
	Medicament m{ id,denumire,pret,producator,substanta };
	validate::Medicament(m);
	rep.store(m);
}

//Sterge medicament dupa id
void MedicamentStore::delMedicament(int id) {
	validate::id(id);
	rep.delMedicamantRepo(id);
}

//Modifica medicament dupa id
void MedicamentStore::modifyMedicament(int id, const string denumire_noua, int pret_nou, const string producator_nou, const string substanta_noua) {
	validate::id(id);
	Medicament med_modificat{ id, denumire_noua, pret_nou, producator_nou, substanta_noua };
	validate::Medicament(med_modificat);
	rep.modifyMedicamentRepo(id, med_modificat);
}

//Cauta medicament dupa id
const Medicament& MedicamentStore::srcMedicament(int id) {
	return rep.srcMedicamentRepo(id);
}

//Filtrare
vector<Medicament> MedicamentStore::filtreaza(function<bool(const Medicament&)> fct) {
	vector<Medicament> rez;
	for (const auto& med : rep.getAll()) {
		if (fct(med)) {
			rez.push_back(med);
		}
	}
	return rez;
}

//Filtreaza medicamente dupa pret
vector<Medicament> MedicamentStore::pretFilter(int pret) {
	return filtreaza([pret](const Medicament& m) {
		return m.getPret() < pret;
		});
}

//Sorteaza medicament dupa denumire
vector<Medicament> MedicamentStore::sortDenumire() {
	auto copyAll = rep.getAll();
	std::sort(copyAll.begin(), copyAll.end(), cmpDemumire);
	return copyAll;
}

//Sorteaza medicament dupa producator
vector<Medicament> MedicamentStore::sortProducator() {
	auto copyAll = rep.getAll();
	std::sort(copyAll.begin(), copyAll.end(), cmpProducator);
	return copyAll;
}

//Sorteaza medicament dupa substanta activa + pret
vector<Medicament> MedicamentStore::sortSA_pret() {
	return generalSort([](const Medicament& m1, const Medicament& m2) {
		if (m1.getSubstanta() == m2.getSubstanta()) {
			return m1.getPret() < m2.getPret();
		}
		return m1.getSubstanta() < m2.getSubstanta();
		});
}

/*
void testAdaugaCtr() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	assert(ctr.getAll().size() == 1);

	//adaug medicament incvalid
	try {
		ctr.addMedicament(-1, "asdd", 15, "asdad", "asdasd");
		assert(false);
	}
	catch (ValidateException&) {
		assert(true);
	}
}

void testStergeMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.getAll().size() == 2);

	ctr.delMedicament(2);
	assert(ctr.getAll().size() == 1);

	ctr.delMedicament(1);
	assert(ctr.getAll().size() == 0);

}

void testModificaMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.getAll().size() == 2);

	ctr.modifyMedicament(1, "NurofenModificat", 15, "Med", "snurofen");
	assert(ctr.getAll().size() == 2);
}

void testCautaMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.getAll().size() == 2);

	ctr.srcMedicament(1);
	assert(ctr.getAll().size() == 2);
}

void testFiltrareMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen", 25, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.pretFilter(20).size() == 1);
	assert(ctr.pretFilter(30).size() == 2);
}

void testSortareMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	MedicamentStore ctr{ rep,val };
	ctr.addMedicament(1, "Nurofen3", 25, "MEdFarm3", "snurofen3");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm1", "snurofen2");
	ctr.addMedicament(2, "Nurofen1", 12, "MEdFarm2", "snurofen2");

	auto firstM = ctr.sortDenumire()[0];
	assert(firstM.getDenumire() == "Nurofen1");

	firstM = ctr.sortProducator()[0];
	assert(firstM.getProducator() == "MEdFarm1");

	firstM = ctr.sortSA_pret()[0];
	assert(firstM.getPret() == 12);
}

void testCtr() {
	testAdaugaCtr();
	testStergeMedicament();
	testModificaMedicament();
	testCautaMedicament();
	testFiltrareMedicament();
	testSortareMedicament();
}*/