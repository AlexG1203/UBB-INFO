#include "tests.h"
#include <assert.h>
#include <string.h>
#include "contestant.h"
#include "list.h"
#include "service.h"

void model_tests() {
    Contestant* contestant1 = createContestant(1, "gipson", "john", 20);
    char String[100];
    toString(contestant1, String);
    assert(strcmp(String, "1, gipson, john, 20") == 0);
    assert(contestant1->id_contestant == 1);
    assert(contestant1->id_contestant != 0);

    assert(strcmp(contestant1->name_contestant, "gipson") == 0);
    assert(strcmp(contestant1->name_contestant, "anderson") != 0);
    assert(strcmp(contestant1->name_contestant, "jackson") != 0);

    assert(strcmp(contestant1->surname_contestant, "john") == 0);
    assert(strcmp(contestant1->surname_contestant, "andrew") != 0);
    assert(strcmp(contestant1->surname_contestant, "trevor") != 0);

    assert(contestant1->score_contestant == 20);
    assert(contestant1->score_contestant != 21);

    assert(validateContestant(contestant1) == 0);
    assert(validateContestant(contestant1) != 1);
    assert(validateContestant(contestant1) != 2);
    assert(validateContestant(contestant1) != 3);
    assert(validateContestant(contestant1) != 4);

    Contestant* copied_contestant = copyContestant(contestant1);
    assert(copied_contestant->id_contestant == 1);
    assert(contestant1->id_contestant == copied_contestant->id_contestant);

    assert(strcmp(copied_contestant->name_contestant, "gipson") == 0);
    assert(strcmp(contestant1->name_contestant, copied_contestant->name_contestant) == 0);

    assert(strcmp(contestant1->surname_contestant, copied_contestant->surname_contestant) == 0);
    assert(strcmp(contestant1->surname_contestant, copied_contestant->surname_contestant) == 0);

    assert(copied_contestant->score_contestant == 20);
    assert(contestant1->score_contestant == copied_contestant->score_contestant);

    assert(validateContestant(copied_contestant) == 0);
    assert(validateContestant(copied_contestant) != 1);
    assert(validateContestant(copied_contestant) != 2);
    assert(validateContestant(copied_contestant) != 3);
    assert(validateContestant(copied_contestant) != 4);


    destroyContestant(contestant1);

    Contestant* invalidContestant1, * invalidContestant2, * invalidContestant3, * invalidContestant4;

    invalidContestant1 = createContestant(-2, "jackson", "mark", 100);
    assert(validateContestant(invalidContestant1) == 1);

    invalidContestant2 = createContestant(2, "", "paul", 90);
    assert(validateContestant(invalidContestant2) == 2);

    invalidContestant3 = createContestant(2, "griffin", "", 30);
    assert(validateContestant(invalidContestant3) == 3);

    invalidContestant4 = createContestant(2, "glenn", "edgar", -23);
    assert(validateContestant(invalidContestant4) == 4);

    destroyContestant(copied_contestant);
    destroyContestant(invalidContestant1);
    destroyContestant(invalidContestant2);
    destroyContestant(invalidContestant3);
    destroyContestant(invalidContestant4);
}

void list_tests() {
    List* list_dummy = createList((DestroyFn)destroyContestant, (CopyFn)copyContestant);
    assert(list_dummy->length == 0);
    assert(list_dummy->capacity == 2);

    Contestant* contestant1 = createContestant(list_dummy->length, "gipson", "john", 20);
    addElement(list_dummy, contestant1);
    assert(sizeList(list_dummy) == 1);

    Contestant* contestant2 = createContestant(list_dummy->length, "september", "lucia", 70);
    addElement(list_dummy, contestant2);
    assert(sizeList(list_dummy) == 2);

    Contestant* popped_element = popElement(list_dummy);
    assert(popped_element->id_contestant == 1);
    assert(popped_element->id_contestant == list_dummy->length);

    assert(strcmp(popped_element->name_contestant, "september") == 0);
    assert(strcmp(popped_element->name_contestant, contestant2->name_contestant) == 0);
    assert(strcmp(popped_element->surname_contestant, "lucia") == 0);
    assert(strcmp(popped_element->surname_contestant, contestant2->surname_contestant) == 0);

    assert(popped_element->score_contestant == 70);
    assert(popped_element->score_contestant == contestant2->score_contestant);

    Contestant* element = getElement(list_dummy, 0);
    assert(element->id_contestant == 0);
    assert(popped_element->id_contestant == list_dummy->length);

    assert(strcmp(element->name_contestant, contestant1->name_contestant) == 0);
    assert(strcmp(element->surname_contestant, contestant1->surname_contestant) == 0);

    assert(element->score_contestant == contestant1->score_contestant);


    addElement(list_dummy, contestant2);

    List* copied_list = copyList(list_dummy);

    Contestant* dummyPop = popElement(list_dummy);
    Contestant* copyPop = popElement(copied_list);
    assert(copyPop->id_contestant == 1);
    assert(dummyPop->id_contestant == copyPop->id_contestant);

    assert(strcmp(copyPop->name_contestant, "september") == 0);
    assert(strcmp(copyPop->name_contestant, dummyPop->name_contestant) == 0);
    assert(strcmp(copyPop->surname_contestant, "lucia") == 0);
    assert(strcmp(copyPop->surname_contestant, dummyPop->surname_contestant) == 0);

    assert(copyPop->score_contestant == 70);
    assert(copyPop->score_contestant == dummyPop->score_contestant);

    addElement(list_dummy, contestant2);

    Contestant* contestant3 = createContestant(list_dummy->length, "augustin", "mike", 55);
    addElement(list_dummy, contestant3);
    assert(sizeList(list_dummy) == 3);

    destroyContestant(copyPop);

    destroyList(list_dummy);
    destroyList(copied_list);

}


void service_tests() {
    Service* newService = createList_service();
    List* undo = newService->undo_list;
    List* elements = newService->elements_list;
    assert(newService->undo_list->length == 0);
    assert(newService->elements_list->length == 0);
    addContestant_service(newService, "gipson", "john", 20);

    assert(elements->length == 1);
    assert(undo->length == 1);

    Contestant* contestant1 = getElement(elements, 0);
    assert(contestant1->id_contestant == 0);
    assert(contestant1->id_contestant == elements->length - 1);
    assert(strcmp(contestant1->name_contestant, "gipson") == 0);
    assert(strcmp(contestant1->surname_contestant, "john") == 0);
    assert(contestant1->score_contestant == 20);

    assert(addContestant_service(newService, "", "john", 20) == 2);
    assert(addContestant_service(newService, "gipson", "", 20) == 3);
    assert(addContestant_service(newService, "gipson", "john", -2) == 4);

    assert(modifyContestant_service(newService, 2, "gipson", "john", 20) == 1);

    addContestant_service(newService, "september", "lucia", 70);
    assert(elements->length == 2);
    assert(undo->length == 2);

    assert(modifyContestant_service(newService, elements->length - 1, "johnas", "mike", 27) == 0);
    Contestant* modified_contestant = getElement(elements, 1);
    assert(modified_contestant->id_contestant == 1);
    assert(modified_contestant->id_contestant == elements->length - 1);
    assert(strcmp(modified_contestant->name_contestant, "johnas") == 0);
    assert(strcmp(modified_contestant->surname_contestant, "mike") == 0);
    assert(modified_contestant->score_contestant == 27);
    assert(undo->length == 3);

    addContestant_service(newService, "september", "lucia", 70);
    assert(elements->length == 3);
    assert(undo->length == 4);

    int length = elements->length;
    for (int i = elements->length - 1; i >= 0; i--)
    {
        assert(destroyContestant_service(newService, i) == true);
    }
    assert(destroyContestant_service(newService, 5) == false);
    int i;
    for (i = 0; i < length; i++)
    {
        assert(undo_service(newService) == 0);
    }



    List* sortedList2 = sortContestants_service(newService, "score", "ascending");
    Contestant* lastContestant = popElement(sortedList2);
    assert(lastContestant->score_contestant == 70);

    destroyContestant(lastContestant);

    lastContestant = popElement(sortedList2);
    assert(lastContestant->score_contestant == 27);
    destroyContestant(lastContestant);
    destroyList(sortedList2);

    sortedList2 = sortContestants_service(newService, "score", "descending");
    lastContestant = popElement(sortedList2);
    assert(lastContestant->score_contestant == 20);
    destroyContestant(lastContestant);
    lastContestant = popElement(sortedList2);
    assert(lastContestant->score_contestant == 27);
    destroyContestant(lastContestant);
    destroyList(sortedList2);

    sortedList2 = sortContestants_service(newService, "name", "descending");
    lastContestant = popElement(sortedList2);
    assert(strcmp(lastContestant->name_contestant, "gipson") == 0);
    destroyContestant(lastContestant);
    lastContestant = popElement(sortedList2);
    assert(strcmp(lastContestant->name_contestant, "johnas") == 0);
    destroyContestant(lastContestant);
    destroyList(sortedList2);

    sortedList2 = sortContestants_service(newService, "name", "ascending");
    lastContestant = popElement(sortedList2);
    assert(strcmp(lastContestant->name_contestant, "september") == 0);
    destroyContestant(lastContestant);
    lastContestant = popElement(sortedList2);
    assert(strcmp(lastContestant->name_contestant, "johnas") == 0);
    destroyContestant(lastContestant);




    //undo_service
    int ok;
    ok = undo_service(newService);
    assert(ok == 0);
    assert(undo->length == 3);
    assert(undo_service(newService) == 0);
    assert(undo->length == 2);
    assert(undo_service(newService) == 0);
    assert(undo->length == 1);
    assert(undo_service(newService) == 0);
    assert(undo->length == 0);
    assert(undo_service(newService) == 1);

    destroy_service(newService);

    //filtered_service
    Service* service_filter = createList_service();
    addContestant_service(service_filter, "1", "1", 1);
    addContestant_service(service_filter, "2", "2", 2);

    //filter=null
    List* filtered_list_null = filterContestants_service(service_filter, "null", "h");
    Contestant* contestant_1 = getElement(filtered_list_null, 0);
    assert(strcmp(contestant_1->name_contestant, "1") == 0);
    assert(strcmp(contestant_1->surname_contestant, "1") == 0);
    assert(contestant_1->score_contestant == 1);
    destroyList(filtered_list_null);

    List* filtered_list_hscore = filterContestants_service(service_filter, "h/e_score", "0");
    Contestant* contestant_2 = getElement(filtered_list_hscore, 0);
    assert(strcmp(contestant_2->name_contestant, "1") == 0);
    assert(strcmp(contestant_2->surname_contestant, "1") == 0);
    assert(contestant_2->score_contestant == 1);
    destroyList(filtered_list_hscore);

    List* filtered_list_l_score = filterContestants_service(service_filter, "l_score", "2");
    Contestant* contestant_3 = getElement(filtered_list_l_score, 0);
    assert(strcmp(contestant_3->name_contestant, "1") == 0);
    assert(strcmp(contestant_3->surname_contestant, "1") == 0);
    assert(contestant_3->score_contestant == 1);
    destroyList(filtered_list_l_score);

    List* filtered_exact_name = filterContestants_service(service_filter, "exact_name", "2");
    Contestant* contestant_4 = getElement(filtered_exact_name, 0);
    assert(strcmp(contestant_4->name_contestant, "2") == 0);
    assert(strcmp(contestant_4->surname_contestant, "2") == 0);
    assert(contestant_4->score_contestant == 2);
    destroyList(filtered_exact_name);



    List* filtered_name = filterContestants_service(service_filter, "name", "2");
    Contestant* contestant_5 = getElement(filtered_name, 0);
    assert(strcmp(contestant_5->name_contestant, "2") == 0);
    assert(strcmp(contestant_5->surname_contestant, "2") == 0);
    assert(contestant_5->score_contestant == 2);
    destroyList(filtered_name);
    List* filtered_surname = filterContestants_service(service_filter, "surname", "2");
    Contestant* contestant_6 = getElement(filtered_surname, 0);
    assert(strcmp(contestant_6->name_contestant, "2") == 0);
    assert(strcmp(contestant_6->surname_contestant, "2") == 0);
    assert(contestant_6->score_contestant == 2);
    destroyList(filtered_surname);

    destroyList(sortedList2);
    undo_service(service_filter);
    destroy_service(service_filter);
}
