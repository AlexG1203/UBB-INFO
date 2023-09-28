#pragma once
typedef struct {
	int id;
	char tip[20];
	int suprafata;
	char adresa[100];
	int pret;
}Oferta;

//Creeaza Oferta
Oferta createOferta(int id, char* tip, int suprafata, char* adresa, int pret);

//Distruge Oferta
void destroyOferta(Oferta* o);

//Valideaza Oferta
//int valideazaOferta(Oferta o);