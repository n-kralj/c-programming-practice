
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


char niz [205];


void izpis(char* izpis, int odmik) {
    for (int i = 0; i < odmik; i++) {
        printf(" ");
    }
    printf("%s\n", izpis);
}


void rek(int len, char tab[], int odmik) {
    if (len == 0) return;
    if (len == 1)  {
         char bby[2] = {tab[0], '\0'};
        izpis(bby, odmik);
        return;
    } 

    izpis(tab, odmik);

    int max = 0;
    int imax = 0;
    for (int i = 0; i < len; i++) {
        if ((int)tab[i] > max) {
            imax = i;
            max = (int)tab[i];
        }
    }
    char* leva = malloc(imax + 1);
    memcpy(leva, tab, imax);
    leva[imax] = '\0';

    // Desna stran
    int desnaLen = len - imax - 1;
    char* desna = malloc(desnaLen + 1);
    memcpy(desna, tab + imax + 1, desnaLen);
    desna[desnaLen] = '\0';

    rek(imax, leva, odmik);

    char sredina[2] = {tab[imax], '\0'};

    izpis(sredina, odmik + imax);

    rek(desnaLen, desna, odmik + imax);

    free(leva);
    free(desna);

}


int main() {
    scanf("%s", niz);
    int len = strlen(niz);
    rek(len, niz, 0);
    return 0;
}
