#pragma once
#include <vector>
#include "Produs.h"
#include <fstream>
#include <string>
using namespace std;

class Repo {
private:
	vector<Produs> list;
	string fName;
	void loadFromFile();
	void writeToFile();
public:
	Repo(string file) : fName{ file } {
		loadFromFile();
	}
	void store(Produs& produs);
	Produs& search(int id);
	size_t size();
	vector<Produs> getAll();
};