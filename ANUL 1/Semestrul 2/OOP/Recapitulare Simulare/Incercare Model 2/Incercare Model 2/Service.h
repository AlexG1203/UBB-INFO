#pragma once
#include "Repo.h"
#include <algorithm>

class Serv {
	Repo& repo;
public:
	// constructorul
	//	repo: Repository
	Serv(Repo& repo)
		: repo{ repo } {};

	// returneaza lista cu jocuri asociata service-ului
	//	return: lista de jocuri
	auto& getList() {
		return repo.getList();
	}

	// returneaza pozitia unui anumit joc
	//	titlu: string, titlul jocului
	//	pret: unsigned, pretul jocului
	//	return: unsigned, pozitia jocului corespunzator
	int getPos(string tip) {
		Device aux{ tip, "", 0, "", 0};
		return repo.getDevice(aux);
	}

	// returneaza elementul de pe o anumita pozitie
	//	pos: unsigned, pozitia deviceului cautat
	//	return: deviceul respectiv sau exceptie daca nu exista
	Device& at(unsigned pos);

	vector<Device> sorteazaCresc();
};