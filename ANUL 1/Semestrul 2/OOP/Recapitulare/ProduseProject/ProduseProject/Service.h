#pragma once
#include "Repo.h"
class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo{ repo } {  };
	vector<Produs> getAll() { return repo.getAll(); }
	vector<Produs> filterTip(string tip);
	vector<Produs> sortAll();
	int getVoc(string nume);

	void store(int id, string nume, string tip, double pret);
	vector<string> getAllTypes();
};

