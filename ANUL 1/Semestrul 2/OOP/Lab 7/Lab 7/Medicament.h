#pragma once
#include <string>
#include <iostream>

using std::string;

class Medicament {
private:
	std::string denumire;
	double pret;
	std::string producator;
	std::string substantaActiva;
public:
	Medicament() = default;
	Medicament(std::string denumire, double pret, std::string producator, std::string subst) :denumire{ denumire }, pret{ pret }, producator{ producator }, substantaActiva{ subst } {

	}
	Medicament(const Medicament& med) :denumire{ med.denumire }, pret{ med.pret }, producator{ med.producator }, substantaActiva{ med.substantaActiva } {
		//std::cout << "Copiere!\n";
	}
	string getDenumire()const;
	double getPret();
	string getProducator();
	string getSubstantaActiva();
};