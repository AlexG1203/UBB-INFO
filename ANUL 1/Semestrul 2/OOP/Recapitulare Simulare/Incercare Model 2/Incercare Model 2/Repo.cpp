#include "Repo.h"

void Repo::read() {
	ifstream fin(file);
	myList.clear();
	while (!fin.eof()) {
		int an, pret;
		string tip, model, culoare;
		fin >> tip >> model >> an >> culoare >> pret;
		if (tip == "") {
			break;
		}
		myList.push_back(Device{ tip, model, an, culoare, pret });
	}
}

int Repo::getDevice(Device& dev) {
	read();
	for (unsigned i = 0; i < myList.size(); ++i) {
		if (myList.at(i) == dev) {
			return i;
		}
	}
	return -1;
}