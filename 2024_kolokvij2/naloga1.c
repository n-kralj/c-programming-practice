
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"


void nastavi(Vozlisce* zacetek) {
    Vozlisce* prej = zacetek;
    prej->prejsnje = NULL;
    Vozlisce* curr = zacetek->naslednje;
    while (curr != NULL) {
        curr->prejsnje = prej;
        curr = curr->naslednje;
        prej = prej->naslednje;
    }

}

//=============================================================================

#ifndef test

int main() {

    return 0;
}

#endif
