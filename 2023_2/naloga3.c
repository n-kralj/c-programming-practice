
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"


Vozlisce* diagonala(Vozlisce* start, int* vsota) {
    *vsota = 0;
   Vozlisce* zac = start;
   while (zac->desno != NULL) zac = zac->desno;

   
   Vozlisce* novo = malloc(sizeof(Vozlisce));
   Vozlisce* curr = start;

   Vozlisce* vrni = novo;

   while(zac != NULL) {

        novo->vsebina = zac->vsebina;
        novo->desno = NULL;
        novo->dol = NULL;
        
        *vsota += novo->vsebina;
        zac = zac->dol;
        curr = curr->dol;
        if (curr != NULL) {
            while(curr->desno != zac) curr = curr->desno;
            zac = curr;
            novo->desno = malloc(sizeof(Vozlisce));
            novo = novo-> desno;
        }
   }
   return vrni;
}


#ifndef test

int main() {
    
    return 0;
}

#endif
