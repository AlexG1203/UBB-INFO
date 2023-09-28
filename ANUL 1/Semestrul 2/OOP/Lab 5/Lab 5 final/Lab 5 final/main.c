#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdio.h>
#include "tests.h"
#include "ui.h"
#include <stdlib.h>


int main() {
    model_tests();
    list_tests();
    service_tests();
    printf("Tests passed.\n");
    //run();
    _CrtDumpMemoryLeaks();
    return 0;
}