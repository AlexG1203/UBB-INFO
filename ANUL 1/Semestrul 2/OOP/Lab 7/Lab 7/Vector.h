#pragma once

#include "Medicament.h"
//typedef Medicament Element;
#define INITIAL_CAPACITY 5

template <typename Element>
class IteratorMyVector;

template <typename Element>
class MyVector
{
private:
	Element* elems;
	int lg;
	int cap;

	void ensureCapacity();
public:
	/*
	Constructorul default;
	Vom aloca loc pentru 5 elemente;
	*/
	MyVector();//rule of 3

	/*
	Constructorul de copiere
	*/
	MyVector(const MyVector& ot);//rule of 3

	/*
	Destructor;
	Eliberam memoria
	*/
	~MyVector(); //rule of 3

	/*
	Operator assignment
	elibereaza ce era in obiectul curent(this)
	aloca spatiu pentru elemente
	copiaza elementele din ot in this
	*/
	MyVector& operator=(const MyVector& ot);

	/*
	Move constructor
	Apelat daca construim un nou vector dintr-un r-value (ex temporary, expresie de la return)
	Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
	*/
	MyVector(MyVector&& ot); //rule of 5

	/*
	Move assignment
	Similar cu move constructor
	Folosit la assignment
	*/
	MyVector& operator=(MyVector&& ot);//rule of 5

	void add(const Element& el);

	Element& get(int poz) const;

	void set(int poz, const Element& el);

	void deleteElement(int poz);

	int size() const noexcept;

	friend class IteratorMyVector<Element>;
	// functii care creaza iteratori
	IteratorMyVector<Element> begin();
	IteratorMyVector<Element> end();
};

template<typename Element>
class IteratorMyVector {
private:
	const MyVector<Element>& v;
	int poz = 0;
public:
	IteratorMyVector(const MyVector<Element>& v) noexcept;
	IteratorMyVector(const MyVector<Element>& v, int poz) noexcept;
	bool valid() const noexcept;
	Element& element() const noexcept;
	void next() noexcept;
	Element& operator*();
	IteratorMyVector& operator++();
	bool operator==(const IteratorMyVector& ot) noexcept;
	bool operator!=(const IteratorMyVector& ot) noexcept;
};

#include "Vector.h"

//Constructorul default;
template<typename Element>
MyVector<Element>::MyVector() :elems{ new Element[INITIAL_CAPACITY] }, cap{ INITIAL_CAPACITY }, lg{ 0 }
{

}

//Constructorul de copiere
template<typename Element>
MyVector<Element>::MyVector(const MyVector& ot) {
	elems = new Element[ot.cap];
	//copiez elementele
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i];
	}
	lg = ot.lg;
	cap = ot.cap;
}

template<typename Element>
MyVector<Element>::~MyVector()
{
	delete[] elems;
}

template<typename Element>
MyVector<Element>& MyVector<Element>::operator=(const MyVector& ot)
{
	if (this == &ot) {
		return *this;// s-a facut l=l
	}
	delete[] elems;
	elems = new Element[ot.cap];
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i];
	}
	lg = ot.lg;
	cap = ot.cap;
	return *this;
}

template<typename Element>
MyVector<Element>::MyVector(MyVector&& ot)
{
	//Copy the data pointer from other
	elems = ot.elems;
	lg = ot.lg;
	cap = ot.cap;

	//Release the data pointer from the source object so that
	//the destructor does not free the memory multiple times
	ot.elems = nullptr;
	ot.lg = 0;
	ot.cap = 0;
}

template<typename Element>
MyVector<Element>& MyVector<Element>::operator=(MyVector&& ot)
{
	if (this == &ot) {
		return *this;
	}
	delete[] elems;
	//Copy the data pointer from other
	elems = ot.elems;
	lg = ot.lg;
	cap = ot.cap;

	//Release the data pointer from the source object so that
	//the destructor does not free the memory multiple times
	ot.elems = nullptr;
	ot.lg = 0;
	ot.cap = 0;
	return *this;
}

template<typename Element>
void MyVector<Element>::add(const Element& el)
{
	ensureCapacity(); // daca e nevoie mai alocam memorie
	elems[lg++] = el;
}

template<typename Element>
Element& MyVector<Element>::get(int poz) const
{
	return elems[poz];
}

template<typename Element>
void MyVector<Element>::set(int poz, const Element& el) {
	elems[poz] = el;
}

template<typename Element>
void MyVector<Element>::deleteElement(int poz)
{
	for (int i = poz; i < lg; i++) {
		set(i, elems[i + 1]);
	}
	lg--;
}

template<typename Element>
int MyVector<Element>::size() const noexcept
{
	return lg;
}

template<typename Element>
IteratorMyVector<Element> MyVector<Element>::begin()
{
	return IteratorMyVector<Medicament>(*this);
}

template<typename Element>
IteratorMyVector<Element> MyVector<Element>::end()
{
	return IteratorMyVector<Medicament>(*this, lg);
}

template<typename Element>
void MyVector<Element>::ensureCapacity() {
	if (lg < cap) {
		return;
	}
	cap *= 2;
	Element* aux = new Element[cap];
	for (int i = 0; i < lg; i++) {
		aux[i] = elems[i];
	}
	delete[] elems;
	elems = aux;
}

template<typename Element>
IteratorMyVector<Element>::IteratorMyVector(const MyVector<Element>& v) noexcept :v{ v } {}

template<typename Element>
IteratorMyVector<Element>::IteratorMyVector(const MyVector<Element>& v, int poz) noexcept : v{ v }, poz{ poz } {}

template<typename Element>
bool IteratorMyVector<Element>::valid() const noexcept
{
	return poz < v.lg;
}

template<typename Element>
Element& IteratorMyVector<Element>::element() const noexcept
{
	return v.elems[poz];
}

template<typename Element>
void IteratorMyVector<Element>::next() noexcept
{
	poz++;
}

template<typename Element>
Element& IteratorMyVector<Element>::operator*()
{
	return element();
}

template<typename Element>
IteratorMyVector<Element>& IteratorMyVector<Element>::operator++()
{
	next();
	return *this;
}

template<typename Element>
bool IteratorMyVector<Element>::operator==(const IteratorMyVector<Element>& ot) noexcept
{
	return poz == ot.poz;
}

template<typename Element>
bool IteratorMyVector<Element>::operator!=(const IteratorMyVector<Element>& ot) noexcept
{
	return !(*this == ot);
}
