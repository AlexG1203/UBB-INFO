#include "MedicamentRepo.h"

bool MedicamentRepo::exists(string denumire)
{
	IteratorMyVector<Medicament> it = list.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		if (med.getDenumire() == denumire) {
			return 1;
		}
		it.next();
	}
	return 0;
}

void MedicamentRepo::addRepo(Medicament& medicament)
{
	string denumire = medicament.getDenumire();
	if (exists(denumire)) {
		throw RepoException("Medicament existent!\n");
	}
	list.add(medicament);
}

MyVector<Medicament> MedicamentRepo::getAllRepo()
{
	return list;
}

void MedicamentRepo::deleteRepo(const string& denumire)
{
	bool isGasit = false;
	int poz = -1;
	for (int i = 0; i < list.size() && !isGasit; i++) {
		if (list.get(i).getDenumire() == denumire) {
			poz = i;
			isGasit = true;
		}
	}
	if (isGasit == true) {
		list.deleteElement(poz);
	}
	/*
	bool isSters = false;
	for (int i = 0; i < list.size() && !isSters; i++) {
		if (list[i].getDenumire() == denumire) {
			list.erase(list.begin()+i);
			isSters = true;
		}
	}
	*/
	if (!isGasit) {
		throw RepoException("Medicament inexistent!\n");
	}
}

void MedicamentRepo::modifyRepo(const Medicament& medicament)
{
	bool isModified = false;
	for (int i = 0; i < list.size() && !isModified; i++) {
		if (medicament.getDenumire() == list.get(i).getDenumire()) {
			list.set(i, medicament);
			isModified = true;
		}
	}
	if (!isModified) {
		throw RepoException("Medicament inexistent!\n");
	}
}

size_t MedicamentRepo::sizeRepo()
{
	return list.size();
}

const Medicament& MedicamentRepo::searchRepo(const std::string& denumire)
{
	IteratorMyVector<Medicament> it = list.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		if (med.getDenumire() == denumire) {
			return med;
		}
		it.next();
	}

	/*
	for (auto& med : list) {
		if (med.getDenumire() == denumire) {
			return med;
		}
	}
	*/
	throw RepoException("Medicamentul nu a fost gasit!\n");
}
