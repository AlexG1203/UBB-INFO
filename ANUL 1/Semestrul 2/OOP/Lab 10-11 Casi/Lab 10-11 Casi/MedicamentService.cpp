#include "MedicamentService.h"
#include <random>

void MedicamentService::addMedicament(const string& denumire, double pret, const string& producator, const string& substantaActiva)
{
	Medicament medicament(denumire, pret, producator, substantaActiva);
	validator.validate(medicament);
	repo.addRepo(medicament);
	undoActions.push_back(std::make_unique<UndoAdauga>(UndoAdauga{ medicament,repo }));
}

vector<Medicament> MedicamentService::getAllMedicamente()
{
	return repo.getAllRepo();
}

size_t MedicamentService::nrMedicamente()
{
	return repo.sizeRepo();
}

void MedicamentService::stergeMedicament(const string& denumire)
{
	Medicament medSters = repo.searchRepo(denumire);
	repo.deleteRepo(denumire);
	undoActions.push_back(std::make_unique<UndoSterge>(UndoSterge{ medSters, repo }));
}

void MedicamentService::modificaMedicament(string denumire, double pret, string producator, string substantaActiva)
{
	Medicament medicamentModified(denumire, pret, producator, substantaActiva);
	Medicament medInitial = repo.searchRepo(denumire);
	validator.validate(medicamentModified);
	repo.modifyRepo(medicamentModified);
	undoActions.push_back(std::make_unique<UndoModifica>(UndoModifica{ medInitial, repo }));
}

Medicament MedicamentService::searchMedicament(string denumire)
{
	return repo.searchRepo(denumire);
}


vector<Medicament> MedicamentService::filterMedicamentePret(double pret)
{
	vector<Medicament> allMedicamente = repo.getAllRepo();
	vector<Medicament> filteredMedicamente;
	auto id = std::copy_if(allMedicamente.begin(), allMedicamente.end(),
		std::back_inserter(filteredMedicamente),
		[&](const Medicament& med) { return abs(med.getPret() - pret) < 0.0001; });
	/*
	for (auto& med : allMedicamente) {
		if (abs(med.getPret() - pret) < 0.0001) {
			filteredMedicamente.push_back(med);
		}
	}*/
	return filteredMedicamente;
}

vector<Medicament> MedicamentService::filterMedicamenteSubstantaActiva(string substanta) {
	vector<Medicament> allMedicamente = repo.getAllRepo();
	vector<Medicament> filteredMedicamente;
	auto id = std::copy_if(allMedicamente.begin(), allMedicamente.end(),
		std::back_inserter(filteredMedicamente),
		[&](const Medicament& med) { return med.getSubstantaActiva() == substanta;  });
	/*for (auto& med : allMedicamente) {
		if (med.getSubstantaActiva() == substanta) {
			filteredMedicamente.push_back(med);
		}
	}*/
	return filteredMedicamente;
}

int cmpDenumireServ(Medicament m1, Medicament m2) {
	return m1.getDenumire() < m2.getDenumire();
}

int cmpProducatorServ(Medicament m1, Medicament m2) {
	return m1.getProducator() < m2.getProducator();
}

vector<Medicament> MedicamentService::sortMedicamenteDenumire() {
	return sortMedicamente(cmpDenumireServ);
}

vector<Medicament> MedicamentService::sortMedicamenteProducator() {
	return sortMedicamente(cmpProducatorServ);
}

vector<Medicament> MedicamentService::sortMedicamente(CompareFunction cmpF)
{
	vector<Medicament> allMeds = repo.getAllRepo();
	sort(allMeds.begin(), allMeds.end(), cmpF);
	/*
	for (int i = 0; i < allMeds.size(); i++) {
		for (int j = i+1; j < allMeds.size(); j++) {
			//daca primul element mai mare ca al doilea
			if (cmpF(allMeds[i], allMeds[j])) {
				//swap
				Medicament aux = allMeds[j];
				allMeds[j] = allMeds[i];
				allMeds[i] = aux;
			}
		}
	}
	*/
	return allMeds;
}

void MedicamentService::clearReteta()
{
	reteta.clear();
}

void MedicamentService::adaugaToReteta(const string& denumire)
{
	if (repo.exists(denumire) == 1) {
		Medicament med = repo.searchRepo(denumire);
		reteta.add(med);
	}
	else {
		throw RepoException("Medicament inexistent!\n");
	}
}

vector<Medicament> MedicamentService::getAllReteta()
{
	return reteta.getAll();
}

size_t MedicamentService::getSizeReteta()
{
	return reteta.size();
}

void MedicamentService::genereazaReteta(int nr_medicamente)
{
	vector<Medicament> allMeds = repo.getAllRepo();
	if (allMeds.empty()) {
		throw RepoException("Nu exista medicamente!\n");
	}
	for (int i = 0; i < nr_medicamente; i++) {
		std::mt19937 mt{ std::random_device{}() };
		std::uniform_int_distribution<> dist(0, (int)(allMeds.size() - 1));
		int rndNr = dist(mt);// numar aleator intre [0,size-1]
		Medicament med = allMeds[rndNr];
		reteta.add(med);
	}
}

std::map<string, vector<Medicament>> MedicamentService::creeazaRaport()
{
	std::map<string, vector<Medicament>> map;
	vector<Medicament> allMeds = repo.getAllRepo();
	if (allMeds.empty()) {
		throw RepoException("Nu exista medicamente!\n");
	}
	for (auto& med : allMeds) {
		string producator = med.getProducator();
		map[producator].push_back(med);
	}
	return map;
}

void MedicamentService::undo()
{
	if (undoActions.empty()) {
		throw RepoException{ "Nu mai exista operatii." };
	}
	undoActions.back()->doUndo();
	undoActions.pop_back();
}



