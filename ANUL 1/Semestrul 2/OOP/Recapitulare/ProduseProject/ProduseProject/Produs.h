#pragma once
#include <string>
using std::string;

class Produs {
private:
	int id;
	string nume;
	string tip;
	double pret;
public:
	Produs(int id, string nume, string tip, double pret) : id{ id }, nume{ nume }, tip{ tip }, pret{ pret } {}

	int getID() const noexcept {
		return id;
	}

	string getNume() const noexcept {
		return nume;
	}

	string getTip() const noexcept {
		return tip;
	}

	double getPret() const noexcept {
		return pret;
	}
};