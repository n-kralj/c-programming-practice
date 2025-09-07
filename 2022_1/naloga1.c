

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

void vstaviPredpono(char* predpona, Oseba** osebe, int stOseb) {
    for (int i = 0; i < stOseb; i++) {
        char* tel = malloc(30*sizeof(char));
        strcpy(tel, osebe[i]->telefon);
        strcpy(osebe[i]->telefon, predpona);
        strcat(osebe[i]->telefon, tel);

    }
}

#ifndef test

int main() {
    return 0;
}

#endif
