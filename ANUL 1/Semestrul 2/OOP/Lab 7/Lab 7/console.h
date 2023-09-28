#pragma once
#include "MedicamentStore.h"



class Console {
private:
	MedicamentService service;
	void adaugaUI();
	void tipareste(MyVector<Medicament> list);
	void tiparesteMedicamente();
	void stergeUI();
	void modificaUI();
	void cautaUI();
	void filtrareUI();
	void sortareUI();
public:
	Console(MedicamentService service) :service{ service } { }
	void run();
};