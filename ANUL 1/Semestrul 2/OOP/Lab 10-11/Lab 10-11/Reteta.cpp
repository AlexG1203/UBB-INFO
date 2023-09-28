#include "Reteta.h"
#include <iostream>
#include "Medicament.h"
#include "MedicamentStore.h"
#include <assert.h>

using namespace std;

void Reteta::adauga_reteta(Medicament med) {
	this->lista.push_back(med);
}

void Reteta::goleste_reteta() {
	this->lista.clear();
}

const vector<Medicament>& Reteta::getAll_reteta() const noexcept {
	return this->lista;
}

void testReteta() {
	Reteta reteta;
	Medicament m1(1, "Nurofen", 20.0, "ada", "ada");
	reteta.adauga_reteta(m1);
	Medicament m2(2, "Strepsils", 11.11, "aasa", "sad");
	reteta.adauga_reteta(m2);
	vector<Medicament> all = reteta.getAll_reteta();
	assert(all.size() == 2);
	reteta.goleste_reteta();
}