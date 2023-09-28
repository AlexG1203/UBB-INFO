#include "Tests.h"
#include <iostream>
using namespace std;
void Tests::testDomain() {
	Student s{ 1, "Daniel", "info", 18 };
	assert(s.getFacultate().compare("info") == 0);
	assert(s.getMatricol() == 1);
	assert(s.getNume().compare("Daniel") == 0);
	assert(s.getVarsta() == 18);
	s.setVarsta(true);
	assert(s.getVarsta() == 19);
	s.setVarsta(false);
}

void Tests::testRepo() {
	Repo repo{ "TestFile.txt" };
	vector<Student> list = repo.getAllRepo();
	assert(list.size() == 5);
	Student s{ 123, "dada", "dada", 20 };
	repo.addRepo(s);
	assert(repo.getAllRepo().size() == 6);
	repo.deleteRepo(123);
	assert(repo.getAllRepo().size() == 5);
}

void Tests::testService() {
	Repo repo{ "TestFile.txt" };
	Service serv{ repo };
	assert(serv.getAllService().size() == 5);
	serv.addService(123, "dada", "dada", 20);
	assert(serv.getAllService().size() == 6);
	serv.deleteService(123);
	assert(serv.getAllService().size() == 5);
	assert(serv.getAllService()[0].getMatricol() == 4);
	assert(serv.getAllService()[0].getNume().compare("d") == 0);
	serv.setAgeService(true);
	serv.undo();
	try {
		serv.undo();
	}
	catch (exception) {
		assert(true);
	}
}


void Tests::testAll() {
	testDomain();
	testRepo();
	testService();
}