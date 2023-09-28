#include "Console.h"
#include <iostream>

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

void Console::tipareste(MyVector<Medicament> list)
{
	IteratorMyVector<Medicament> it = list.begin();
	while (it.valid()) {
		Medicament& med = it.element();
		cout << "Denumire:: " << med.getDenumire() << " Pret:: " << med.getPret() << " Producator:: " << med.getProducator() << " Substanta activa:: " << med.getSubstantaActiva() << '\n';
		it.next();
	}
	/*
	for (auto& med : list) {
		cout << "Denumire:: " << med.getDenumire() << " Pret:: " << med.getPret() << " Producator:: " << med.getProducator() << " Substanta activa:: " << med.getSubstantaActiva() << '\n';
	}
	*/
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
	MyVector<Medicament> filteredMeds;
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
	return m1.getDenumire() > m2.getDenumire();
}

int cmpProducator(Medicament m1, Medicament m2) {
	return m1.getProducator() > m2.getProducator();
}

void Console::sortareUI()
{
	MyVector<Medicament> sortedMeds;
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
