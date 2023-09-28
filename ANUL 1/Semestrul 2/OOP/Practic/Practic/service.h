#pragma once
#include "repo.h"

using namespace std;

class Service {
private:
	Repo& repo;
public:
	explicit Service(Repo& repo) :repo(repo) {};

	vector<Student>sort_lista();
	vector<Student> get_all_srv() { return sort_lista(); };
	vector<string> getAllTypes();
	void remove_srv(int nrMatricol);
	void Intinerire(int nrMatricol);
};