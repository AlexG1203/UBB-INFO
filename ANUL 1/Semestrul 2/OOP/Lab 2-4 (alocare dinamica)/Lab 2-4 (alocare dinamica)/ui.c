#pragma once
#pragma warning(disable : 4996)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include <stdlib.h>

#include "oferta.h"
#include "MyList.h"
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
	testIterateList();
	testResize();
	testCopyList();
	testsupFilter();
	testtipFilter();
	testpretFilter();
	testSorts();
}

void printAllOferte(MyList *v) {
	if (size(&v) == 0)
		printf("Nu exista oferte.\n");
	else {
		printf("Ofertele curente sunt:\n");
		for (int i = 0; i < size(&v); i++)
		{
			Oferta o = get(v, i);
			printf("ID: %d | Tip: %s | Suprafata: %d | Adresa: %s | Pret: %d\n", o.id, o.tip, o.suprafata, o.adresa, o.pret);
		}
	}
}

void uiAdd(OfertaStore* store) {
	int id, suprafata, pret;
	char tip[30], adresa[30];
	printf("ID-ul ofertei este: ");
	scanf("%d", &id);
	printf("Tipul ofertei este (teren, casa, apartament): ");
	scanf("%s", tip, 30);
	printf("Suprafata este: ");
	scanf("%d", &suprafata);
	printf("Adresa este: ");
	scanf("%s", adresa, 30);
	printf("Pretul este: ");
	scanf("%d", &pret);

	int succes = addOferta(store, id, tip, suprafata, adresa, pret);
	if (succes)
		printf("Oferta adaugata cu succes.\n");
	else
		printf("Oferta invalida.\n");
}

void uiModify(OfertaStore* store) {
	int id, suprafata_noua, pret_nou;
	char tip_nou[30], adresa_noua[30];
	printf("Introduceti id-ul ofertei pentru modificare: ");
	scanf("%d", &id);
	printf("Tipul ofertei este (teren, casa, apartament): ");
	scanf("%s", tip_nou, 30);
	printf("Suprafata este: ");
	scanf("%d", &suprafata_noua);
	printf("Adresa este: ");
	scanf("%s", adresa_noua, 30);
	printf("Pretul este: ");
	scanf("%d", &pret_nou);

	int succes = modifyOferta(store, id, tip_nou, suprafata_noua, adresa_noua, pret_nou);
	if (succes)
		printf("Oferta modificata cu succes.\n");
	else
		printf("ID invalid.\n");
}

void uiDelete(OfertaStore* store) {
	int id;
	printf("Introduceti id-ul ofertei pe care doriti sa o stergeti: ");
	scanf("%d", &id);

	int succes = deleteOferta(store, id);
	if (succes)
		printf("Oferta stearsa cu succes.\n");
	else
		printf("ID invalid.\n");
}

void uiSort(OfertaStore* store) {
	int s;
	printf("Doriti sa fie sortat dupa (1.Pret | 2.Tip): ");
	scanf("%d", &s);
	if (s == 1) {
		int ord;
		printf("Cum doriti sa fie sortat (1.Crescator | 2.Descrescator): ");
		scanf("%d", &ord);
		if (ord == 1) {
			MyList allOferte = sortPC(store);
			printAllOferte(&allOferte);
			destroy(&allOferte);
		}
		else if (ord == 2) {
			MyList allOferte = sortPD(store);
			printAllOferte(&allOferte);
			destroy(&allOferte);
		}
	}
	else if (s == 2) {
		int ord;
		printf("Cum doriti sa fie sortat (1.Crescator | 2.Descrescator): ");
		scanf("%d", &ord);
		if (ord == 1) {
			MyList allOferte = sortTC(store);
			printAllOferte(&allOferte);
			destroy(&allOferte);
		}
		else if (ord == 2) {
			MyList allOferte = sortTD(store);
			printAllOferte(&allOferte);
			destroy(&allOferte);
		}
	}
}

void uiFilter(OfertaStore* store) {
	int t, suprafata, pret;
	char tip[30];
	printf("Alegeti tipul filtrarii(1.Suprafata | 2.Tip | 3.Pret): ");
	scanf("%d", &t);
	if (t == 1) {
		printf("Suprafata este: ");
		scanf("%d", &suprafata);
		MyList filteredList = supFilter(store, suprafata);
		printAllOferte(&filteredList);
	}
	else if (t == 2) {
		printf("Tipul este: ");
		scanf("%s", &tip);
		MyList filteredList = tipFilter(store, tip);
		printAllOferte(&filteredList);
	}
	else {
		printf("Pretul este: ");
		scanf("%d", &pret);
		MyList filteredList = pretFilter(store, pret);
		printAllOferte(&filteredList);
	}
}

void run() {
	OfertaStore store = createOfertaStore();
	int running = 1;
	while (running) {
		printMenu();
		int cmd;
		printf("Comanda este:");
		scanf("%d", &cmd);
		switch (cmd) {
		case 1:
			uiAdd(&store);
			break;
		case 2:
			uiModify(&store);
			break;
		case 3:
			uiDelete(&store);
			break;
		case 4:
			uiSort(&store);
			break;
		case 5:
			uiFilter(&store);
			break;
		case 6:
			printAllOferte(&store);
			break;
		case 0:
			running = 0;
			break;
		default:
			printf("Comanda invalida!\n");
		}
	}
	destroyStore(&store);
}

int main() {
	//run();
	testAll();
	_CrtDumpMemoryLeaks();
	return 0;
}