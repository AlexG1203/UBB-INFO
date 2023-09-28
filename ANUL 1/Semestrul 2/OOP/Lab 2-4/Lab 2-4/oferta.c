#pragma once
#include "oferta.h"
#include <string.h>
#include <assert.h>

Oferta createOferta(int id, char* tip, int suprafata, char* adresa, int pret) {
	Oferta o;
	o.id = id;
	strcpy_s(o.tip, sizeof(o.tip), tip);
	o.suprafata = suprafata;
	strcpy_s(o.adresa, sizeof(o.adresa), adresa);
	o.pret = pret;
	return o;
}

void destroyOferta(Oferta* o) {
	o->id = -1;
	o->tip[0] = '\0';
	o->suprafata = -1;
	o->adresa[0] = '\0';
	o->pret = -1;
}