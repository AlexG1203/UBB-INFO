#include "MedicamentRepoFile.h"
#include <fstream>

void MedicamentRepoFile::loadFromFile()
{
	std::ifstream in(fName);
	if (!in.is_open()) {
		throw RepoException("Error open:" + fName);
	}
	while (!in.eof()) {
		string denumire;
		in >> denumire;
		if (in.eof())break;
		double pret;
		in >> pret;
		string producator;
		in >> producator;
		string substantaActiva;
		in >> substantaActiva;
		Medicament med{ denumire,pret,producator,substantaActiva };
		MedicamentRepo::addRepo(med);
	}
	in.close();
}

void MedicamentRepoFile::writeToFile()
{
	std::ofstream out(fName);
	if (!out.is_open()) {
		string msg("Error open file");
		throw RepoException(msg);
	}
	for (auto& med : getAllRepo()) {
		out << med.getDenumire();
		out << std::endl;
		out << med.getPret();
		out << std::endl;
		out << med.getProducator();
		out << std::endl;
		out << med.getSubstantaActiva();
		out << std::endl;
	}
	out.close();
}
