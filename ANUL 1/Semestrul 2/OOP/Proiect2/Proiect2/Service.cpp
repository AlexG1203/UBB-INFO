#include "Service.h"


vector<Student> Service::getAllService() {
	vector<Student> list = repo.getAllRepo();

	sort(list.begin(), list.end(), [&](const Student& s1, const Student& s2) {
		return s1.getVarsta() < s2.getVarsta();
		});

	return list;
}

void Service::deleteService(int matricol) {
	repo.deleteRepo(matricol);
}

void Service::addService(int nrmatricol, string nume, string facultate, int varsta) {
	Student s{ nrmatricol, nume , facultate , varsta };
	repo.addRepo(s);
}

void Service::setAgeService(bool op) {
	operatii.push_back(op);
	repo.setAgeRepo(op);
}

void Service::undo() {
	if (operatii.size() < 1) {
		throw std::exception("Nu mai exista undo");
	}
	else {
		bool opact = operatii[operatii.size() - 1];
		operatii.pop_back();
		repo.setAgeRepo(!opact);
	}
}