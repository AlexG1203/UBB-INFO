#pragma once
#include "oferta.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//Creeaza o noua oferta
Oferta createOferta(int id, char* tip, int suprafata, char* adresa, int pret) {
	Oferta o;
	o.id = id;
	size_t nrC = strlen(tip) + 1;
	o.tip = malloc(sizeof(char) * nrC);
	strcpy_s(o.tip, nrC, tip);
	o.suprafata = suprafata;
	nrC = strlen(adresa) + 1;
	o.adresa = malloc(sizeof(char) * nrC);
	strcpy_s(o.adresa, nrC, adresa);
	o.pret = pret;
	return o;
}

//Deloca memoria ocupata de oferta
void destroyOferta(Oferta* o) {
	free(o->tip);
	free(o->adresa);
	o->tip = NULL;
	o->adresa = NULL;
	o->id = -1;
	o->suprafata = -1;
	o->pret = -1;
}

//Creeaza o copie pentru oferta
Oferta copyOferta(Oferta* o) {
	createOferta(o->id, o->tip, o->suprafata, o->adresa, o->pret);
}

int valideazaOferta(Oferta o) {
	if (o.id < 0) {
		return 0;
	}
	if (strlen(o.tip) == 0) {
		return 0;
	}
	if (o.suprafata < 0) {
		return 0;
	}
	if (strlen(o.adresa) == 0) {
		return 0;
	}
	if (o.pret < 0) {
		return 0;
	}
	return 1;
}

