#pragma once
#include "MedicamentRepo.h"
#include "validator.h"

class MedicamentService {
private:
	MedicamentRepo repo;
	MedicamentValidator validator;
public:
	MedicamentService(MedicamentRepo r, MedicamentValidator v) : repo{ r }, validator{ v } { }
	void addMedicament(const string& denumire, double pret, const string& producator, const string& substantaActiva);
	MyVector<Medicament> getAllMedicamente();
	size_t nrMedicamente();
	void stergeMedicament(const string& denumire);
	void modificaMedicament(string denumire, double pret, string producator, string substantaActiva);
	Medicament searchMedicament(string denumire);
	MyVector<Medicament> filterMedicamentePret(double pret);
	MyVector<Medicament> filterMedicamenteSubstantaActiva(string substanta);

	typedef int (*CompareFunction)(Medicament med1, Medicament med2);
	MyVector<Medicament> sortMedicamente(CompareFunction cmpF);
};