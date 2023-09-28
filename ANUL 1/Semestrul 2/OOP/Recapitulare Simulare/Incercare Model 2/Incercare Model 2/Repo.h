#pragma once
#include "device.h"
#include <vector>
#include <fstream>

class Repo {
private:
	vector<Device> myList;
	string file;
public:
	// Constructorul
	//	file : fisierul din care se citesc datele
	Repo(string file)
		: file{ file } {};

	// Citeste datele din fisierul text dat ca parametru
	//	return: se va modifica lista
	void read();

	// Returneaza pozitia unui anumit device
	//	j : referinta la un Device
	//	return: pozitia lui j in vector
	int getDevice(Device& j);

	// Returneaza lista cu deviceuri
	//	return: lista de deviceuri
	vector<Device>& getList() {
		read();
		return myList;
	}
};