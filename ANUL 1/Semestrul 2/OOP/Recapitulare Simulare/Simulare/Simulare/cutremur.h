#pragma once
#include <string>

using namespace std;

class Cutremur {
private:
	string locatie;
	string data;
	int intensitate;
	int adancime;
public:
	Cutremur(string locatie, string data, int intensitate, int adancime) :
		locatie{ locatie }, data{ data }, intensitate{ intensitate }, adancime{ adancime } {};

	string getLocatie() {
		return locatie;
	}

	string getData() {
		return data;
	}

	int getIntensitate() {
		return intensitate;
	}

	int getAdancime() {
		return adancime;
	}

	bool operator==(Cutremur& oth) {
		return locatie == oth.locatie;
	}
};