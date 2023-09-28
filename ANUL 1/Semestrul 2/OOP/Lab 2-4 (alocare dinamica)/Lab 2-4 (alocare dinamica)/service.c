#pragma once
#include "service.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "sort.h"

//Adauga o oferta in agentie
int addOferta(OfertaStore* store, int id, char* tip, int suprafata, char* adresa, int pret) {
	Oferta o = createOferta(id, tip, suprafata, adresa, pret);
	int err = valideazaOferta(o);
	if (err == 0) {
		destroyOferta(&o);
		return err;
	}
	add(&store->allOferte, o);
	return 1;
}

OfertaStore createOfertaStore() {
	OfertaStore rez;
	rez.allOferte = createEmpty();
	return rez;
}

void destroyStore(OfertaStore* store) {
	destroy(&store->allOferte);
}

int findOferta(MyList* store, int id) {
	int poz_to_delete = -1;
	for (int i = 0; i < store->lg; i++) {
		Oferta o = get(store, i);
		if (id == o.id) {
			poz_to_delete = i;
			break;
		}
	}
	return poz_to_delete;
}

int modifyOferta(OfertaStore* store, int id, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou) {
	int poz_to_delete = findOferta(&store->allOferte, id);
	if (poz_to_delete != -1) {
		Oferta ofertaNoua = createOferta(id, tip_nou, suprafata_noua, adresa_noua, pret_nou);
		Oferta o = get(&store->allOferte, poz_to_delete);
		destroyOferta(&o);
		setElem(&store->allOferte, poz_to_delete, ofertaNoua);
		return 1;
	}
	return 0;
}

int deleteOferta(OfertaStore* store, int id) {
	int poz_to_delete = findOferta(&store->allOferte, id);
	if (poz_to_delete != -1) {
		Oferta o = delete(&store->allOferte, poz_to_delete);
		destroyOferta(&o);
		return 1;
	}
	return 0;
}

int cmpTip(Oferta* o1, Oferta* o2) {
	return strcmp(o1->tip, o2->tip);
}

int cmpPret(Oferta* o1, Oferta* o2) {
	/*if (o1->pret > o2->pret) {
		return 1;
	}
	else if (o1->pret < o2->pret) {
		return -1;
	}
	else
		return 0;*/
	return o1->pret > o2->pret;
}

MyList sortPC(OfertaStore* store) {
	MyList l = copyList(&store->allOferte);
	funcSortC(&l, cmpPret);
	return l;
}

MyList sortPD(OfertaStore* store) {
	MyList l = copyList(&store->allOferte);
	funcSortD(&l, cmpPret);
	return l;
}

MyList sortTC(OfertaStore* store) {
	MyList l = copyList(&store->allOferte);
	funcSortC(&l, cmpTip);
	return l;
}

MyList sortTD(OfertaStore* store) {
	MyList l = copyList(&store->allOferte);
	funcSortD(&l, cmpTip);
	return l;
}

MyList supFilter(OfertaStore* store, int suprafata) {
	MyList filteredList = createEmpty();
	if (suprafata > 0) {
		for (int i = 0; i < size(&store->allOferte); i++) {
			Oferta o = get(&store->allOferte, i);
			if (o.suprafata == suprafata)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
}

MyList tipFilter(OfertaStore* store, char* tip) {
	MyList filteredList = createEmpty();
	if (strcmp(tip, "") != 0) {
		for (int i = 0; i < size(&store->allOferte); i++) {
			Oferta o = get(&store->allOferte, i);
			if (strcmp(tip, o.tip) == 0)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
}

MyList pretFilter(OfertaStore* store, int pret) {
	MyList filteredList = createEmpty();
	if (pret > 0) {
		for (int i = 0; i < size(&store->allOferte); i++) {
			Oferta o = get(&store->allOferte, i);
			if (o.pret == pret)
				add(&filteredList, createOferta(o.id, o.tip, o.suprafata, o.adresa, o.pret));
		}
		return filteredList;
	}
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

	//ADD OFERTA IVALIDA
	int insucces1 = addOferta(&v, -1, "casa", 15, "Sibiu", 15000);
	assert(insucces1 == 0);

	int insucces2 = addOferta(&v, 1, "", 15, "Sibiu", 15000);
	assert(insucces2 == 0);

	int insucces3 = addOferta(&v, 1, "casa", -5, "Sibiu", 15000);
	assert(insucces3 == 0);

	int insucces4 = addOferta(&v, 1, "casa", 15, "", 15000);
	assert(insucces4 == 0);

	int insucces5 = addOferta(&v, 1, "casa", 15, "Sibiu", -50);
	assert(insucces5 == 0);

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
	int poz1 = findOferta(&v, 2);
	assert(poz1 == 1);

	int poz2 = findOferta(&v, 4);
	assert(poz2 == -1);
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
	OfertaStore v = createOfertaStore();

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
	destroy(&v);
	destroyStore(&v);
}

void  testtipFilter() {
	OfertaStore v = createOfertaStore();

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
	destroy(&v);
	destroyStore(&v);
}


void testpretFilter() {
	OfertaStore v = createOfertaStore();

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
	destroy(&v);
	destroyStore(&v);
}

void testSorts() {
	OfertaStore store = createOfertaStore();
	addOferta(&store, 1, "casa", 15, "Sibiu", 17000);
	addOferta(&store, 2, "teren", 15, "Sibiu", 15000);
	addOferta(&store, 3, "apartament", 16, "Sibiu", 11000);

	MyList l = sortPC(&store);
	assert(strcmp(get(&l, 2).tip, "casa") == 0);
	destroy(&l);

	l = sortPD(&store);
	assert(strcmp(get(&l, 0).tip, "casa") == 0);
	destroy(&l);

	l = sortTC(&store);
	assert(strcmp(get(&l, 0).tip, "apartament") == 0);
	destroy(&l);

	l = sortTD(&store);
	assert(strcmp(get(&l, 2).tip, "apartament") == 0);
	destroy(&l);

	destroyStore(&store);
}