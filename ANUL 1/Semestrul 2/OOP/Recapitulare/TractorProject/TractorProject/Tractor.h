#pragma once
#include <string>

using namespace std;

class Tractor {
private:
	int id;
	string denumire;
	string tip;
	int nrRoti;
public:
	Tractor(int id, string denumire, string tip, int nrRoti) : id{ id }, denumire{ denumire }, tip{ tip }, nrRoti{ nrRoti } {}

	int getID()const noexcept {
		return id;
	}

	string getDenumire()const noexcept {
		return denumire;
	}

	string getTip()const noexcept {
		return tip;
	}

	int getNrRoti()const noexcept {
		return nrRoti;
	}
};