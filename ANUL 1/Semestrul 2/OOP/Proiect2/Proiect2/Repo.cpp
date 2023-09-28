#include "Repo.h"


vector<Student>& Repo::getAllRepo() {
	readAllFromFile();
	return this->list;
}


void Repo::deleteRepo(int matricol) {
	readAllFromFile();
	auto it = find_if(list.begin(), list.end(), [&](const Student& s) {
		return s.getMatricol() == matricol;
		});

	int poz = distance(list.begin(), it);
	list.erase(list.begin() + poz);
	writeAllToFile();
}

void Repo::addRepo(Student s) {
	readAllFromFile();
	list.push_back(s);
	writeAllToFile();
}


void Repo::readAllFromFile() {
	std::ifstream fin(FilePath);
	list.clear();

	string line;
	string atribut;
	vector<string> atribute;
	while (getline(fin, line)) {
		std::stringstream linestream(line);
		while (getline(linestream, atribut, ',')) {
			atribute.push_back(atribut);
		}
		Student s{ std::stoi(atribute[0]),atribute[1],atribute[2], std::stoi(atribute[3]) };
		list.push_back(s);
		atribute.clear();
	}
}

void Repo::writeAllToFile() {
	std::ofstream fout(FilePath);
	//if (!fout.is_open()) throw RepoException("File repo couldn t be opened");

	for (auto& s : list) {
		fout << s.getMatricol() << "," << s.getNume() << "," << s.getFacultate() << "," <<
			s.getVarsta() << std::endl;
	}

	fout.close();
}

void Repo::setAgeRepo(bool op) {
	readAllFromFile();
	/*auto it = find_if(list.begin(), list.end(), [&](const Student& s) {
		return s.getMatricol() == nrmatricol;
		});
	int poz = distance(list.begin(), it);*/
	for (auto& el : list) {
		el.setVarsta(op);
	}
	//list[poz].setVarsta(op);
	writeAllToFile();
}