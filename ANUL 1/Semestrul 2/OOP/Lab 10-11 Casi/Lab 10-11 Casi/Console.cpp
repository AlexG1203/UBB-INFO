#include "Console.h"
#include <iostream>
#include <fstream>
#include <random>

using std::cout;
using std::cin;

void Console::adaugaUI()
{
	string denumire, producator, substantaActiva;
	double pret;
	cout << "Denumire: ";
	cin >> denumire;
	cout << "Pret: ";
	cin >> pret;
	cout << "Producator: ";
	cin >> producator;
	cout << "Substanta activa: ";
	cin >> substantaActiva;
	service.addMedicament(denumire, pret, producator, substantaActiva);
	cout << "Medicament adaugat cu succes!\n";
}

void Console::tipareste(vector<Medicament> list)
{
	/*
	IteratorMyVector it = list.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		cout << "Denumire:: " << med.getDenumire() << " Pret:: " << med.getPret() << " Producator:: " << med.getProducator() << " Substanta activa:: " << med.getSubstantaActiva() << '\n';
		it.next();
	}*/

	for (auto& med : list) {
		cout << "Denumire:: " << med.getDenumire() << " Pret:: " << med.getPret() << " Producator:: " << med.getProducator() << " Substanta activa:: " << med.getSubstantaActiva() << '\n';
	}

}

void Console::tiparesteMedicamente()
{
	tipareste(service.getAllMedicamente());
}

void Console::stergeUI()
{
	string denumire;
	cout << "Denumirea medicamentului sters: ";
	cin >> denumire;
	service.stergeMedicament(denumire);
}

void Console::modificaUI()
{
	string denumire, producator, substantaActiva;
	double pret;
	cout << "Denumire medicament modificat: ";
	cin >> denumire;
	cout << "Noul pret: ";
	cin >> pret;
	cout << "Noul producator: ";
	cin >> producator;
	cout << "Noua substanta activa";
	cin >> substantaActiva;
	service.modificaMedicament(denumire, pret, producator, substantaActiva);
	cout << "Medicament modificat cu succes!\n";
}

void Console::cautaUI()
{
	string denumire;
	cout << "Denumire: ";
	cin >> denumire;
	Medicament med = service.searchMedicament(denumire);
	cout << "Denumire:: " << med.getDenumire() << " Pret:: " << med.getPret() << " Producator:: " << med.getProducator() << " Substanta activa:: " << med.getSubstantaActiva() << '\n';
}

void Console::filtrareUI()
{
	vector<Medicament> filteredMeds;
	cout << " 1. Filtrare dupa pret.\n 2. Filtrare dupa substanta activa.\n";
	int cmd;
	cin >> cmd;
	if (cmd == 1) {
		double pret;
		cout << "Pret:: ";
		cin >> pret;
		filteredMeds = service.filterMedicamentePret(pret);
		tipareste(filteredMeds);
	}
	else if (cmd == 2) {
		string substanta;
		cout << "Substanta activa:: ";
		cin >> substanta;
		filteredMeds = service.filterMedicamenteSubstantaActiva(substanta);
		tipareste(filteredMeds);
	}
	else {
		cout << "Comanda invalida!\n";
	}
}

int cmpDenumire(Medicament m1, Medicament m2) {
	return m1.getDenumire() < m2.getDenumire();
}

int cmpProducator(Medicament m1, Medicament m2) {
	return m1.getProducator() < m2.getProducator();
}

void Console::sortareUI()
{
	vector<Medicament> sortedMeds;
	int cmd;
	cout << "1.Sortare dupa denumire\n2.Sortare dupa producator\n";
	cin >> cmd;
	if (cmd == 1) {
		sortedMeds = service.sortMedicamente(cmpDenumire);
		tipareste(sortedMeds);
	}
	else if (cmd == 2) {
		sortedMeds = service.sortMedicamente(cmpProducator);
		tipareste(sortedMeds);
	}
	else {
		cout << "Comanda invalida!\n";
	}
}



void Console::run()
{
	while (true) {
		cout << "1. Adaugare medicament\n2. Stergere medicament\n3. Modificare medicament\n";
		cout << "4. Afisare medicamente\n5. Cautare medicament\n6. Filtrare medicamente\n7. Sortare medicamente\n";
		cout << "8. Reteta\n9. Creeaza raport\n10. Undo\n";
		cout << "0. Exit\n";
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 0:
				return;
			case 1:
				adaugaUI();
				break;
			case 2:
				// stergere medicament
				stergeUI();
				break;
			case 3:
				// modificare medicament
				modificaUI();
				break;
			case 4:
				// afisare medicamente
				tiparesteMedicamente();
				break;
			case 5:
				// cautare medicamente
				cautaUI();
				break;
			case 6:
				// filtrare medicamente
				filtrareUI();
				break;
			case 7:
				// sortare medicamente
				sortareUI();
				break;
			case 8:
				// ui reteta
				runUiReteta();
				break;
			case 9:
				// raport
				creeazaRaportUI();
			case 10:
				//undo
				undoUI();
			default:
				cout << "Comanda invalida!\n";
				break;
			}
		}
		catch (RepoException exception) {
			cout << exception.what();
		}
		catch (ValidateException exception) {
			cout << exception.what();
		}
	}

}

void Console::runUiReteta() {
	while (true) {
		cout << "Reteta contine " << service.getSizeReteta() << " medicamente.\n";
		cout << " ===RETETA=== \n1. Goleste reteta\n2. Adauga pe reteta\n3. Genereaza reteta\n";
		cout << "4. Export\n0. Iesire meniu reteta\n";
		int cmd;
		cin >> cmd;
		try {
			switch (cmd) {
			case 0:
				// exit meniu reteta
				return;
			case 1:
				// goleste reteta
				service.clearReteta();
				break;
			case 2:
				//adauga pe reteta
				adaugaToRetetaUI();
				break;
			case 3:
				// genereaza reteta
				genereazaRetetaUI();
				break;
			case 4:
				//export reteta
				exportToCSVFile();
				break;
			default:
				cout << "Comanda invalida!\n";
				break;
			}
		}
		catch (RepoException exception) {
			cout << exception.what();
		}

	}
}

void Console::adaugaToRetetaUI() {
	string denumire;
	cout << "Denumire: ";
	cin >> denumire;
	service.adaugaToReteta(denumire);
}

void Console::genereazaRetetaUI() {
	cout << "Numar de medicamente ::";
	int nr;
	cin >> nr;
	service.genereazaReteta(nr);
}

void Console::exportToCSVFile() {
	vector<Medicament> recipeMeds = service.getAllReteta();
	std::ofstream myfile;
	myfile.open("export.csv");
	myfile << "Denumire,Pret,Producator,Substanta activa\n";
	for (auto& med : recipeMeds) {
		myfile << med.getDenumire() + ',' << med.getPret() << ',' << med.getProducator() + ',' + med.getSubstantaActiva() + '\n';
	}
}

void Console::creeazaRaportUI()
{
	std::map<string, vector<Medicament>>map;
	map = service.creeazaRaport();
	std::map<string, vector<Medicament>>::iterator it = map.begin();
	while (it != map.end()) {
		cout << "Producator:: " << it->first << '\n';
		vector<Medicament> meds = it->second;
		for (auto& med : meds) {
			cout << "->" << med.getDenumire() << '\n';
		}
		++it;
	}
}

void Console::undoUI()
{
	service.undo();
}
