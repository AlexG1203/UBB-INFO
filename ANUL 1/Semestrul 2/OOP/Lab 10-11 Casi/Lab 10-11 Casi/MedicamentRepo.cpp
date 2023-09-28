#include "MedicamentRepo.h"

bool sameDenumire(string denumire, Medicament med) {
	return med.getDenumire() == denumire;
}

bool MedicamentRepo::exists(string denumire)
{
	/*
	for (auto& m : list) {
		if (m.getDenumire() == denumire) {
			return 1;
		}
	}
	vector<Medicament>::iterator it = std::find_if(list.begin(), list.end(), );
	if(it == list.end())
		return 0;
	return 1;
	*/
	const auto it = std::find_if(list.begin(), list.end(), [&](const Medicament& med) {
		return med.getDenumire() == denumire;
		});
	if (it != list.end())
		return 1;
	return 0;
}


void MedicamentRepo::addRepo(const Medicament& medicament)
{
	string denumire = medicament.getDenumire();
	if (exists(denumire)) {
		throw RepoException("Medicament existent!\n");
	}
	list.push_back(medicament);
}

vector<Medicament> MedicamentRepo::getAllRepo()
{
	return list;
}

void MedicamentRepo::deleteRepo(const string& denumire)
{
	const auto it = std::find_if(list.begin(), list.end(), [&](const Medicament& med) {
		return med.getDenumire() == denumire;
		});
	if (it != list.end()) {
		list.erase(it);
		return;
	}

	/*
	bool isGasit = false;
	int poz = -1;
	for (int i = 0; i < list.size() && !isGasit; i++) {
		if (list[i].getDenumire() == denumire) {
			poz = i;
			isGasit = true;
		}
	}
	if (isGasit == true) {
		list.erase(list.begin() + poz);
	}
	*/
	/*
	bool isSters = false;
	for (int i = 0; i < list.size() && !isSters; i++) {
		if (list[i].getDenumire() == denumire) {
			list.erase(list.begin()+i);
			isSters = true;
		}
	}
	*/
	throw RepoException("Medicament inexistent!\n");
}

void MedicamentRepo::modifyRepo(const Medicament& medicament)
{
	bool isGasit = false;
	int poz = -1;
	string denumire = medicament.getDenumire();
	const auto it = std::find_if(list.begin(), list.end(), [&](const Medicament& med) {
		poz++;
		return med.getDenumire() == denumire;
		});
	if (it != list.end()) {
		isGasit = true;
	}
	if (isGasit) {
		list[poz] = medicament;
	}
	if (!isGasit) {
		throw RepoException("Medicament inexistent!\n");
	}
	/*
	bool isModified = false;
	for (int i = 0; i < list.size() && !isModified; i++) {
		if (medicament.getDenumire() == list[i].getDenumire()) {
			list[i] = medicament;
			isModified = true;
		}
	}
	if (!isModified) {
		throw RepoException("Medicament inexistent!\n");
	}
	*/
}

size_t MedicamentRepo::sizeRepo()
{
	return list.size();
}

const Medicament& MedicamentRepo::searchRepo(const std::string& denumire)
{
	const auto it = std::find_if(list.begin(), list.end(), [&](const Medicament& med) {
		return med.getDenumire() == denumire;
		});
	if (it != list.end()) {
		return *it;
	}
	/*
	for (auto& med : list) {
		if (med.getDenumire() == denumire) {
			return med;
		}
	}
	*/
	throw RepoException("Medicament inexistent!\n");
}
