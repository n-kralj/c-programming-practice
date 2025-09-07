
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

int st;

void stej(Vozlisce* curr) {
   if (curr == NULL) return;
    st++;

    if (curr->stOtrok == -1 || curr->stOtrok == 0) return;

    for (int j = 0; j < curr->stOtrok; j++) {
        stej(curr->otroci[j]);
    }
}

void izvedi(Vozlisce* koren, int stUkazov, char** ukazi) {

    Vozlisce* curr = koren;
    
    for (int i = 0; i<stUkazov; i++) {

        if (!strcmp(ukazi[i], "prestej")) {
            st = 0;
            stej (curr);
            printf("%d\n", st);
        }

        //cd prestavi gor
        else if (!strcmp(ukazi[i], "cd .."))  {
           if (curr != NULL) curr = curr->stars;
        }
        //prestavi v pravega otroka
        else {
            char ime[30];
            strcpy(ime, (ukazi[i]+3));
            strcat(ime, "\0");

           

             for (int j = 0; j<curr->stOtrok; j++) {
               
                if (!strcmp(ime, curr->otroci[j]->ime)) {
                    if (curr != NULL) curr = curr->otroci[j];
                    break;
                }
            }

        }/
    }
}

#ifndef test

int main() {
    return 0;
}

#endif
