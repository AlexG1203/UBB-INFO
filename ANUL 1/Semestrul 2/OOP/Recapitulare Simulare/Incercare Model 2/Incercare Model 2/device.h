#pragma once
#include <string>

using namespace std;

class Device {
private:
	string tip;
	string model;
	int an;
	string culoare;
	int pret;
public:
	Device(string tip, string model, int an, string culoare, int pret) : tip{ tip }, model{ model }, an{ an }, culoare{ culoare }, pret{ pret } {};

	Device() = default;

	string getTip() {
		return tip;
	}

	string getModel() {
		return model;
	}

	int getAn() {
		return an;
	}

	string getCuloare() {
		return culoare;
	}

	int getPret() {
		return pret;
	}

	bool operator==(Device& oth) {
		return tip == oth.tip;
	}
};