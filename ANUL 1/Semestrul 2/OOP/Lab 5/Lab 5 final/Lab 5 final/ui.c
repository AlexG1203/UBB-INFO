#pragma warning(disable : 4996)
#include "ui.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void menu_startup_ui() {
    printf("1.Add contestant to the list.\n");
    printf("2.Update an already existing contestant.\n");
    printf("3.Delete an already existing contestant.\n");
    printf("4.Print all contestant with/without a filter.\n");
    printf("5.Print all contestant sorted by score/name in ascending/descending order.\n");
    printf("6.Undo.\n");
    printf("7.Print every contestant.\n");
    printf("\nHow do you wish to continue?\n");

}

void print_all(List* elements) {
    for (int i = 0; i < sizeList(elements); i++) {
        char stringToConcatenate[100];
        Contestant* contest = getElement(elements, i);
        if (contest->id_contestant != -1) {
            toString(contest, stringToConcatenate);
            printf("%s", stringToConcatenate);
            printf("\n");
        }
    }
}

void addContestant_ui(Service* l) {
    Contestant* addedC;
    int last_operation;
    char name_contestant[30];
    char surname_contestant[30];
    int score_contestant;
    printf("Enter participant's name: \n");
    scanf("%s", name_contestant);
    printf("Enter participant's surname: \n");
    scanf("%s", surname_contestant);
    printf("Enter participant's score: \n");
    scanf("%d", &score_contestant);
    last_operation = addContestant_service(l, name_contestant, surname_contestant, score_contestant);
    addedC = getElement(l->elements_list, sizeList(l->elements_list) - 1);
    if (last_operation == 0) {
        printf("Participant added successfully.\n");
        printf("Participant's ID is %d.\n", addedC->id_contestant);
    }
    else if (last_operation == 2)
        printf("Invalid name. Retry.");
    else if (last_operation == 3)
        printf("Invalid surname. Retry.");
    else
        printf("Invalid score. Retry.");
}

void filterContestants_ui(Service* l) {
    char filter[30];
    char argument[30];
    printf("Enter the item the list should be filtered by: \n");
    printf("(h/e_score, l_score, exact_name,  name, surname,no filter->null)\n");
    scanf("%s", filter);
    printf("Enter the argument of the desired filter: \n");
    printf("(score number,full name, first letter of the name, first letter of the surname)\n");
    scanf("%s", argument);
    List* filtered_list = filterContestants_service(l, filter, argument);
    print_all(filtered_list);
    destroyList(filtered_list);
}

void sortContestants_ui(Service* l) {
    char sorting_element[30];
    char mode[30];
    printf("Enter the item the list should be sorted by: \n");
    printf("(score, name)\n");
    scanf("%s", sorting_element);
    printf("Enter the mode the list should be sorted in(ascending,descending): \n");
    scanf("%s", mode);
    List* sorted_list = sortContestants_service(l, sorting_element, mode);
    for (int index = 0; index < sorted_list->length; index++) {
        Contestant* c = getElement(sorted_list, index);
        if (c->id_contestant != -1)
            printf("ID participant: %d, name: %s, surname: %s, score %u.\n", c->id_contestant, c->name_contestant,
                c->surname_contestant, c->score_contestant);
    }
    destroyList(sorted_list);
}

void modifyContestant_ui(Service* l) {
    int id_participant;
    char nume_participant[30];
    char prenume_participant[30];
    int scor_participant;
    printf("Enter the ID of the participant you wish to modify: \n");
    scanf("%u", &id_participant);
    printf("Enter participant's changed name: \n");
    scanf("%s", nume_participant);
    printf("Enter participant's changed surname: \n");
    scanf("%s", prenume_participant);
    printf("Enter participant's changed score: \n");
    scanf("%d", &scor_participant);
    int last_operation;
    last_operation = modifyContestant_service(l, id_participant, nume_participant, prenume_participant,
        scor_participant);
    if (last_operation == 0)
        printf("The participant has been modified successfully.\n");
    else
        printf("Incorrect ID.Retry.\n");
}

void destroyContestant_ui(Service* l) {
    int id_participant;
    printf("Enter the ID of the participant you wish to delete: \n");
    scanf("%d", &id_participant);
    destroyContestant_service(l, id_participant);
    printf("Participant deleted successfully.\n");

}

void undo_ui(Service* l) {
    if (undo_service(l) == 0) {
        printf("\nUndo has been done successfully !");
    }
    else
        printf("\nYou can not undo_service since your list is empty!");

}

void run() {
    Service* dummy_list = createList_service();
    int valoare_de_adevar = 1;
    char raspuns[4];
    int answer;

    while (valoare_de_adevar == 1) {
        printf("Do you want to open the menu?\n");
        printf("(yes/no)\n");
        scanf("%s", raspuns);
        if (strcmp(raspuns, "yes") == 0) {
            menu_startup_ui();
            scanf("%d", &answer);
            if (answer == 1) {
                addContestant_ui(dummy_list);
            }
            else if (answer == 2) {
                modifyContestant_ui(dummy_list);
            }
            else if (answer == 3) {
                destroyContestant_ui(dummy_list);
            }
            else if (answer == 4) {
                filterContestants_ui(dummy_list);
            }
            else if (answer == 5) {
                sortContestants_ui(dummy_list);
            }
            else if (answer == 6) {
                undo_ui(dummy_list);
            }
            else if (answer == 7)
            {
                List* to_print = dummy_list->elements_list;
                print_all(to_print);
            }
            else {
                printf("Invalid command. Try again.");
                continue;
            }


        }
        else {
            valoare_de_adevar = 0;
            destroy_service(dummy_list);
        }
    }
}