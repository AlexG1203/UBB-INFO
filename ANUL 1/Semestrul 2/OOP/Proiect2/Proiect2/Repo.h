#pragma once
#include "Domain.h"
#include <vector>
#include <sstream>
#include <fstream>
using std::vector;
class Repo
{
private:
	vector<Student> list;
	string FilePath;
public:
	Repo(string FilePath) : FilePath{ FilePath } {};

	vector<Student>& getAllRepo();
	/*
	returneaza vectrot<student> = studentii din lista
	*/

	void deleteRepo(int matricol);
	/*
	functie de stergere
	sterge din list , student cu nr matricol
	*/

	void addRepo(Student s);
	/*
	functie adaugare
	adauga student s in list
	*/

	void readAllFromFile();
	/*
	citire din fisier
	*/

	void writeAllToFile();
	/*
	afisare modificari in fisier
	*/
	void setAgeRepo(bool op);
	/*
	incrementeaza sau decrementeaza varsta studentilor in functie de val op
	true = inc
	false = dec
	*/
};

