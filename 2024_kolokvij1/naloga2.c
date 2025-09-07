
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"


void racionaliziraj(char** nizi) {
    int n = 1;
    while(nizi[n] != NULL) {
        for (int u = 0; u <= n-1; u++) {
            if (!strcmp(nizi[n], nizi[u])) {
                nizi[n] = nizi[u];
                break;
            }
        }
        n++;
    }

}



#ifndef test

int main() {

    return 0;
}

#endif
