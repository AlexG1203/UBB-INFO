#include "MedicamentStore.h"

void MedicamentService::addMedicament(const string& denumire, double pret, const string& producator, const string& substantaActiva)
{
	Medicament medicament(denumire, pret, producator, substantaActiva);
	validator.validate(medicament);
	repo.addRepo(medicament);
}

MyVector<Medicament> MedicamentService::getAllMedicamente()
{
	return repo.getAllRepo();
}

size_t MedicamentService::nrMedicamente()
{
	return repo.sizeRepo();
}

void MedicamentService::stergeMedicament(const string& denumire)
{
	repo.deleteRepo(denumire);
}

void MedicamentService::modificaMedicament(string denumire, double pret, string producator, string substantaActiva)
{
	Medicament medicamentModified(denumire, pret, producator, substantaActiva);
	validator.validate(medicamentModified);
	repo.modifyRepo(medicamentModified);
}

Medicament MedicamentService::searchMedicament(string denumire)
{
	return repo.searchRepo(denumire);
}


MyVector<Medicament> MedicamentService::filterMedicamentePret(double pret)
{
	MyVector<Medicament> filteredMedicamente;
	MyVector<Medicament> allMedicamente = repo.getAllRepo();
	IteratorMyVector<Medicament> it = allMedicamente.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		if (abs(med.getPret() - pret) < 0.0001) {
			filteredMedicamente.add(med);
		}
		it.next();
	}
	return filteredMedicamente;
}

MyVector<Medicament> MedicamentService::filterMedicamenteSubstantaActiva(string substanta) {
	MyVector<Medicament> filteredMedicamente;
	MyVector<Medicament> allMedicamente = repo.getAllRepo();
	IteratorMyVector<Medicament> it = allMedicamente.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		if (med.getSubstantaActiva() == substanta) {
			filteredMedicamente.add(med);
		}
		it.next();
	}
	return filteredMedicamente;
}

MyVector<Medicament> MedicamentService::sortMedicamente(CompareFunction cmpF)
{
	MyVector<Medicament> allMeds = repo.getAllRepo();
	for (int i = 0; i < allMeds.size(); i++) {
		for (int j = i + 1; j < allMeds.size(); j++) {
			//daca primul element mai mare ca al doilea
			if (cmpF(allMeds.get(i), allMeds.get(j))) {
				//swap
				Medicament aux = allMeds.get(j);
				allMeds.set(j, allMeds.get(i));
				allMeds.set(i, aux);
			}
		}
	}
	return allMeds;
}

