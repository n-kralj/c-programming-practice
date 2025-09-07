

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga4.h"

void pisi(int dat, int odmik, bool zadnji){
    for (int i = 0; i<odmik; i++) printf(" ");
    if (zadnji) {
        printf("%d\n", dat);
    } else {
        printf("%d,\n", dat); 
    }
}

void moje(Vozlisce* zacetek, int odmik, bool zadnje){
    int basicO = odmik;
    for (int i = 0; i<(odmik-2);i++) printf(" ");
    printf("[\n");
    Vozlisce* zunanje = zacetek;
    while (zunanje != NULL){
        bool zad = (zunanje->desno == NULL)? true : false;
        if (zunanje->podatek > 0) {
        
            pisi(zunanje->podatek, basicO, zad);
        }  else {
            moje(zunanje->dol, odmik+2, zad);


        }     
        zunanje = zunanje->desno;
    } 

    for (int i = 0; i<(odmik-2);i++) printf(" ");
    if (!zadnje) printf("],\n");
    else printf("]\n"); 
    return;

}


void izpisi(Vozlisce* zacetek) {

    int odmik = 2;
    printf("[\n");

    Vozlisce* zunanje = zacetek;
    while (zunanje != NULL){
        bool zad = (zunanje->desno == NULL)? true : false;
        if (zunanje->podatek > 0) {
            pisi(zunanje->podatek, odmik, zad);
        }  else {
            moje(zunanje->dol, odmik+2, zad);
        }      


        zunanje = zunanje->desno;
    }

     printf("]\n");
}

#ifndef test

int main() {
    return 0;
}

#endif
