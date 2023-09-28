#pragma once

#include "service.h"

void menu_startup_ui();
void undo_ui(Service* l);
void print_all(List* l);

void addContestant_ui(Service* l);

void modifyContestant_ui(Service* l);

void destroyContestant_ui(Service* l);

void filterContestants_ui(Service* l);

void sortContestants_ui(Service* l);

void run();