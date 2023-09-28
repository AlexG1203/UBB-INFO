#pragma once
#include "service.h"
#include <assert.h>
#include <string.h>

int addOferta(MyList* v, int id, char* tip, int suprafata, char* adresa, int pret) {
	Oferta o = createOferta(id, tip, suprafata, adresa, pret);
	add(v, o);
	return 1;
}

int findOferta(MyList* v, int id) {
	int poz_to_delete = -1;
	for (int i = 0; i < v->length; i++) {
		Oferta o = get(v, i);
		if (id == o.id) {
			poz_to_delete = i;
			break;
		}
	}
	return poz_to_delete;
}

int modifyOferta(MyList* v, int id, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou) {
	int poz_to_delete = findOferta(v, id);
	if (poz_to_delete != -1) {
		Oferta ofertaNoua = createOferta(id, tip_nou, suprafata_noua, adresa_noua, pret_nou);
		Oferta o = get(v, poz_to_delete);
		destroyOferta(&o);
		setElem(v, poz_to_delete, ofertaNoua);
		return 1;
	}
	return 0;
}

int deleteOferta(MyList* v, int id) {
	int poz_to_delete = findOferta(v, id);
	if (poz_to_delete != -1) {
		Oferta o = delete(v, poz_to_delete);
		destroyOferta(&o);
		return 1;
	}
	return 0;
}

MyList supFilter(MyList* v, int suprafata) {
	MyList filteredList = createEmpty();
	if (suprafata > 0) {
		for (int i = 0; i < v->length; i++) {
			Oferta o = get(v, i);
			if (o.suprafata == suprafata)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
	return copyList(v);
}

MyList tipFilter(MyList* v, char* tip) {
	MyList filteredList = createEmpty();
	if (strcmp(tip, "") != 0) {
		for (int i = 0; i < v->length; i++) {
			Oferta o = get(v, i);
			if (strcmp(tip, o.tip) == 0)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
	return copyList(v);
}

MyList pretFilter(MyList* v, int pret) {
	MyList filteredList = createEmpty();
	if (pret > 0) {
		for (int i = 0; i < v->length; i++) {
			Oferta o = get(v, i);
			if (o.pret == pret)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
	return copyList(v);
}

void testAddService() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	assert(size(&v) == 1);
	Oferta o = get(&v, 0);

	assert(o.id == 1);
	assert(strcmp(o.tip, "casa") == 0);
	assert(o.suprafata == 15);
	assert(strcmp(o.adresa, "Sibiu") == 0);
	assert(o.pret == 15000);
	destroy(&v);

}

void testFindService() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "apartament", 15, "Sibiu", 15000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	int poz = findOferta(&v, 2);

	assert(poz == 1);

	destroy(&v);

}

void testModifyService() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "apartament", 15, "Sibiu", 15000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	int mod_of1 = modifyOferta(&v, 2, "teren", 25, "Medias", 18000);
	assert(mod_of1 == 1);

	int mod_of2 = modifyOferta(&v, 4, "teren", 25, "Medias", 18000);
	assert(mod_of2 == 0);
	destroy(&v);
}

void testDeleteService() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "apartament", 15, "Sibiu", 15000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	int succes_del1 = deleteOferta(&v, 2);
	assert(succes_del1 == 1);
	int succes_del2 = deleteOferta(&v, 5);
	assert(succes_del2 == 0);
	destroy(&v);
}

void testsupFilter() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "apartament", 16, "Sibiu", 15000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	MyList filteredList = supFilter(&v, 15);
	assert(size(&filteredList) == 2);
	destroy(&filteredList);

	filteredList = supFilter(&v, 0);
	assert(size(&filteredList) == 3);
	destroy(&filteredList);

	destroy(&v);
}

void  testtipFilter() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "casa", 16, "Sibiu", 15000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	MyList filteredList = tipFilter(&v, "casa");
	assert(size(&filteredList) == 2);
	destroy(&filteredList);

	filteredList = tipFilter(&v, "");
	assert(size(&filteredList) == 3);
	destroy(&filteredList);

	destroy(&v);
}


void testpretFilter() {
	MyList v = createEmpty();

	int succes1 = addOferta(&v, 1, "casa", 15, "Sibiu", 15000);
	assert(succes1 == 1);

	int succes2 = addOferta(&v, 2, "teren", 15, "Sibiu", 15000);
	assert(succes2 == 1);

	int succes3 = addOferta(&v, 3, "apartament", 16, "Sibiu", 158000);
	assert(succes3 == 1);

	assert(size(&v) == 3);
	MyList filteredList = pretFilter(&v, 15000);
	assert(size(&filteredList) == 2);
	destroy(&filteredList);

	filteredList = pretFilter(&v, 0);
	assert(size(&filteredList) == 3);
	destroy(&filteredList);

	destroy(&v);
}