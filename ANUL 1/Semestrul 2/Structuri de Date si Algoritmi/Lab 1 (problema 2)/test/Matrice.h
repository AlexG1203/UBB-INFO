#pragma once
#include <tuple>
typedef int TElem;
typedef std::tuple<int, int, TElem> TPair;

#define NULL_TELEMENT 0

class Matrice {

private:
    /* aici e reprezentarea */
    TPair* vector;
    int capacity;
    int length;
    int n, m;
public:

    //constructor
    //se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
    Matrice(int nrLinii, int nrColoane);// theta(1)


    //destructor
    ~Matrice();// theta(1)

    //returnare element de pe o linie si o coloana
    //se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
    //indicii se considera incepand de la 0
    TElem element(int i, int j) const; // theta(log2(length))


    // returnare numar linii
    int nrLinii() const; // theta(1)

    // returnare numar coloane
    int nrColoane() const; // theta(1)


    // modificare element de pe o linie si o coloana si returnarea vechii valori
    // se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
    TElem modifica(int i, int j, TElem); // O(length)

};