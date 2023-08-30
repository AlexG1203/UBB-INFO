#include "IteratorMD.h"
#include "MD.h"

using namespace std;

/// Complexitate: teta(1)
//constructorul primeste o referinta catre Container
//iteratorul va referi primul element din container
IteratorMD::IteratorMD(const MD& _md) : md(_md) {
	curent = md.prim;
	if (curent == -1)
		curentLista = -1;
	else
		curentLista = md.e[curent].second->primLista;
}

//returneaza valoarea elementului din container referit de iterator
//arunca exceptie daca iteratorul nu e valid
TElem IteratorMD::element() const {
	if (valid() == false)
		throw std::exception();

	return pair <TCheie, TValoare>(md.e[curent].first, md.e[curent].second->val[curentLista]);
}

/// Complexitate: teta(1)
//verifica daca iteratorul e valid (indica un element al containerului)
bool IteratorMD::valid() const {
	if (curentLista == -1)
		return false;

	if (curent == -1)
		return false;

	return true;
}

/// Complexiatate: teta(1)
//muta iteratorul in container
// arunca exceptie daca iteratorul nu e valid
void IteratorMD::urmator() {
	curentLista = md.e[curent].second->urmLista[curentLista];

	if (valid() == false)
	{
		curent = md.urm[curent];
		if (curent != -1)
		{
			curentLista = md.e[curent].second->primLista;
		}

	}
}

/// Complexitate: teta(1)
//reseteaza pozitia iteratorului la inceputul containerului
void IteratorMD::prim() {
	curent = md.prim;
	if (curent == -1)
		curentLista = -1;
	else
		curentLista = md.e[curent].second->primLista;
}

