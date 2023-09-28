#pragma once
#include "MedicamentStore.h"
#include "Medicament.h"
#include <map>

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

	//Adauga medicament in reteta dupa denumire
	void adaugaRetetaUI();

	//Adauga medicament random
	void adaugaRetetaRandomUI();

	//Goleste reteta
	void golesteRetetaUI();

	//Creeaza raport
	void creeazaRaportUI();

	//Undo
	void undoUI();

	//Tipareste o lista de medicamente la consola
	void tipareste(const vector<Medicament>& meds);
public:
	ConsoleUI(MedicamentStore& ctr) :ctr{ ctr } {
	}
	//nu permitem copierea obiectelor
	ConsoleUI(const ConsoleUI& ot) = delete;

	void start();
};