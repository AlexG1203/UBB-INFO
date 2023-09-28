#pragma once
#include <string>
using std::string;
class Student
{
private:
	int nrmatricol, varsta;
	string nume, facultate;
public:
	Student(int nrmatricol, string nume, string facultate, int varsta) : nrmatricol{ nrmatricol }, varsta{ varsta }, nume{ nume }, facultate{ facultate } {};
	void setVarsta(bool operatie) noexcept;
	/*
	nu returneaza nimic
	functie pentru setat varsta
	*/
	int getVarsta() const noexcept;
	/*
	returneaza int = varsta student
	*/
	int getMatricol() const noexcept;
	/*
	returneaza int = nr matricol student
	*/
	string getNume() const noexcept;
	/*
	returneaza string = nume student
	*/
	string getFacultate() const noexcept;
	/*
	retunreaza string = facultate student
	*/
};

