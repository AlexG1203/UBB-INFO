#pragma once
#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

#include "service.h"

void printMenu() {
	printf("1. Adaugare oferta\n2. Actualizare oferta\n");
	printf("3. Sterge oferta\n4. Vizualizare oferete ordonat dupa pret, tip (crescator/descrescator)\n");
	printf("5. Vizualizare oferte filtrate dupa un criteriu (suprafata, tip, pret)\n6. Tipareste toate\n0. Iesire\n");
}

void testAll() {
	testAddService();
	testFindService();
	testModifyService();
	testDeleteService();
	testCopyList();
	testsupFilter();
	testtipFilter();
	testpretFilter();
}

void printAllOferte(MyList* v) {
	if(v->length == 0)
		printf("Nu exista oferte.\n");
	else {
		printf("Ofertele curente sunt:\n");
		for (int i = 0; i < size(v); i++)
		{
			Oferta o = get(v, i);
			printf("ID: %d | Tip: %s | Suprafata: %d | Adresa: %s | Pret: %d\n", o.id, o.tip, o.suprafata, o.adresa, o.pret);
		}
	}
}

void uiAdd(MyList* v) {
	int id, suprafata, pret;
	char tip[30], adresa[30];
	printf("ID-ul ofertei este: ");
	scanf("%d", &id);
	printf("Tipul ofertei este (teren, casa, apartament): ");
	scanf("%s", &tip);
	printf("Suprafata este: ");
	scanf("%d", &suprafata);
	printf("Adresa este: ");
	scanf("%s", &adresa);
	printf("Pretul este: ");
	scanf("%d", &pret);

	int succes = addOferta(v, id, tip, suprafata, adresa, pret);
	if (succes)
		printf("Oferta adaugata cu succes.\n");
	else
		printf("Oferta invalida.\n");
}

void uiModify(MyList* v) {
	int id, suprafata_noua, pret_nou;
	char tip_nou[30], adresa_noua[30];
	printf("Introduceti id-ul ofertei pentru modificare: ");
	scanf("%d", &id);
	printf("Tipul ofertei este (teren, casa, apartament): ");
	scanf("%s", &tip_nou);
	printf("Suprafata este: ");
	scanf("%d", &suprafata_noua);
	printf("Adresa este: ");
	scanf("%s", &adresa_noua);
	printf("Pretul este: ");
	scanf("%d", &pret_nou);

	int succes = modifyOferta(v, id, tip_nou, suprafata_noua, adresa_noua, pret_nou);
	if (succes)
		printf("Oferta modificata cu succes.\n");
	else
		printf("ID invalid.\n");
}

void uiDelete(MyList* v) {
	int id;
	printf("Introduceti id-ul ofertei pe care doriti sa o stergeti: ");
	scanf("%d", &id);

	int succes = deleteOferta(v, id);
	if (succes)
		printf("Oferta stearsa cu succes.\n");
	else
		printf("ID invalid.\n");
}

void uiSort(MyList* v) {

}

void uiFilter(MyList* v) {
	int t, suprafata, pret;
	char tip[30];
	printf("Alegeti tipul filtrarii(1.Suprafata | 2.Tip | 3.Pret): ");
	scanf("%d", &t);
	if (t == 1) {
		printf("Suprafata este: ");
		scanf("%d", &suprafata);
		MyList filteredList = supFilter(v, suprafata);
		printAllOferte(&filteredList);
	}
	else if (t == 2) {
		printf("Tipul este: ");
		scanf("%s", &tip);
		MyList filteredList = tipFilter(v, tip);
		printAllOferte(&filteredList);
	}
	else {
		printf("Pretul este: ");
		scanf("%d", &pret);
		MyList filteredList = pretFilter(v, pret);
		printAllOferte(&filteredList);
	}
}

void run() {
	MyList oferteList = createEmpty();
	int running = 1;
	while (running) {
		printMenu();
		int cmd;
		printf("Comanda este:");
		scanf("%d", &cmd);
		switch (cmd) {
		case 1:
			uiAdd(&oferteList);
			break;
		case 2:
			uiModify(&oferteList);
			break;
		case 3:
			uiDelete(&oferteList);
			break;
		case 5:
			uiFilter(&oferteList);
			break;
		case 6:
			printAllOferte(&oferteList);
			break;
		case 0:
			running = 0;
			break;
		default:
			printf("Comanda invalida!\n");
		}
	}
}

int main() {
	//run();
	testAll();
}