#pragma once
#include "Medicament.h"
#include <string>
#include <vector>
#include "Vector.h"

using std::vector;
using std::string;

class MedicamentRepo {
private:
	MyVector<Medicament> list;
	/*
	return 1 daca exista un medicament cu denumirea denumire, 0 altfel
	*/
	bool exists(string denumire);
public:
	MedicamentRepo() = default;
	/*
	adauga un medicament in repo
	daca exista deja un medicament cu aceeasi denumire, atunci va arunca exceptie
	*/
	void addRepo(Medicament& medicament);
	/*
	returneaza un vector cu toate medicamentele stocate in repo
	*/
	MyVector<Medicament> getAllRepo();
	/*
	sterge din repo medicamentul cu denumirea denumire
	daca nu exista un medicament cu denumirea denumire, atunci va arunca exceptie
	*/
	void deleteRepo(const string& denumire);
	/*
	modifica in repo medicamentul cu denumirea lui medicament
	*/
	void modifyRepo(const Medicament& medicament);
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