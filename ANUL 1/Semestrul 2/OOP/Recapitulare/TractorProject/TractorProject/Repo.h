#pragma once
#include <vector>
#include "Tractor.h"
#include <fstream>
#include <string>

using namespace std;

class Repo {
private:
	vector<Tractor> list;
	string fName;
	void loadFromFile();
	void writeToFile();
public:
	Repo(string file) : fName{ file } {
		loadFromFile();
	}
	void store(const Tractor& tractor);
	void deleteRepo(int id);
	void modifica(const Tractor& tractor);
	Tractor& search(int id);
	size_t size();
	vector<Tractor> getAll();
};