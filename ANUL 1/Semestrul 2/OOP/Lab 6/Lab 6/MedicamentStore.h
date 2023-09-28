#pragma once

#include "Medicament.h"
#include "MedicamentRepo.h"
#include <string>
#include <vector>

#include <functional>
#include "validator.h"

using std::vector;
using std::function;

class MedicamentStore {
	MedicamentRepo& rep;
	MedicamentValidator& val;

	//Functie generala de sortare
	vector<Medicament> generalSort(bool(*maiMicF)(const Medicament&, const Medicament&));

public:
	MedicamentStore(MedicamentRepo& rep, MedicamentValidator& val) :rep{ rep }, val{ val } {

	}
	//nu permitem copierea de obiecte MedicamentStore
	MedicamentStore(const MedicamentStore& ot) = delete;

	//returneaza toate medicamentele in ordinea in care au fost adaugate
	const vector<Medicament>& getAll() noexcept {
		return rep.getAll();
	}

	/*
	Adauga un nou medicament
	arunca exceptie daca: nu se poate salva, nu este valid
	*/
	void addMedicament(int id, const string& denumire, int pret, const string& producator, const string& substanta);

	//Sterge medicament dupa id
	void delMedicament(int id);

	//Modifica medicament dupa id
	void modifyMedicament(int id, const string& denumire_noua, int pret_nou, const string& producator_nou, const string& substanta_noua);

	//Cauta medicament dupa id
	const Medicament &srcMedicament(int id);

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