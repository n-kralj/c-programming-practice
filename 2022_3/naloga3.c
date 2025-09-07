
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#include "naloga3.h"

Vozlisce* drevo(int n, int* podatki) {
    if (n == 0) return NULL;
    int meja= 1 << (n - 1);;
    Vozlisce* curr = malloc(sizeof(Vozlisce));
    curr->podatek = podatki[0];
    curr->levo = drevo(n-1, podatki+1);
    curr->desno = drevo(n-1, podatki+meja);
    return curr;
}

#ifndef test

int main() {

    return 0;
}

#endif
