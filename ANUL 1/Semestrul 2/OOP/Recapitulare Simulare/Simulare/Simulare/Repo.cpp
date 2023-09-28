#include "Repo.h"

void Repo::read() {
	ifstream fin(file);
	myList.clear();
	while (!fin.eof()) {
		string locatie, data;
		int intensitate, adancime;
		fin >> locatie >> data >> intensitate >> adancime;
		if (locatie == "")
			break;
		myList.push_back(Cutremur{ locatie,data,intensitate,adancime });
	}
}