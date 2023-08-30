#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    //theta(1)
    if (e1 <= e2)
        return true;
    return false;
}

void Colectie::redim() {
    //theta(2*cp)
    TElem* elemsN = new TElem[2 * cp];
    int* stN = new int[2 * cp];
    int* drN = new int[2 * cp];
    for (int i = 0; i < cp; i++) {
        elemsN[i] = elemente[i];
        stN[i] = stang[i];
        drN[i] = drept[i];
    }
    delete[] elemente;
    delete[] stang;
    delete[] drept;
    elemente = elemsN;
    stang = stN;
    drept = drN;
    //initializam tabloul cu -1
    for (int i = cp; i < 2 * cp; i++) {
        elemente[i] = stang[i] = drept[i] = -1;
    }
    cp *= 2;
}

void Colectie::actualizarePrimLiber() {
    //O(cp)
    primLiber++;
    while (primLiber < cp && elemente[primLiber] != -1)
        primLiber++;
}

Colectie::Colectie() {
    //theta(cp)
    cp = 1;
    size = 0;
    elemente = new TElem[cp];
    stang = new int[cp];
    drept = new int[cp];
    for (int i = 0; i < cp; i++) {
        elemente[i] = stang[i] = drept[i] = -1;
    }
    prim = -1;
    primLiber = 0;
}

void Colectie::adauga(TElem e) {
    //O(h), h-inaltimea arborelui
    if (primLiber >= cp)
        redim();
    if (prim == -1) { //adauga cand tablela e goala
        elemente[0] = e;
        prim = 0;
        primLiber = 1;
        size++;
        return;
    }
    //se parcurge arborele binar pentru a gasi pozitia corecta de inserare
    int ant = -1;
    int i = prim;
    while (i != -1) {
        ant = i;
        if (rel(e, elemente[i])) {
            i = stang[i];
        }
        else {
            i = drept[i];
        }
    }
    elemente[primLiber] = e;
    //se actualizeaza legaturile catre noul element in arbore
    if (ant != -1) {
        if (rel(e, elemente[ant])) {
            stang[ant] = primLiber;
        }
        else drept[ant] = primLiber;
    }
    actualizarePrimLiber();
    size++;
}


bool Colectie::sterge(TElem e) {
    //O(h)
    int i = prim;
    int ant = -1;
    //se parcurge arborele binar pentru a gasi pozitia corecta
    while (i != -1 && elemente[i] != e) {//cand e primul element;
        ant = i;
        if (rel(e, elemente[i])) {
            i = stang[i];
        }
        else i = drept[i];
    }
    if (i == -1)//cand nu exista numarul in colectie
        return false;
    //Daca nodul gasit are cel putin un fiu gol, se inlocuieste nodul gasit cu fiul sau nenul
    if (stang[i] == -1 || drept[i] == -1) {
        int nou;
        if (stang[i] == -1) {
            nou = drept[i];
            elemente[i] = elemente[nou];
            drept[i] = drept[nou];
            stang[i] = stang[nou];
            if (nou == -1) {
                elemente[i] = drept[i] = stang[i] = -1;
            }
        }
        else {
            nou = stang[i];
            elemente[i] = elemente[nou];
            stang[i] = stang[nou];
            drept[i] = drept[nou];
        }
        if (ant != -1) {
            if (i == stang[ant])
                stang[ant] = nou;
            else drept[ant] = nou;
        }
    }
    else {//cand nu mai este inlantuit
        //Daca nodul gsait nu are niciun fiu gol, se gaseste succesorul sau in inordine (urmatorul element in ordine)
        int prev = -1;
        int temp;
        temp = drept[i];
        while (stang[temp] != -1) {
            prev = temp;
            temp = stang[temp];
        }
        if (prev != -1) {
            stang[prev] = drept[temp];
        }
        else drept[i] = drept[temp];
        elemente[i] = elemente[temp];
    }
    size--;
    return true;
}


bool Colectie::cauta(TElem elem) const {
    //O(h)
    int i = prim;
    while (i != -1) {
        if (elem <= elemente[i]) {
            if (elem == elemente[i])
                return true;
            i = stang[i];
        }
        else i = drept[i];
    }
    return false;
}


int Colectie::nrAparitii(TElem elem) const {
    //O(h)
    int i = prim;
    int nr = 0;
    stack<int> s;
    while (i != -1 || !s.empty()) {
        while (i != -1) {
            s.push(i);
            i = stang[i];
        }
        i = s.top();
        s.pop();
        if (elemente[i] == elem)
            nr++;
        if (elemente[i] > elem)
            return nr;
        i = drept[i];
    }
    return nr;
}



int Colectie::dim() const {
    //theta(1)
    return size;
}


bool Colectie::vida() const {
    //theta(1)
    if (size == 0)
        return true;
    return false;
}


IteratorColectie Colectie::iterator() const {
    //theta(1)
    return  IteratorColectie(*this);
}

Colectie::~Colectie() {
    //theta(1)
    delete[] elemente;
    delete[] stang;
    delete[] drept;
}