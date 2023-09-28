#include "MedicamentStore.h"
//#include "Reteta.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include <random>

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
void MedicamentStore::addMedicament(int id, const string& denumire, int pret, const string& producator, const string& substanta) {
	Medicament m{ id,denumire,pret,producator,substanta };
	val.validate(m);
	rep.store(m);
	undoAction.push_back(std::make_unique<UndoAdauga>(rep, rep.getLength()));
}

//Sterge medicament dupa id
void MedicamentStore::delMedicament(int id) {
	Medicament medSters = rep.srcMedicamentRepo(id);
	rep.delMedicamantRepo(id);
	undoAction.push_back(make_unique<UndoSterge>(rep, medSters));
}

//Modifica medicament dupa id
void MedicamentStore::modifyMedicament(int id, const string& denumire_noua, int pret_nou, const string& producator_nou, const string& substanta_noua) {
	Medicament med_modificat{ id, denumire_noua, pret_nou, producator_nou, substanta_noua };
	Medicament medVechi = rep.srcMedicamentRepo(id);
	val.validate(med_modificat);
	rep.modifyMedicamentRepo(id, med_modificat);
	undoAction.push_back(std::make_unique<UndoModifica>(rep, medVechi, id));
}

//Modifica medicament dupa denumire
void MedicamentStore::modifyMedicamentDen(int id, const string& denumire_noua, int pret_nou, const string& producator_nou, const string& substanta_noua) {
	Medicament med_modificat{ id, denumire_noua, pret_nou, producator_nou, substanta_noua };
	Medicament medVechi = rep.srcMedicamentRepoDenumire(denumire_noua);
	val.validate(med_modificat);
	rep.modifyMedicamentRepoDen(med_modificat);
	//undoAction.push_back(std::make_unique<UndoModifica>(rep, medVechi));
}

//Cauta medicament dupa id
const Medicament& MedicamentStore::srcMedicament(int id) {
	return rep.srcMedicamentRepo(id);
}

//Cauta medicament dupa denumire
const Medicament& MedicamentStore::srcMedicamentDenumire(string denumire) {
	return rep.srcMedicamentRepoDenumire(denumire);
}

//Filtrare
/*vector<Medicament> MedicamentStore::filtreaza(function<bool(const Medicament&)> fct) {
	vector<Medicament> rez;
	for (const auto& med : rep.getAll()) {
		if (fct(med)) {
			rez.push_back(med);
		}
	}
	return rez;
}*/

//Filtreaza medicamente dupa pret
vector<Medicament> MedicamentStore::pretFilter(int pret) {
	/*return filtreaza([pret](const Medicament& m) {
		return m.getPret() < pret;
		});*/
	vector<Medicament> allMedicamente = rep.getAll();
	vector<Medicament> filteredMedicamente;
	auto id = std::copy_if(allMedicamente.begin(), allMedicamente.end(),
		std::back_inserter(filteredMedicamente),
		[&](const Medicament& med) { return abs(med.getPret() - pret) < 0.0001; });
	return filteredMedicamente;
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

//Adauga medicament in reteta dupa denumire
void MedicamentStore::adauga_reteta(string denumire) {
	//Medicament m = rep.getMedicament_denumire(denumire);
	//reteta.adauga_reteta(m);
	vector<Medicament> v{ rep.getAll() };//fac o copie	
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].getDenumire() == denumire)
			reteta.adauga_reteta(v[i]);
	}
}

//Adauga medicamente random in reteta
void MedicamentStore::adauga_reteta_random(int nr) {
	vector<Medicament> v = rep.getAll();
	for (int i = 0; i < nr; i++) {
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> dist(0, (int)v.size() - 1);
		int random_number = dist(mt);
		Medicament med = v[random_number];
		reteta.adauga_reteta(med);
	}
}

//Goleste reteta
void MedicamentStore::goleste_reteta() {
	reteta.goleste_reteta();
}

std::map<string, vector<Medicament>> MedicamentStore::creeazaRaport() {
	std::map<string, vector<Medicament>> map;
	vector<Medicament> allMeds = rep.getAll();
	if (allMeds.empty()) {
		throw MedicamentRepoException("Nu exista medicament!");
	}
	for (auto& med : allMeds) {
		string producator = med.getProducator();
		map[producator].push_back(med);
	}
	return map;
}

/*
//Afisare reteta
vector <Medicament> MedicamentStore::getAll_reteta() {
	return reteta.getAll_reteta();
}*/

//Undo
void MedicamentStore::undo() {
	if (undoAction.empty()) {
		throw exception{ "Nu mai exista operatii" };
	}
	undoAction.back()->doUndo();
	undoAction.pop_back();
}


void testAdaugaCtr() {
	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	assert(ctr.getAll().size() == 1);
	ctr.adauga_reteta("Nurofen");
	assert(ctr.getAll_reteta().size() == 1);
	ctr.adauga_reteta_random(5);
	assert(ctr.getAll_reteta().size() == 6);
	ctr.goleste_reteta();
	assert(ctr.getAll_reteta().size() == 0);

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
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
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
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.getAll().size() == 2);

	ctr.modifyMedicament(1, "NurofenModificat", 15, "Med", "snurofen");
	assert(ctr.getAll().size() == 2);
}

void testCautaMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
	ctr.addMedicament(1, "Nurofen", 15, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	assert(ctr.getAll().size() == 2);

	ctr.srcMedicament(1);
	assert(ctr.getAll().size() == 2);
}

void testFiltrareMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
	ctr.addMedicament(1, "Nurofen", 25, "MEdFarm", "snurofen");
	ctr.addMedicament(2, "Nurofen2", 12, "MEdFarm2", "snurofen2");
	vector<Medicament> filteredMedsPret = ctr.pretFilter(25);
	assert(filteredMedsPret.size() == 1);
}

void testSortareMedicament() {
	MedicamentRepo rep;
	MedicamentValidator val;
	Reteta reteta;
	MedicamentStore ctr{ rep,val,reteta };
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
}