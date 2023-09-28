#pragma once

#include "Medicament.h"
typedef Medicament Element;
#define INITIAL_CAPACITY 5

class IteratorMyVector;

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

	friend class IteratorMyVector;
	// functii care creaza iteratori
	IteratorMyVector begin();
	IteratorMyVector end();
};

class IteratorMyVector {
private:
	const MyVector& v;
	int poz = 0;
public:
	IteratorMyVector(const MyVector& v) noexcept;
	IteratorMyVector(const MyVector& v, int poz) noexcept;
	bool valid() const noexcept;
	Element& element() const noexcept;
	void next() noexcept;
	Element& operator*();
	IteratorMyVector& operator++();
	bool operator==(const IteratorMyVector& ot) noexcept;
	bool operator!=(const IteratorMyVector& ot) noexcept;
};