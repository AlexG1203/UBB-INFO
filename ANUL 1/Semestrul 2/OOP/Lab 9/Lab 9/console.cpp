#include "console.h"
#include "Export.h"
#include "Medicament.h"
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::ws;

void ConsoleUI::tipareste(const vector<Medicament>& meds) {
	if (meds.size() != 0)
		cout << "Medicamentele din farmacie sunt:\n";
	else
		cout << "Nu exista medicamente!\n";
	for (const auto& med : meds) {
		cout << "ID: " << med.getID() << " | Denumire: " << med.getDenumire() << " | Pret: " << med.getPret() << " | Producator: " << med.getProducator() << " | Substanta activa: " << med.getSubstanta() << "\n";
	}
	cout << "\n";
}

void ConsoleUI::adaugaUI() {
	string den, prod, sub;
	int id, pr;
	cout << "Introduceti ID-ul: ";
	cin >> id;
	cout << "Introduceti denumirea: ";
	cin >> den;
	cout << "Introduceti pretul: ";
	cin >> pr;
	cout << "Introduceti producatorul: ";
	cin >> prod;
	cout << "Introduceti substanta activa: ";
	cin >> sub;
	ctr.addMedicament(id, den, pr, prod, sub);
	cout << "Medicament adaugat cu succes!\n\n";
}

void ConsoleUI::stergeUI() {
	int id;
	cout << "Introduceti id-ul medicamentului pe care doriti sa il stergeti: ";
	cin >> id;
	ctr.delMedicament(id);
	cout << "Medicament sters cu succes!\n\n";
}

void ConsoleUI::modificareUI() {
	int id;
	cout << "Introduceti id-ul medicamentului pe care doriti sa il modificati: ";
	cin >> id;
	string den_noua, prod_nou, sub_noua;
	int  pr_nou;
	cout << "Introduceti noua denumirea: ";
	cin >> den_noua;
	cout << "Introduceti noul pretul: ";
	cin >> pr_nou;
	cout << "Introduceti noul producatorul: ";
	cin >> prod_nou;
	cout << "Introduceti noua substanta activa: ";
	cin >> sub_noua;
	ctr.modifyMedicament(id, den_noua, pr_nou, prod_nou, sub_noua);
	cout << "Medicament modificat cu succes!\n\n";
}

void ConsoleUI::cautareUI() {
	int id;
	cout << "Introduceti id-ul medicamentului pe care doriti sa il cautati: ";
	cin >> id;
	Medicament to_print = ctr.srcMedicament(id);
	cout << "Medicamentul este: " << to_print.to_string_print() << "\n\n";
}

void ConsoleUI::adaugaRetetaUI() {
	string den;
	cout << "Introduceti o denumire existenta: ";
	cin >> den;
	ctr.adauga_reteta(den);
}

////Adauga medicamente random in cos
void ConsoleUI::adaugaRetetaRandomUI() {
	int nr;
	cout << "Introduceti numarul de medicamente random: ";
	cin >> nr;
	ctr.adauga_reteta_random(nr);
}

void ConsoleUI::golesteRetetaUI() {
	ctr.goleste_reteta();
}

void ConsoleUI::creeazaRaportUI() {
	std::map<string, vector<Medicament>>map;
	map = ctr.creeazaRaport();
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

void ConsoleUI::undoUI() {
	ctr.undo();
}

void ConsoleUI::start() {
	while (true) {
		cout << "Meniu:\n";
		cout << "1.Adauga medicament\n2.Sterge medicament\n3.Modificare\n4.Cauat medicament\n5.Filtrare medicament\n6.Sortare medicament\n7.Afiseaza toate medicamentele\n--------Reteta--------\n8.Adauga medicament in reteta medicament dupa denumire\n9.Afiseaza reteta\n10.Adauga medicamente random in reteta\n11.Goleste reteta\n12.Creeaza raport\n13.Undo la ultima operatie\n0.Iesire\nIntroduceti comanda: ";
		int cmd;
		cin >> cmd;
		cout << "\n";
		try {
			switch (cmd) {
			case 1:
				adaugaUI();
				break;
			case 2:
				stergeUI();
				break;
			case 3:
				modificareUI();
				break;
			case 4:
				cautareUI();
				break;
			case 5:
				int pret;
				cout << "Pretul este: ";
				cin >> pret;
				tipareste(ctr.pretFilter(pret));
				break;
			case 6:
				int t, den, prod, sa_p;
				cout << "Sortati dupa (1.Denumire | 2.Producator | 3.Substanta activa + pret): ";
				cin >> t;
				if (t == 1) {
					tipareste(ctr.sortDenumire());
					break;
				}
				else if (t == 2) {
					tipareste(ctr.sortProducator());
					break;
				}
				else if (t == 3) {
					tipareste(ctr.sortSA_pret());
					break;
				}
			case 7:
				tipareste(ctr.getAll());
				break;
			case 8:
			{
				adaugaRetetaUI();
				string nume_fisier;
				cout << "Nume fisier unde exporti medicamentele: ";
				cin >> nume_fisier;
				vector<Medicament> all = ctr.getAll_reteta();
				exportToCSV(nume_fisier, all);
				break;
			}
			case 9:
				/* {
				vector <Medicament> med = ctr.getAll_reteta();
				for (auto i : med) {
					cout << i.getID() << "," << i.getDenumire() << "," << i.getPret() << "," << i.getProducator() << "," << i.getSubstanta() << endl;
				}
				break;
				}*/
				tipareste(ctr.getAll_reteta());
				break;
			case 10:
			{
				adaugaRetetaRandomUI();
				string nume_fisier;
				cout << "Nume fisier unde exporti medicamentele random: ";
				cin >> nume_fisier;
				vector<Medicament> all = ctr.getAll_reteta();
				exportToCSV(nume_fisier, all);
				break;
			}
			case 11:
			{
				string nume_fisier;
				cout << "Nume fisier unde golesti medicamentele din reteta: ";
				cin >> nume_fisier;
				vector<Medicament> all = ctr.getAll_reteta();
				golesteRetetaUI();
				exportToCSV(nume_fisier, all);
				break;
			}
			case 12:
				creeazaRaportUI();
				break;
			case 13:
				undoUI();
				break;
			case 0:
				return;
			default:
				cout << "Comanda invalida\n";
			}
		}
		catch (const MedicamentRepoException& ex) {
			cout << ex << "\n";
		}
		catch (const ValidateException& ex) {
			cout << ex << '\n';
		}
	}
}