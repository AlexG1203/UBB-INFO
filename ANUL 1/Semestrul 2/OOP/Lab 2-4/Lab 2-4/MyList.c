#pragma once
#include "MyList.h"
#include <string.h>
#include <assert.h>

MyList createEmpty() {
	MyList v;
	v.length = 0;
	return v;
}

void destroy(MyList* v) {
	v->length = 0;
}

ElemType get(MyList* v, int poz) {
	return v->elems[poz];
}
ElemType setElem(MyList* v, int poz, ElemType el) {
	ElemType replacedElement = v->elems[poz];
	v->elems[poz] = el;
	return replacedElement;
}


int size(MyList* v) {
	return v->length;
}

void add(MyList* v, ElemType el) {
	v->elems[v->length] = el;
	v->length++;
}
ElemType delete(MyList* v, int poz) {
	ElemType el = v->elems[poz];
	for (int i = poz; i < v->length - 1; i++) {
		v->elems[i] = v->elems[i + 1];
	}
	v->length--;
	return el;
}

MyList copyList(MyList* v) {
	MyList v_copy = createEmpty();
	for (int i = 0; i < v->length; i++) {
		ElemType el = get(v, i);
		add(&v_copy, el);
	}
	return v_copy;
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
}