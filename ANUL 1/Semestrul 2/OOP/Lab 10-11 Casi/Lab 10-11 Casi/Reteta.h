#pragma once
#include "Medicament.h"
#include <vector>

using std::vector;

class Reteta {
private:
	vector<Medicament> v;
public:
	void add(Medicament& medicament);
	void clear();
	size_t size();
	vector<Medicament> getAll();
};