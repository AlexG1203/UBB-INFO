#pragma once
#include "Medicament.h"

#include <vector>
#include <string>
#include <ostream>

using std::vector;
using std::string;
using std::ostream;

class MedicamentRepo {
	vector<Medicament> all;
	//metoda privata verifica daca exista deja m in repository
	bool exist(const Medicament& m) const;
public:
	MedicamentRepo() = default;
	//nu permitem copierea de obiecte
	MedicamentRepo(const MedicamentRepo& ot) = delete;

	/*
	Salvare Medicament
	arunca exceptie daca mai exista un medicament cu aceeasi denumire si producator
	*/
	void store(const Medicament& m);

	//Sterge medicament dupa id
	void delMedicamantRepo(int id);

	//Modifca medicament dupa id
	void modifyMedicamentRepo(int id, const Medicament& med_de_modificat);

	//Cauta medicament dupa id
	const Medicament& srcMedicamentRepo(int id);

	/*
	Cauta Medicament
	arunca exceptie daca nu exista medicament
	*/
	const Medicament& find(string denumire, string producator) const;

	//Returneaza medicamentele date dupa o anumita denumire
	Medicament getMedicament_denumire(string denumire);

	//returneaza toate medicamentele salvate
	const vector<Medicament>& getAll() const noexcept;
};

//Folosit pentru a semnala situatii exceptionale care pot aparea in repo
class MedicamentRepoException {
	string msg;
public:
	MedicamentRepoException(string m) : msg{ m } {

	}
	//functie friend (vreau sa folosesc membru privat msg)
	friend ostream& operator<<(ostream& out, const MedicamentRepoException& ex);
};

ostream& operator<<(ostream& out, const MedicamentRepoException& ex);

void testRepo();