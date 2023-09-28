#pragma once
#include "Medicament.h"
#include <string>

using std::string;

class MedicamentValidator {
public:
	void validate(Medicament& medicament);
};

class ValidateException : public std::exception {
private:
	string message;

public:
	ValidateException(string msg) : message(msg) {}
	string what() {
		return message;
	}
};