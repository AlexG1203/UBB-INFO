#ifndef MYSORT_H_
#define MYSORT_H_

#include "MyList.h"
/*
   Tipul functie de comparare pentru 2 elemente
   returneaza 0 daca sunt egale, 1 daca o1>o2, -1 altfel
*/
typedef int(*FunctieComparare)(Oferta* o1, Oferta* o2);

/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void funcSortC(MyList* l, FunctieComparare cmpF);
void funcSortD(MyList* l, FunctieComparare cmpF);

#endif