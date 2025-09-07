
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "naloga2.h"



int dolzinaCikla(Vozlisce* zacetek) {
    int st = 1;
      Vozlisce* pocasi = zacetek;
    Vozlisce* hitro = zacetek;

    // najdem točko srečanja
    do {
        pocasi = pocasi->naslednje;
        hitro = hitro->naslednje->naslednje;
    } while (pocasi != hitro);

    zacetek = pocasi;
    pocasi = pocasi->naslednje;
    while(pocasi != zacetek) {
        pocasi = pocasi->naslednje;
        st++;
    }


    return st;  
}



#ifndef test

int main() {
    return 0;
}

#endif
