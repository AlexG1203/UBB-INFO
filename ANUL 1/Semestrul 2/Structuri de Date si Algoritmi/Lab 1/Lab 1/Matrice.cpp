#include "Matrice.h"
#include "VectorDinamic.h"
#include <exception>

using namespace std;

//theta(nrCol)
Matrice::Matrice(int m, int n) : Linie(1), Valoare(1) {
	if (m < 0 || n < 0) {
		throw exception("Nu s-a putut initializa matricea, valorile sunt invalide!");
	}
	nrLin = n;
	nrCol = m;
	Coloana = new int[nrCol + 1];
	for (int i = 0; i <= nrCol; ++i) {
		Coloana[i] = 0;
	}
}

//theta(1)
Matrice::~Matrice() {
	delete[] Coloana;
}

//theta(1)
int Matrice::nrLinii() const {
	return nrLin;
}

//theta(1)
int Matrice::nrColoane() const {
	return nrCol;
}

//O(n)
TElem Matrice::element(int i, int j) const {
	if (i < 0 || i > nrLin || j < 0 || j > nrCol) {
		throw exception("Nu s-a putut returna elementul, coordonatele sunt invalide!");
	}
	for (int k = Coloana[i]; k < Coloana[i + 1]; ++k) {
		if (Linie.element(k) == j) {
			return Valoare.element(k);
		}
	}
	return NULL_TELEMENT;
}


//O(n)
TElem Matrice::modifica(int i, int j, TElem e) {
	if (i < 0 || i > nrLin || j < 0 || j > nrCol) {
		throw exception("Nu s-a putut realiza modificarea, coordonatele sunt invalide!");
	}
	int k;
	bool passed = false;
	for (k = Coloana[i]; k < Coloana[i + 1]; ++k) {
		passed = true;
		if (Linie.element(k) >= j) {
			break;
		}
	}
	if (passed && Linie.element(k) == j) {
		TElem valoareVeche = Valoare.element(k);
		if (e == NULL_TELEMENT) {
			for (int j = i; j < nrCol; j++) {
				Coloana[j]--;
			}
			Linie.sterge(k);
			Valoare.sterge(k);
		}
		else {
			Valoare.modifica(k, e);
		}
		return valoareVeche;
	}

	if (e != NULL_TELEMENT) {
		Linie.adauga(k, j);
		Valoare.adauga(k, e);

		for (int p = i + 1; p <= nrLin; ++p) {
			Coloana[p]++;
		}
	}

	return NULL_TELEMENT;
}

void Matrice::redimensioneaza(int numarNouLinii, int numarNouColoane) {
	if (numarNouLinii < 0 || numarNouColoane < 0) {
		throw exception("Nu s-a putut realiza redimensionarea, coordonatele sunt invalide!");
	}
	if (numarNouLinii > nrLin && numarNouColoane > nrCol) {
		for (int i = 0; i < numarNouLinii; ++i) {
			if (i >= nrLin) {
				for (int j = 0; j < numarNouColoane; ++j) {
					modifica(i, j, NULL_TELEMENT);
				}
			}
			else {
				int k = Coloana[i];
				while (k < Coloana[i + 1] && Linie.element(k) < numarNouColoane) {
					++k;
				}
				for (int j = Linie.element(k - 1) + 1; j < numarNouColoane; ++j) {
					modifica(i, j, NULL_TELEMENT);
				}
			}
		}
	}
	else if (numarNouLinii < nrLin && numarNouColoane < nrCol) {
		for (int i = numarNouLinii; i < nrLin; ++i) {
			for (int k = Coloana[i]; k < Coloana[i + 1]; ++k) {
				int j = Linie.element(k);
				if (j >= numarNouColoane) {
					Linie.sterge(k);
					Valoare.sterge(k);
					--k;
					--Coloana[i + 1];
				}
			}
		}
	}
	nrLin = numarNouLinii;
	nrCol = numarNouColoane;
}