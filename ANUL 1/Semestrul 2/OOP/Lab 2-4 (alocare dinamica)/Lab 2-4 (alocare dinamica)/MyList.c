#pragma once
#include "MyList.h"
#include <string.h>
#include <assert.h>
#include <stdlib.h>

//Creeaza o lista goala
MyList createEmpty() {
	MyList rez;
	rez.lg = 0;
	rez.cap = 4;
	rez.elems = malloc(sizeof(ElemType) * rez.cap);
	return rez;
}

//Distruge lista
void destroy(MyList* v) {
	//deloca oferte
	for (int i = 0; i < v->lg; i++){
		destroyOferta(&v->elems[i]);
	}
	free(v->elems);
	//make harder to miss-use after destroy
	v->elems = NULL;
	v->lg = 0;
}

/*
Ia un element din lista
poz - pozitia elementului, trebuie sa fie valida
returneaza elemnetul de pe pozitia data
*/
ElemType get(MyList* v, int poz) {
	return v->elems[poz];
}

/*
Modifica elementul de pe pozitia data
Returneaza elementul suprascris
*/
ElemType setElem(MyList* v, int poz, Oferta el) {
	ElemType rez = v->elems[poz];
	v->elems[poz] = el;
	return rez;
}

//Returneaza numarul elementelor din lista
int size(MyList* v) {
	return v->lg;
}

//Aloca mai multa memorie daca este nevoie
void ensureCapacity(MyList* l) {
	if (l->lg < l->cap) {
		return; //avem spatiu
	}
	//aloca mai multa memorie
	int newCapacity = l->cap + 2;
	ElemType* nElems = malloc(sizeof(ElemType) * newCapacity);
	//copiaza elementele
	for (int i = 0; i < l->lg; i++) {
		nElems[i] = l->elems[i];
	}
	//dealoca vectorul vechi
	free(l->elems);
	l->elems = nElems;
	l->cap = newCapacity;
}

/*
Adauga elementele in lista
(elementul este adaugat la sfarsitul listei)
*/
void add(MyList* v, ElemType el) {
	ensureCapacity(v);
	v->elems[v->lg] = el;
	v->lg++;
}

//Sterge elementul din lista
ElemType delete(MyList* v, int poz) {
	ElemType el = v->elems[poz];
	for (int i = poz; i < v->lg - 1; i++) {
		v->elems[i] = v->elems[i + 1];
	}
	v->lg--;
	return el;
}

//Face o copie listei
MyList copyList(MyList* v) {
	MyList rez = createEmpty();
	for (int i = 0; i < size(v); i++) {
		ElemType el = get(v, i);
		add(&rez, copyOferta(&el));
	}
	return rez;
}

void testIterateList() {
	MyList l = createEmpty();
	add(&l, createOferta(1, "casa", 15, "Sibiu", 15000));
	add(&l, createOferta(2, "casa", 16, "Sibiu", 16000));
	assert(size(&l) == 2);
	Oferta o = get(&l, 0);

	assert(o.id == 1);
	o = get(&l, 1);
	assert(strcmp(o.tip, "casa") == 0);
	destroy(&l);
	assert(size(&l) == 0);
}

void testCopyList() {
	MyList v1 = createEmpty();
	add(&v1, createOferta(1, "teren", 15, "Sibiu", 15000));
	add(&v1, createOferta(2, "casa", 18, "Sibiu", 18000));

	assert(size(&v1) == 2);
	MyList v2 = copyList(&v1);
	assert(size(&v2) == 2);
	Oferta o = get(&v2, 0);
	assert(strcmp(o.adresa, "Sibiu") == 0);
	destroy(&v1);
	destroy(&v2);
}

void testResize() {
	MyList l = createEmpty();
	for (int i = 0; i < 10; i++) {
		add(&l, createOferta(1, "teren", 15, "Sibiu", 15000));
	}
	assert(size(&l) == 10);
	destroy(&l);
	assert(size(&l) == 0);
	assert(l.elems == NULL);
}