#pragma once
#include "repo.h"
#include <algorithm>
#include <exception>
class Service
{
private:
	Repo& repo;
	vector<bool> operatii;
public:
	Service(Repo& repo) : repo{ repo } {};

	vector<Student> getAllService();
	/*
	returneaza vector cu studentii din service
	*/

	//vector<Student> getSortedList();

	void deleteService(int nrmatricol);
	/*
	sterge din lista studentul cu nr matricol

	*/

	void addService(int nrmatricol, string nume, string facultate, int varsta);
	/*
	adauga in lista studentul cu inputul dat
	*/
	void setAgeService(bool op);
	/*
	in functie de val param op
	dec sau inc varstele
	*/

	void undo();
};

