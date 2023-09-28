#pragma once
#include "vector"
#include "domain.h"

class Repo {
private:
	vector<Student> list;
	string fName;
	void loadFromFile();
	void writeToFile();
public:
	
	Repo(string file) : fName{ file } {
		loadFromFile();
	}
	void save_to_file(vector<Student> lst);
	vector<Student>& get_all() { return list; };
	void remove(int nrMAtricol);
};