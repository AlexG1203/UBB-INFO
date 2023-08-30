#include "IteratorColectie.h"
#include "Colectie.h"


IteratorColectie::IteratorColectie(const Colectie& c) : col(c) {
    //theta(dim)
    curent = 0;
    stack<int> s;
    int i = col.prim;
    while (i != -1 || !s.empty()) {
        while (i != -1) {
            s.push(i);
            i = col.stang[i];
        }
        i = s.top();
        s.pop();
        all.push_back(col.elemente[i]);
        i = col.drept[i];
    }
}

TElem IteratorColectie::element() const {
    //theta(1)
    return all[curent];
}

bool IteratorColectie::valid() const {
    //theta(1)
    return curent < col.size;
}

void IteratorColectie::urmator() {
    //theta(1)
    curent++;
}

void IteratorColectie::prim() {
    //theta(1)
    curent = 0;
}