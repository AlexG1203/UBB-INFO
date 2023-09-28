#pragma once
#include <algorithm>
#include "MedicamentRepo.h"
#include "validator.h"

#include <functional>

using std::function;
using std::sort;

class MedicamentStore {
	MedicamentRepo& rep;

	//Functie generala de sortare
	vector<Medicament> generalSort(bool(*maiMicF)(const Medicament&, const Medicament&));

public:
	MedicamentStore(MedicamentRepo& rep) :rep{ rep } {

	}
	//nu permitem copierea de obiecte MedicamentStore
	MedicamentStore(const MedicamentStore& ot) = delete;

	const vector<Medicament>& getAll() const;

	/*
	Adauga un nou medicament
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	void addMedicament(int id, const string denumire, int pret, const string producator, const string substanta);

	//Sterge medicament dupa id
	void delMedicament(int id);

	//Modifica medicament dupa id
	void modifyMedicament(int id, const string denumire_noua, int pret_nou, const string producator_nou, const string substanta_noua);

	//Cauta medicament dupa id
	const Medicament& srcMedicament(int id);

	//Filtrare
	vector<Medicament> filtreaza(function<bool(const Medicament&)> fct);

	//Filtreaza medicamente dupa pret
	vector<Medicament> pretFilter(int pret);

	//Sortare dupa denumire
	vector<Medicament> sortDenumire();

	//Sortare dupa producator
	vector<Medicament> sortProducator();

	//Sortare dupa substanta activa + pret
	vector<Medicament> sortSA_pret();

};

void testCtr();