

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"



void obdelaj(Vozlisce* zacetek) {
    Vozlisce* curr = zacetek;

    while (curr != NULL) {
        int sum = curr->podatek;
        bool podvojeno = false;

        // tecemo čez skupino enakih vrednosti
        Vozlisce* q = curr->naslednje;
        while (q != NULL && q->podatek == curr->podatek) {
            podvojeno = true;
            sum += q->podatek;
            q = q->naslednje;
        }

        // če je bila skupina dolga >= 2: zapiši vsoto in odstrani vmesna vozlišča
        if (podvojeno) {
            curr->podatek = sum;
            curr->naslednje = q;   // preskoči odstranjena
        }

        // naprej na naslednje vozlišče
        curr = curr->naslednje;
    }
}


#ifndef test

int main() {

    return 0;
}

#endif
