#include "MedicamentRepoFile.h"
#include <fstream>

void MedicamentRepoFile::loadFromFile() {
	std::ifstream in(fName);
	if (!in.is_open()) {
		throw MedicamentRepoException("Error open:" + fName);
	}
	while (!in.eof()) {
		int id;
		in >> id;
		string denumire;
		in >> denumire;
		if (in.eof())break;
		int pret;
		in >> pret;
		string producator;
		in >> producator;
		string substantaActiva;
		in >> substantaActiva;
		Medicament med{ id,denumire,pret,producator,substantaActiva };
		MedicamentRepo::store(med);
	}
	in.close();
}

void MedicamentRepoFile::writeToFile()
{
	std::ofstream out(fName);
	if (!out.is_open()) {
		throw MedicamentRepoException("Error open file");
	}
	for (auto& med : getAll()) {
		out << med.getID();
		out << std::endl;
		out << med.getDenumire();
		out << std::endl;
		out << med.getPret();
		out << std::endl;
		out << med.getProducator();
		out << std::endl;
		out << med.getSubstanta();
		out << std::endl;
	}
	out.close();
}