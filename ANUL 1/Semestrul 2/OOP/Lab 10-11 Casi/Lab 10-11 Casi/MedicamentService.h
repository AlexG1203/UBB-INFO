#pragma once
#include "MedicamentRepo.h"
#include "MedicamentRepoFile.h"
#include "MedicamentValidator.h"
#include "Reteta.h"
#include "ActiuneUndo.h"
#include <map>

class MedicamentService {
private:
	MedicamentRepo& repo;
	MedicamentValidator& validator;
	Reteta& reteta;
	vector<std::unique_ptr<ActiuneUndo>> undoActions;
public:
	MedicamentService(MedicamentRepo& r, MedicamentValidator& v, Reteta& reteta) : repo{ r }, validator{ v }, reteta{ reteta } {}
	void addMedicament(const string& denumire, double pret, const string& producator, const string& substantaActiva);
	vector<Medicament> getAllMedicamente();
	size_t nrMedicamente();
	void stergeMedicament(const string& denumire);
	void modificaMedicament(string denumire, double pret, string producator, string substantaActiva);
	Medicament searchMedicament(string denumire);
	vector<Medicament> filterMedicamentePret(double pret);
	vector<Medicament> filterMedicamenteSubstantaActiva(string substanta);

	vector<Medicament> sortMedicamenteDenumire();

	vector<Medicament> sortMedicamenteProducator();

	typedef int (*CompareFunction)(Medicament med1, Medicament med2);
	vector<Medicament> sortMedicamente(CompareFunction cmpF);

	void clearReteta();
	void adaugaToReteta(const string& denumire);
	vector<Medicament> getAllReteta();
	size_t getSizeReteta();
	void genereazaReteta(int nr_medicamente);

	std::map<string, vector<Medicament>> creeazaRaport();
	void undo();
};