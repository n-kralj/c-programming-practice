

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"


int** zmehcaj(int** slika, int n, int m, int d) {

    int visina = n - 2 * d;
    int sirina = m - 2 * d;

    int** sl = calloc(visina, sizeof(int*));
    for (int i = 0; i < visina; i++) {
        sl[i] = calloc(sirina, sizeof(int));
        for (int j = 0; j < sirina; j++) {
            int id = i + d;
            int jd = j + d;


            int l = id - d;
            int r = id + d;
            int u = jd - d;
            int dol = jd + d;


            int vsota = 0;
            for (int x = l; x <= r; x++) {
                for (int y = u; y <= dol; y++) {
                    vsota += slika[x][y];
                }
            }

            int stevilo = (2 * d + 1) * (2 * d + 1);
            sl[i][j] = vsota / stevilo;
        }
    }

    return sl;
}

#ifndef test

int main() {

    return 0;
}

#endif
