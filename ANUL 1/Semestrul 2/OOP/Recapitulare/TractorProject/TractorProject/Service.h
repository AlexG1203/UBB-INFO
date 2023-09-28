#pragma once
#include "Repo.h"
class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {  };
	vector<Tractor> getAll() { return repo.getAll(); }
	vector<Tractor> filterTip(string tip);
	vector<Tractor> sortAll();

	void store(int id, string denumire, string tip, int nrRoti);
	void modifica(int id, string denumire, string tip, int nrRoti);
	vector<string> getAllTypes();
};