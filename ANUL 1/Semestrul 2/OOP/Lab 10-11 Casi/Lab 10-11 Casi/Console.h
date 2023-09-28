#pragma once
#include "MedicamentService.h"
#include <map>

class Console {
private:
	MedicamentService& service;
	void adaugaUI();
	void tipareste(vector<Medicament> list);
	void tiparesteMedicamente();
	void stergeUI();
	void modificaUI();
	void cautaUI();
	void filtrareUI();
	void sortareUI();
	void runUiReteta();
	void adaugaToRetetaUI();
	void genereazaRetetaUI();
	void exportToCSVFile();
	void creeazaRaportUI();
	void undoUI();
public:
	Console(MedicamentService& service) :service{ service } { }
	void run();
};