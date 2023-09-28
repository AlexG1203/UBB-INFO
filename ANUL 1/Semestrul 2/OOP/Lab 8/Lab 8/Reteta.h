#pragma once
#include <iostream>
#include "Medicament.h"
#include <vector>

using namespace std;

class Reteta {
	vector<Medicament> lista;
public:
	void adauga_reteta(Medicament med);
	const vector<Medicament>& getAll_reteta() const noexcept;
	void goleste_reteta();
};