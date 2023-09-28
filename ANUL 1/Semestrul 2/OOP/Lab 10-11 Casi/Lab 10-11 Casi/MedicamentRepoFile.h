#pragma once
#include "MedicamentRepo.h"
class MedicamentRepoFile : public MedicamentRepo {
private:
	std::string fName;
	void loadFromFile();
	void writeToFile();
public:
	MedicamentRepoFile(std::string fName) :MedicamentRepo(), fName{ fName } {
		loadFromFile();
	}
	void addRepo(const Medicament& medicament)override {
		MedicamentRepo::addRepo(medicament);
		writeToFile();
	}
	void deleteRepo(const string& denumire)override {
		MedicamentRepo::deleteRepo(denumire);
		writeToFile();
	}
	void modifyRepo(const Medicament& medicament)override {
		MedicamentRepo::modifyRepo(medicament);
		writeToFile();
	}
};