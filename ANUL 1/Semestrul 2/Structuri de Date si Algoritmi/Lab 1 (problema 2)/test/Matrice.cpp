#include "Matrice.h"
#include <exception>

using namespace std;

Matrice::Matrice(int n, int m) {
    if (n <= 0 || m <= 0) throw exception();
    this->n = n;
    this->m = m;
    capacity = n * m;
    length = 0;
    vector = new TPair[capacity];
}

Matrice::~Matrice() { delete vector; }

int Matrice::nrLinii() const {
    return n;
}


int Matrice::nrColoane() const {
    return m;
}


TElem Matrice::element(int i, int j) const {
    if (i < 0 || j < 0 || i >= n || j >= m) throw exception();
    int mij, st = 0, dr = length - 1, pi, pj;
    while (st <= dr)
    {
        mij = (st + dr) / 2;
        pi = get<0>(vector[mij]);
        pj = get<1>(vector[mij]);
        if (pi == i && pj == j) return get<2>(vector[mij]);
        if (i < pi || i == pi && j < pj) dr = mij - 1;
        else st = mij + 1;
    }
    return NULL_TELEMENT;
}



TElem Matrice::modifica(int i, int j, TElem e) {
    if (i < 0 || j < 0 || i >= n || j >= m) throw exception();
    TElem old = element(i, j);
    int mij, st = 0, dr = length, pi, pj, lastst = 0;
    while (st < dr)
    {
        mij = (st + dr) / 2;
        pi = get<0>(vector[mij]);
        pj = get<1>(vector[mij]);
        if (pi == i && pj == j) { get<2>(vector[mij]) = e; return old; }
        if (i < pi || i == pi && j < pj) dr = mij;
        else st = mij + 1, lastst = st;
    }
    // il adaugam
    TPair nou = make_tuple(i, j, e);
    // il inseram la pozitia care trebuie
    int poz = lastst;
    for (int index = length - 1; index >= poz; --index)
        vector[index + 1] = vector[index];
    vector[poz] = nou;
    length++;
    return NULL_TELEMENT;
}


