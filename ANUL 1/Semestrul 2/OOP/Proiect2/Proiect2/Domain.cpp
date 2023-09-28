#include "Domain.h"


void Student::setVarsta(bool operatie) noexcept {
	if (operatie)
		this->varsta++;
	else
		this->varsta--;
}

int Student::getMatricol() const noexcept {
	return this->nrmatricol;
}

int Student::getVarsta() const noexcept {
	return this->varsta;
}

string Student::getNume() const noexcept {
	return this->nume;
}

string Student::getFacultate() const noexcept {
	return this->facultate;
}