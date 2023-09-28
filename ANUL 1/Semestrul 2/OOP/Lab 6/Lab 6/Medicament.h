#pragma once
#include <string>
#include <iostream>

using std::string;
using std::cout;

class Medicament {
	int id;
	std::string denumire;
	int pret;
	std::string producator;
	std::string substanta;
public:
	Medicament(int i, const string den, int p, const string prod, const string sub) :id{ i }, denumire { den }, pret{ p }, producator{ prod }, substanta{ sub } {

	}
	//constructor de copiere
	Medicament(const Medicament& ot) :id{ot.id}, denumire{ot.denumire}, pret{ot.pret}, producator{ot.producator}, substanta{ot.substanta} {
	}

	int getID() const noexcept {
		return id;
	}

	string getDenumire() const {
		return denumire;
	}

	int getPret() const noexcept {
		return pret;
	}

	string getProducator() const {
		return producator;
	}

	string getSubstanta() const {
		return substanta;
	}

	string to_string_print();
};

bool cmpDemumire(const Medicament& m1, const Medicament& m2);

bool cmpProducator(const Medicament& m1, const Medicament& m2);