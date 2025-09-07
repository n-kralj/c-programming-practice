

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"

void urediZOdstranjevanjem(Vozlisce* zacetek) {
        Vozlisce* curr = zacetek->naslednje;
        Vozlisce* prej = zacetek;
        bool zbrisano = false;

        while(curr != NULL){
            if (prej->podatek > curr->podatek){
                prej->naslednje = curr->naslednje;
                curr = curr->naslednje;
                zbrisano = true;
            }

            while(zbrisano && curr != NULL) {
                if (prej->podatek > curr->podatek){
                    prej->naslednje = curr->naslednje;
                    curr = curr->naslednje;
                    zbrisano = true;
                } else {
                    zbrisano = false;

                }
            }
            if (!zbrisano) {
                 prej = prej->naslednje;
                 curr = curr->naslednje;
            }

        }
}

#ifndef test

int main() {
    return 0;
}

#endif
