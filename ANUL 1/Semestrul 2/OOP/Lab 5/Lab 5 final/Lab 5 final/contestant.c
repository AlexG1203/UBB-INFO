#pragma warning(disable : 4996)
#include "contestant.h"
#include <stdlib.h>
#include <string.h>

Contestant* createContestant(int id_contestant, char* name_contestant, char* surname_contestant, int score_contestant) {
    Contestant* resultingContestant = (Contestant*)malloc(sizeof(Contestant));

    resultingContestant->id_contestant = id_contestant;

    size_t charNumber = strlen(name_contestant) + 1;
    resultingContestant->name_contestant = (char*)malloc(sizeof(char) * charNumber);
    strcpy(resultingContestant->name_contestant, name_contestant);

    charNumber = strlen(surname_contestant) + 1;
    resultingContestant->surname_contestant = (char*)malloc(sizeof(char) * charNumber);
    strcpy(resultingContestant->surname_contestant, surname_contestant);

    resultingContestant->score_contestant = score_contestant;

    return resultingContestant;

}

void destroyContestant(Contestant* c) {
    free(c->name_contestant);
    free(c->surname_contestant);
    //marking the contestant has been destroyed

    c->id_contestant = -1;
    //c->name_contestant = NULL;
    //c->surname_contestant = NULL;
    //c->score_contestant = -1;

    free(c);
    //c = NULL;
}
void deleteContestant(Contestant* c) {
    c->id_contestant = -1;

}
Contestant* copyContestant(Contestant* c) {
    Contestant* newContestant = (Contestant*)malloc(sizeof(Contestant));

    newContestant->id_contestant = c->id_contestant;
    newContestant->name_contestant = (char*)malloc(sizeof(char) * strlen(c->name_contestant) + 1);
    strcpy(newContestant->name_contestant, c->name_contestant);

    newContestant->surname_contestant = (char*)malloc(sizeof(char) * strlen(c->surname_contestant) + 1);
    strcpy(newContestant->surname_contestant, c->surname_contestant);

    newContestant->score_contestant = c->score_contestant;
    return newContestant;

}

int validateContestant(Contestant* c) {
    if (c->id_contestant < 0)
        return 1;
    if (strlen(c->name_contestant) == 0)
        return 2;
    if (strlen(c->surname_contestant) == 0)
        return 3;
    if (c->score_contestant < 0)
        return 4;
    return 0;
}

void toString(Contestant* print_e, char stringToConcatenate[])
{
    char auxiliary[41];
    char num[10], score[10];

    sprintf(num, "%d", print_e->id_contestant);
    sprintf(score, "%d", print_e->score_contestant);
    strcpy(auxiliary, num);
    strcpy(stringToConcatenate, auxiliary);
    strcat(stringToConcatenate, ", ");
    strcat(stringToConcatenate, print_e->name_contestant);
    strcat(stringToConcatenate, ", ");
    strcat(stringToConcatenate, print_e->surname_contestant);
    strcat(stringToConcatenate, ", ");
    strcat(stringToConcatenate, score);
}