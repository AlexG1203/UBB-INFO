#pragma once

#include "contestant.h"
#include "list.h"
typedef struct
{
    List* elements_list;
    List* undo_list;
}Service;
Service* createList_service();
void destroy_service(Service* service);

int undo_service(Service* service);

int addContestant_service(Service* l, char* name_contestant, char* surname_contestant, int score_contestant);

bool destroyContestant_service(Service* l, int id_contestant);

int modifyContestant_service(Service* l, int id_contestant, char* name_contestant, char* surname_contestant, int score_contestant);

List* sortContestants_service(Service* l, char* sorting_element, char* mode);

List* filterContestants_service(Service* l, char* filter, char* argument);