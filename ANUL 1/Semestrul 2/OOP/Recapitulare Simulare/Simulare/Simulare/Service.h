#pragma once
#include "Repo.h"
#include <algorithm>

class Serv {
	Repo& repo;
public:
	Serv(Repo& repo) : repo{ repo } {};

	auto& getList() {
		return repo.getList();
	}
	
	vector<Cutremur> addCutremur(string& locatie, string& data, int intensitate, int adincime);
};