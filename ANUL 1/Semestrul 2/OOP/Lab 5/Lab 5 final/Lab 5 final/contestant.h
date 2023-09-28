#pragma once
#include <string.h>
#include <stdio.h>
/*
 * defining the structure known as <contestant>
 */
typedef struct {
    int id_contestant;
    char* name_contestant;
    char* surname_contestant;
    int score_contestant;

} Contestant;
void toString(Contestant* print_e, char stringToConcatenate[]);
/*
 * Create a new contestant
 */
Contestant* createContestant(int id_contestant, char* name_contestant, char* surname_contestant, int score_contestant);

/*
 * De-allocate the memory used by a contestant.
 */
void destroyContestant(Contestant* c);

/*
 * Create a copy for a contestant and its attributes.
 */
Contestant* copyContestant(Contestant* c);

/*
 * Validate a contestant.
 * If the contestant is invalid, return value <> 0.
 */
int validateContestant(Contestant* c);

void deleteContestant(Contestant* c);