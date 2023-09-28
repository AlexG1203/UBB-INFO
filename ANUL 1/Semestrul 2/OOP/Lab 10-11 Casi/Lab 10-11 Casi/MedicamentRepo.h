#pragma once
#include "Medicament.h"
#include <string>
#include <vector>
#include "MyVector.h"

using std::vector;
using std::string;

class MedicamentRepo {
private:
	vector<Medicament> list;

public:
	/*
	return 1 daca exista un medicament cu denumirea denumire, 0 altfel
	*/
	bool exists(string denumire);

	MedicamentRepo() = default;
	MedicamentRepo(const MedicamentRepo& ot) = delete;

	/*
	adauga un medicament in repo
	daca exista deja un medicament cu aceeasi denumire, atunci va arunca exceptie
	*/
	virtual void addRepo(const Medicament& medicament);
	/*
	returneaza un vector cu toate medicamentele stocate in repo
	*/
	vector<Medicament> getAllRepo();
	/*
	sterge din repo medicamentul cu denumirea denumire
	daca nu exista un medicament cu denumirea denumire, atunci va arunca exceptie
	*/
	virtual void deleteRepo(const string& denumire);
	/*
	modifica in repo medicamentul cu denumirea lui medicament
	*/
	virtual void modifyRepo(const Medicament& medicament);
	/*
	returneaza numarul de elemente stocate in repo
	*/
	size_t sizeRepo();
	/*
	cauta medicamentul cu denumirea denumire,
	arunca exceptie daca nu exista
	*/
	const Medicament& searchRepo(const string& denumire);

};

class RepoException : public std::exception {
private:
	string message;

public:
	RepoException(string msg) : message(msg) {}
	string what() {
		return message;
	}
};