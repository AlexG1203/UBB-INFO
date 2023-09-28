#pragma once

#include "contestant.h"
#include <stdbool.h>

typedef void* TElem;
typedef void (*DestroyFn)(TElem);
typedef TElem(*CopyFn)(TElem);
//typedef Contestant ElementType;

typedef struct {
    TElem* elements;
    int length;
    int capacity;
    DestroyFn destroyFn;
    CopyFn copyFn;
}List;

/*
 * create an empty list from scratch
 */
List* createList(DestroyFn destroyFn, CopyFn copyFn);

/*
 * destroy a list
 */
void destroyList(List* l);

/*
 * Pop an element from the list(LIFO)
 */
TElem popElement(List* l);

/*
 * Get an element from the list, given its position
 */
TElem getElement(List* l, int position);

/*
 * Return the length of the list
 */
int sizeList(List* l);

/*
 * Add an element to the list(it is added at the end of the list)
 */
void addElement(List* l, TElem element);

/*
 * Make a copy of a list
 */
List* copyList(List* l);
