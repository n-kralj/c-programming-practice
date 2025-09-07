
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

Zunanje* porazdeli(Notranje* zacetek, int k) {
    Notranje* curr = zacetek;

    //naredi zunanji seznam
    Zunanje* zac = malloc(1*sizeof(Zunanje));
    Zunanje* z = zac;
    z->prvo = NULL;
    z->zadnje = NULL;
    z->dol = NULL;

    for (int i = 1; i<k; i++) {
        Zunanje* zz = malloc(1*sizeof(Zunanje));
        zz->prvo = NULL;
        zz->zadnje = NULL;
        zz->dol = NULL;

        z->dol = zz;
        z = z->dol;
    }

    //porazdeli notri
    while(curr != NULL) {
        Zunanje* okvir = zac;
        for (int i = 0; i<k; i++) {
            if (curr == NULL) break;
            
            
            if (okvir->prvo == NULL) {
                okvir->prvo = curr;
                okvir->zadnje = curr;

                curr = curr->desno;
                okvir->zadnje->desno = NULL;
            } else {
                okvir->zadnje->desno = curr; 
                curr = curr->desno;
                 okvir->zadnje = okvir->zadnje->desno; 
                 okvir->zadnje->desno = NULL;

            }

            okvir = okvir->dol;

        }
    }
    return zac;
}

#ifndef test

int main() {
    return 0;
}

#endif
