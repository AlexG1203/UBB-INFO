#pragma once
#include "oferta.h"

typedef Oferta ElemType;
typedef struct {
	ElemType elems[100];
	int length;
}MyList;

//Creeaza o lista goala
MyList createEmpty();

//Distruge lista data si elementele sale
void destroy(MyList* v);

//Returneaza elementul de pe pozitia poz din lista data
ElemType get(MyList* v, int poz);

//Pune elementul el pe pozitia poz din lista v
ElemType setElem(MyList* v, int poz, ElemType el);

//Returneaza numarul de elemente in lista
int size(MyList* v);

//Adauga un element in lista
void add(MyList* v, ElemType el);

//Sterge un element din lista
ElemType delete(MyList* v, int poz);

//Face o copie a listei date (similar cu Python deepcopy)
MyList copyList(MyList* v);

void testCopyList();
