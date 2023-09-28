#include "list.h"
#include <stdlib.h>
#define init_capacity 2

/*
 * create an empty list from scratch
 */
List* createList(DestroyFn destroyFn, CopyFn copyFn) {
    List* resultingList = (List*)malloc(sizeof(List));

    resultingList->length = 0;
    resultingList->capacity = init_capacity;
    resultingList->elements = (TElem)malloc(sizeof(TElem) * init_capacity);
    resultingList->destroyFn = destroyFn;
    resultingList->copyFn = copyFn;
    return resultingList;
}

/*
 * destroy a list
 */
void destroyList(List* l) {
    //imma de-allocate the contestants
    for (int i = 0; i < l->length; i++)
        l->destroyFn(l->elements[i]);
    free(l->elements);
    free(l);
}

/*
 * Get an element fom the list, given its position
 */
TElem popElement(List* l) {
    TElem element = l->elements[l->length - 1];
    l->length -= 1;
    return element;
}

TElem getElement(List* l, int position) {
    TElem element = l->elements[position];
    return element;
}


/*
 * Return the length of the list
 */
int sizeList(List* l) {
    return l->length;
}

/*
  Allocate more memory if needed
*/
void ensureCapacity(List* l) {
    if (l->length < l->capacity) {
        return; //we have room
    }
    //alocate more memory
    int newCapacity = l->capacity * 2;
    TElem* nElements = malloc(sizeof(TElem) * newCapacity);
    //copy elems
    for (int i = 0; i < l->length; i++) {
        nElements[i] = l->elements[i];
    }
    //dealocate old vector
    free(l->elements);
    l->elements = nElements;
    l->capacity = newCapacity;
}

/*
 * Add an element to the list(it is added at the end of the list)
 */
void addElement(List* l, TElem element) {
    ensureCapacity(l);
    l->elements[l->length] = element;
    l->length++;

}

/*
 * Make a copy of a list
 */
List* copyList(List* l) {
    List* copiedList = createList(l->destroyFn, l->copyFn);

    for (int i = 0; i < l->length; i++) {
        addElement(copiedList, l->copyFn(l->elements[i]));
        //copiedList->elements[i] = l->copyFn(l->elements[i]);
    }
    //copiedList->length = l->length;
    //copiedList->capacity = l->capacity;
    return copiedList;
}