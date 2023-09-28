#include "Medicament.h"

string Medicament::to_string_print() {
	return "ID: " + std::to_string(this->id) + " | Denumire: " + this->denumire + " | Pret: " + std::to_string(this->pret) +
		" | Producator: " + this->producator + " | Substanta activa: " + this->substanta;
}

int Medicament::getID() const {
	return id;
}

string Medicament::getDenumire() const {
	return denumire;
}

int Medicament::getPret() const {
	return pret;
}

string Medicament::getProducator() const {
	return producator;
}

string Medicament::getSubstanta() const {
	return substanta;
}

bool cmpDemumire(const Medicament& m1, const Medicament& m2) {
	return m1.getDenumire() < m2.getDenumire();
}

bool cmpProducator(const Medicament& m1, const Medicament& m2) {
	return m1.getProducator() < m2.getProducator();
}