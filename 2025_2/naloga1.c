

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

void nicleVPresledke(char* tabela, int k) {
    bool prva = true;
    int dist = 0;
    int zadnja = -1;

    for (int i = 0; i < 1000; i++) {
      // printf("i-ti krog %d\n", i);S
       
        if (prva && tabela[i] == '\0') {
            tabela[i] = ' ';
            prva = false;
            dist = 0;
            continue;
        } 

       
        if (tabela[i] == '\0') {
            if (zadnja != -1) tabela[zadnja] = ' ';
            zadnja = i;
            dist = 0;
        } else if (!prva) {
            dist++;
        }

         if (dist == k-1) break;

    }
    return;
}


#ifndef test

int main() {
    return 0;
}

#endif
