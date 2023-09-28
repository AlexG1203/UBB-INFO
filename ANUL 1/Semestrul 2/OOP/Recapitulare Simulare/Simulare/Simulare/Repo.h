#pragma once
#include "cutremur.h"
#include <vector>
#include <fstream>

class Repo {
private:
	vector<Cutremur> myList;
	string file;
public:
	Repo(string file) : file{ file } {};

	void read();

	vector<Cutremur>& getList() {
		read();
		return myList;
	}
};