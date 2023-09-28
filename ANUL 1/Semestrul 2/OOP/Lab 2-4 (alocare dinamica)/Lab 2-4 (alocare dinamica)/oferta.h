#pragma once
typedef struct {
	int id;
	char* tip;
	int suprafata;
	char* adresa;
	int pret;
}Oferta;

//Creeaza Oferta
Oferta createOferta(int id, char* tip, int suprafata, char* adresa, int pret);

//Distruge Oferta (deloca memoria ocupata de oferta)
void destroyOferta(Oferta* o);

//Creeaza o copie pentru oferta
Oferta copyOferta(Oferta* o);

//Valideaza Oferta
int valideazaOferta(Oferta o);