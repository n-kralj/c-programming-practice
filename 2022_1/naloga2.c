

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"



Vozlisce* zlij(Vozlisce* a, Vozlisce* b) {

    Vozlisce* zac = (a->podatek > b->podatek) ? b : a;
    Vozlisce* c = zac;
    if (zac == a) a = a->naslednje;
    else b = b->naslednje;

    while (a != NULL && b != NULL) {
        zac -> naslednje = (a->podatek > b->podatek) ? b : a;
        zac = zac->naslednje;
        if (zac == b) b = b->naslednje;
        else a = a->naslednje;
    }

    if (a != NULL) {
        while (a != NULL) {
            zac->naslednje = a;
            zac= zac->naslednje;
            a = a->naslednje;
        }
    } else if (b != NULL) {
        while (b != NULL) {
            zac->naslednje = b;
            zac = zac->naslednje;
            b = b->naslednje;
        }
    }
    return c;
}



#ifndef test

int main() {
    return 0;
}

#endif
