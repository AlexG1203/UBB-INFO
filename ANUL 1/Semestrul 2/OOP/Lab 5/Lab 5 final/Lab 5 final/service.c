#pragma warning(disable : 4996)
#include "service.h"
#include <string.h>
#include <stdlib.h>

Service* createList_service()
{
    Service* service = (Service*)malloc((sizeof(Service)));
    service->elements_list = createList((DestroyFn)destroyContestant, (CopyFn)copyContestant);
    service->undo_list = createList((DestroyFn)destroyList, (CopyFn)copyList);
    return service;
}
void destroy_service(Service* service)
{
    destroyList(service->elements_list);
    destroyList(service->undo_list);
    free(service);
}

int undo_service(Service* service)
{
    if (sizeList(service->undo_list) == 0)
    {
        return 1;
    }

    List* list_elemente_noi = popElement(service->undo_list);
    destroyList(service->elements_list);
    service->elements_list = list_elemente_noi;
    return 0;

}

int addContestant_service(Service* l, char* name_contestant, char* surname_contestant, int score_contestant) {
    Contestant* newContestant = createContestant(l->elements_list->length, name_contestant, surname_contestant, score_contestant);

    if (validateContestant(newContestant) == 0) {
        List* copy = copyList(l->elements_list);
        addElement(l->undo_list, copy);
        addElement(l->elements_list, newContestant);

        return 0;
    }
    else {
        int ValidError = validateContestant(newContestant);
        destroyContestant(newContestant);
        return ValidError;
    }
}

bool destroyContestant_service(Service* service, int id_contestant) {
    List* l = service->elements_list;
    if (id_contestant < l->length) {
        List* copy_undo = copyList(l);
        addElement(service->undo_list, copy_undo);
        Contestant* c = getElement(l, id_contestant);
        deleteContestant(c);
        l->elements[id_contestant] = c;
        return true;
    }
    return false;
}

int modifyContestant_service(Service* service, int id_contestant, char* name_contestant, char* surname_contestant, int score_contestant) {
    List* l = service->elements_list;

    if (id_contestant >= l->length)
        return 1;//the index is out of range
    //adaugare undo_service
    List* copie = copyList(l);
    addElement(service->undo_list, copie);
    destroyContestant(l->elements[id_contestant]);
    Contestant* modified_contestant = createContestant(id_contestant, name_contestant, surname_contestant, score_contestant);
    l->elements[id_contestant] = modified_contestant;
    return 0;
}



List* sortContestants_service(Service* l, char* sorting_element, char* mode) {
    List* copied_list = copyList(l->elements_list);
    int i, j;
    if (strcmp(sorting_element, "score") == 0) {
        if (strcmp(mode, "descending") == 0) {
            for (i = 0; i < copied_list->length; i++) {
                for (j = 0; j < copied_list->length; j++) {
                    Contestant* c1 = getElement(copied_list, i);
                    Contestant* c2 = getElement(copied_list, j);
                    if (c1->score_contestant > c2->score_contestant) {
                        //Contestant* aux = getElement(copied_list, i);
                        copied_list->elements[i] = c2;
                        copied_list->elements[j] = c1;

                    }
                }
            }

        }
        else {
            for (i = 0; i < copied_list->length; i++) {
                for (j = 0; j < copied_list->length; j++) {
                    Contestant* c1 = getElement(copied_list, i);
                    Contestant* c2 = getElement(copied_list, j);
                    if (c1->score_contestant < c2->score_contestant) {
                        //Contestant* aux = getElement(copied_list, i);
                        copied_list->elements[i] = c2;
                        copied_list->elements[j] = c1;

                    }
                }
            }
        }
    }
    else if (strcmp(sorting_element, "name") == 0) {
        if (strcmp(mode, "descending") == 0) {
            for (i = 0; i < copied_list->length; i++) {
                for (j = 0; j < copied_list->length; j++) {
                    Contestant* c1 = getElement(copied_list, i);
                    Contestant* c2 = getElement(copied_list, j);
                    if (strcmp(c1->name_contestant, c2->name_contestant) > 0) {
                        //Contestant* aux = getElement(copied_list, i);
                        copied_list->elements[i] = c2;
                        copied_list->elements[j] = c1;

                    }
                }
            }
        }
        else {
            for (i = 0; i < copied_list->length; i++) {
                for (j = 0; j < copied_list->length; j++) {
                    Contestant* c1 = getElement(copied_list, i);
                    Contestant* c2 = getElement(copied_list, j);
                    if (strcmp(c1->name_contestant, c2->name_contestant) < 0) {
                        //Contestant* aux = getElement(copied_list, i);
                        copied_list->elements[i] = c2;
                        copied_list->elements[j] = c1;

                    }
                }
            }
        }
    }
    return copied_list;
}

List* filterContestants_service(Service* l, char* filter, char* argument)
{
    List* filtered_list = createList((DestroyFn)destroyContestant, (CopyFn)copyContestant);
    List* contestants = l->elements_list;
    Contestant* c;
    if (strcmp(filter, "null") == 0) {
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            if (c->id_contestant != -1) {
                {
                    Contestant* copy = copyContestant(c);
                    addElement(filtered_list, copy);

                }
            }
        }
    }
    if (strcmp(filter, "h/e_score") == 0) {
        int score = atoi(argument);
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            if (c->id_contestant != -1 && c->score_contestant >= score)
            {
                Contestant* copy = copyContestant(c);
                addElement(filtered_list, copy);

            }
        }
    }

    if (strcmp(filter, "l_score") == 0) {
        int score = atoi(argument);
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            if (c->id_contestant != -1 && c->score_contestant < score)
            {
                Contestant* copy = copyContestant(c);
                addElement(filtered_list, copy);

            }
        }
    }

    if (strcmp(filter, "exact_name") == 0) {
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            if (c->id_contestant != -1 && strcmp(c->name_contestant, argument) == 0)
            {
                Contestant* copy = copyContestant(c);
                addElement(filtered_list, copy);

            }

        }
    }


    if (strcmp(filter, "name") == 0) {
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            char name[2];
            name[1] = '\0';
            strncpy(name, c->name_contestant, 1);
            if (c->id_contestant != -1 && strcmp(name, argument) == 0) {
                Contestant* copy = copyContestant(c);
                addElement(filtered_list, copy);

            }

        }
    }
    if (strcmp(filter, "surname") == 0) {
        for (int index = 0; index < contestants->length; index++) {
            c = getElement(contestants, index);
            char surname[2];
            surname[1] = '\0';
            strncpy(surname, c->surname_contestant, 1);
            if (c->id_contestant != -1 && strcmp(surname, argument) == 0) {
                Contestant* copy = copyContestant(c);
                addElement(filtered_list, copy);

            }

        }
    }


    return filtered_list;
}
