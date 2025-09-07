
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"


void nastavi(Vozlisce* zacetek) {
    
    while (zacetek->naslednje != NULL && zacetek->naslednje->naslednje != NULL) { 
         zacetek->nn = zacetek->naslednje->naslednje;
         zacetek = zacetek->naslednje;
    }
    zacetek->nn = NULL;
    if (zacetek->naslednje != NULL) zacetek->naslednje->nn = NULL;
       
}

#ifndef test

int main() {

    return 0;
}

#endif
