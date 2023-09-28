#pragma once
#include "MyList.h"

typedef struct {
	MyList allOferte;
}OfertaStore;

//Creaza o OfertaStore
OfertaStore createOfertaStore();

void destroyStore(OfertaStore* store);

//Adauga o oferta
int addOferta(OfertaStore* store, int id, char* tip, int suprafata, char* adresa, int pret);


//Gaseste o oferta dupa un id dat
int findOferta(OfertaStore* store, int id);

//Modifica o oferta
int modifyOferta(OfertaStore* store, int id, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou);

//Sterge o oferta
int deleteOferta(OfertaStore* store, int id);

//Sorteaza dupa pret, crescator
MyList sortPC(OfertaStore* store);

//Sorteaza dupa pret, descrescator
MyList sortPD(OfertaStore* store);

//Sorteaza dupa tip, crescator
MyList sortTC(OfertaStore* store);

//Sorteaza dupa tip, descrescator
MyList sortTD(OfertaStore* store);

//Filtreaza dupa suprafata
MyList supFilter(OfertaStore* store, int suprafata);

//Filtreaza dupa tip
MyList tipFilter(OfertaStore* store, char* tip);

//Filtrare dupa pret
MyList pretFilter(OfertaStore* store, int pret);

//Teste
void testAddService();
void testFindService();
void testModifyService();
void testDeleteService();
void testsupFilter();
void testtipFilter();
void testpretFilter();
void testSorts();