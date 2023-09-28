#include "MyVector.h"

//Constructorul default;
MyVector::MyVector() :elems{ new Element[INITIAL_CAPACITY] }, cap{ INITIAL_CAPACITY }, lg{ 0 }
{

}

//Constructorul de copiere
MyVector::MyVector(const MyVector& ot) {
	elems = new Element[ot.cap];
	//copiez elementele
	for (int i = 0; i < ot.lg; i++) {
		elems[i] = ot.elems[i];
	}
	lg = ot.lg;
	cap = ot.cap;
}

MyVector::~MyVector()
{
	delete[] elems;
}

MyVector& MyVector::operator=(const MyVector& ot)
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

MyVector::MyVector(MyVector&& ot)
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

MyVector& MyVector::operator=(MyVector&& ot)
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

void MyVector::add(const Element& el)
{
	ensureCapacity(); // daca e nevoie mai alocam memorie
	elems[lg++] = el;
}

Element& MyVector::get(int poz) const
{
	return elems[poz];
}

void MyVector::set(int poz, const Element& el) {
	elems[poz] = el;
}

void MyVector::deleteElement(int poz)
{
	for (int i = poz; i < lg; i++) {
		set(i, elems[i + 1]);
	}
	lg--;
}

int MyVector::size() const noexcept
{
	return lg;
}

IteratorMyVector MyVector::begin()
{
	return IteratorMyVector(*this);
}

IteratorMyVector MyVector::end()
{
	return IteratorMyVector(*this, lg);
}

void MyVector::ensureCapacity() {
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

IteratorMyVector::IteratorMyVector(const MyVector& v) noexcept :v{ v } {}

IteratorMyVector::IteratorMyVector(const MyVector& v, int poz) noexcept : v{ v }, poz{ poz } {}

bool IteratorMyVector::valid() const noexcept
{
	return poz < v.lg;
}

Element& IteratorMyVector::element() const noexcept
{
	return v.elems[poz];
}

void IteratorMyVector::next() noexcept
{
	poz++;
}

Element& IteratorMyVector::operator*()
{
	return element();
}

IteratorMyVector& IteratorMyVector::operator++()
{
	next();
	return *this;
}

bool IteratorMyVector::operator==(const IteratorMyVector& ot) noexcept
{
	return poz == ot.poz;
}

bool IteratorMyVector::operator!=(const IteratorMyVector& ot) noexcept
{
	return !(*this == ot);
}
