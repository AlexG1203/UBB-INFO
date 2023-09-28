#include "sort.h"

/**
* Sorteaza in place
* cmpf - relatia dupa care se sorteaza
*/
void funcSortC(MyList* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < size(l); i++) {
		for (j = i + 1; j < size(l); j++) {
			Oferta o1 = get(l, i);
			Oferta o2 = get(l, j);
			if (cmpF(&o1, &o2) > 0) {
				//interschimbam
				setElem(l, i, o2);
				setElem(l, j, o1);
			}
		}
	}
}

void funcSortD(MyList* l, FunctieComparare cmpF) {
	int i, j;
	for (i = 0; i < size(l); i++) {
		for (j = i + 1; j < size(l); j++) {
			Oferta o1 = get(l, i);
			Oferta o2 = get(l, j);
			if (cmpF(&o1, &o2) < 0) {
				//interschimbam
				setElem(l, i, o2);
				setElem(l, j, o1);
			}
		}
	}
}