#pragma once
#include "MedicamentStore.h"
#include "Medicament.h"

class ConsoleUI {
	MedicamentStore& ctr;
	/*
	Citeste datele de la tastatura si adauga medicament
	arunca exceptie daca: nu se poate salva, nu e valid
	*/
	void adaugaUI();

	//Sterge medicament dupa id
	void stergeUI();

	//Modifica medicament dupa id
	void modificareUI();

	//Cauta medicament dupa id
	void cautareUI();

	//Filtare medicament dupa pret sau substanta activa
	void filtrareUI();

	//Tipareste o lista de medicamente la consola
	void tipareste(const vector<Medicament>& meds);
public:
	ConsoleUI(MedicamentStore& ctr) :ctr{ ctr } {
	}
	//nu permitem copierea obiectelor
	ConsoleUI(const ConsoleUI& ot) = delete;

	void start();
};