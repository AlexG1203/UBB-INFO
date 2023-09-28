#pragma once
#include <string>
#include <iostream>

using std::string;
using std::ostream;

class Medicament {
	int id;
	string denumire;
	int pret;
	string producator;
	string substanta;
public:
	Medicament(int i, const string den, int p, const string prod, const string sub) :id{ i }, denumire{ den }, pret{ p }, producator{ prod }, substanta{ sub } {

	}
	//constructor de copiere
	Medicament(const Medicament& ot) :id{ ot.id }, denumire{ ot.denumire }, pret{ ot.pret }, producator{ ot.producator }, substanta{ ot.substanta } {
	}

	int getID() const;

	string getDenumire() const;

	int getPret() const;

	string getProducator() const;

	string getSubstanta() const;

	string to_string_print();
};

bool cmpDemumire(const Medicament& m1, const Medicament& m2);

bool cmpProducator(const Medicament& m1, const Medicament& m2);