#pragma once
#include "MedicamentRepo.h"

class MedicamentRepoFile : public MedicamentRepo {
	std::string fName;
	void loadFromFile();
	void writeToFile();
public:
	MedicamentRepoFile(std::string fName) : MedicamentRepo(), fName{ fName } {
		loadFromFile();
	}
	void store(const Medicament& m)override{
		MedicamentRepo::store(m);
		writeToFile();
	}
	void delMedicamantRepo(int id)override {
		MedicamentRepo::delMedicamantRepo(id);
		writeToFile();
	}
};