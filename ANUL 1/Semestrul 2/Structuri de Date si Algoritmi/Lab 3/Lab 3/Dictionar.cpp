#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

/// Teta(1)
Nod::Nod(TElem e, PNod urm, PNod pre) {
	/// constructor
	this->e = e;
	this->urm = urm;
	this->pre = pre;
}

/// Teta(1)
TElem Nod::element() {
	return e;
}

/// Teta(1)
PNod Nod::urmator() {
	return urm;
}

/// Teta(1)
PNod Nod::precedent() {
	return this->pre;
}

/// Teta(1)
Dictionar::Dictionar() {
	/// constructor , setam inceputul cu null
	this->Inceput = NULL;
	this->len = 0;
}

/// Teta(n)
Dictionar::~Dictionar() {
	/// trecem prim toate elementele ramase in lista pentru a le sterge din memorie
	while (this->Inceput != nullptr)
	{
		PNod p = this->Inceput;
		this->Inceput = this->Inceput->urm;
		delete p;
	}
}

/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
TValoare Dictionar::adauga(TCheie c, TValoare v) {
	/// Adaugam un element in dictionar daca acesta nu exista deja
	/// daca cheia are deja o valoare ii schimbam valoarea
	/// returnam valoarea cheii precedente sau NULL_TVALOARE daca cheia nu avea 
	/// valoare

	TElem e;
	e.first = c;
	e.second = v;
	PNod newp = new Nod(e, nullptr, nullptr);

	if (this->Inceput == nullptr)
	{
		this->Inceput = newp;
		this->len = 1;
		return NULL_TVALOARE;
	}

	PNod p = this->Inceput;
	while (p->urmator() != nullptr)
	{
		if (c == p->element().first)
		{
			TValoare aux = p->e.second;
			p->e.second = v;
			return aux;
		}
		p = p->urmator();
	}

	if (c == p->element().first)
	{
		TValoare aux = p->e.second;
		p->e.second = v;
		return aux;
	}

	if (p->urm != nullptr)
	{
		p->urm->pre = newp;
		newp->urm = p->urm;
	}
	p->urm = newp;
	newp->pre = p;
	this->len++;

	return NULL_TVALOARE;
}


/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
	/// Cautam in dictionar o cheie data
	/// returnam NULL_TVALOARE daca nu exista cheia

	PNod p = this->Inceput;
	while (p != nullptr)
	{
		if (c == p->element().first)
			return p->e.second;
		p = p->urmator();
	}

	return NULL_TVALOARE;
}


/// caz favoranil : Teta(1)
/// caz defavorabil : Teta(n)
/// caz mediu : Teta(n)
/// overall case : O(n)
TValoare Dictionar::sterge(TCheie c) {
	/// stergem o cheie din dinctionar daca aceasta exista
	/// si ii returnam valoarea
	/// daca nu exista returnam NULL_TVALOARE
	/// + dam free la memoria stearsa

	if (this->Inceput == nullptr)
		return NULL_TVALOARE;

	PNod p = this->Inceput;
	if (c == p->element().first)
	{
		PNod p_aux = this->Inceput;
		TValoare aux = p->e.second;
		this->Inceput = p->urm;
		if (this->Inceput != nullptr)
			this->Inceput->pre = nullptr;
		delete p_aux;
		this->len--;
		return aux;
	}

	while (p->urmator() != nullptr)
	{
		if (c == p->element().first)
		{
			PNod p_aux = p;
			TValoare aux = p->e.second;
			p = p->pre;
			if (p->urm->urm != nullptr)
				p->urm->urm->pre = p;
			p->urm = p->urm->urm;
			delete p_aux;
			this->len--;
			return aux;
		}
		p = p->urmator();
	}

	if (c == p->element().first)
	{
		PNod p_aux = p;
		TValoare aux = p->e.second;
		p->pre->urm = nullptr;
		p = nullptr;
		this->len--;
		delete p_aux;
		return aux;
	}

	return NULL_TVALOARE;
}

/*
TValoare Dictionar::ceaMaiFrecventaValoare(const Dictionar& d) const {
	if (d.vid() == true)
		return NULL_TVALOARE;
	PNod p = this->Inceput;
	int f[1000] = { 0 };
	while (p != nullptr)
	{
		f[p->element().second]++;
		p = p->urmator();
	}
	int maxi = -9999, rez = -1;
	for (int i = 0; i < 1000; i++) {
		if (f[i] != 0) {
			if (f[i] > maxi) {
				maxi = f[i];
				rez = i;
			}
		}
	}
	return rez;
}
*/

/// Teta(1)
int Dictionar::dim() const {
	/// returnam variabila care tine cont de lungime

	return this->len;
}


/// Teta(1)
bool Dictionar::vid() const {
	/// Verificam daca disctionarul este vid
	/// (verifica, daca inceputul listei este nullptr)
	return this->Inceput == nullptr;
}


/// Teta(1)
IteratorDictionar Dictionar::iterator() const {
	// se returneaza iterator pe dictionar
	return  IteratorDictionar(*this);
}