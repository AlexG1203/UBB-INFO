#pragma once
#include "MyList.h"

//Adauga o oferta
int addOferta(MyList* v, int id, char* tip, int suprafata, char* adresa, int pret);

//Gaseste o oferta dupa un id dat
int findOferta(MyList* v, int id);

//Modifica o oferta
int modifyOferta(MyList* v, int id, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou);

//Sterge o oferta
int deleteOferta(MyList* v, int id);

//Filtreaza dupa suprafata
MyList supFilter(MyList* v, int suprafata);

//Filtreaza dupa tip
MyList tipFilter(MyList* v, char* tip);

//Filtrare dupa pret
MyList pretFilter(MyList* v, int pret);

//Teste
void testAddService();
void testFindService();
void testModifyService();
void testDeleteService();
void testsupFilter();
void testtipFilter();
void testpretFilter();