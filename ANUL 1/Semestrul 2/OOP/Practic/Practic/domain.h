#pragma once
#include <string>

using namespace std;

class Student {
private:
	int nrMatricol;
	string nume;
	int varsta;
	string facultate;
public:
	Student(int nrMAtricol, string nume, int varsta, string facultate) : nrMatricol{ nrMatricol }, nume{ nume }, varsta{ varsta }, facultate{ facultate } {}

	int getNrMatricol() const noexcept {
		return nrMatricol;
	}

	string getNume() const noexcept {
		return nume;
	}

	int getVarsta() const noexcept {
		return varsta;
	}

	string getFacultate() const noexcept {
		return facultate;
	}

};