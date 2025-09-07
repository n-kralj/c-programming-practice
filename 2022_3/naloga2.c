
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"


void zapis(Vozlisce* zac){
    char *cpy = malloc(1010*sizeof(char));
   strcpy(cpy, "<h1>");
   strcat(cpy, zac->niz);
    strcat(cpy, "</h1>"); 
    strcpy(zac->niz, cpy);
    free(cpy);

}

void vstaviH1(Vozlisce* zacetek) {
   Vozlisce*  temp = zacetek;
   Vozlisce*  curr = zacetek->naslednje;
   
   if (zacetek->naslednje == NULL && strcmp(zacetek->niz, "") != 0) zapis(zacetek);
   else if (strcmp(zacetek->niz, "") != 0 && strcmp(zacetek->naslednje->niz, "") == 0) zapis(zacetek);
   
   while (curr != NULL) {
        if (strcmp(temp->niz, "") == 0 && strcmp(curr->niz, "") != 0 ) {
            Vozlisce*  next = curr->naslednje;
            if (next == NULL ) {
                zapis(curr);
            } else {
                if(strcmp(next->niz, "") == 0) zapis(curr);
            }
        }
        temp = temp->naslednje;
        curr = curr->naslednje;
   }
}




#ifndef test

int main() {
    /*Vozlisce* z = malloc(sizeof(Vozlisce));
    z->niz = malloc(1010); 
     strcpy(z->niz, "okokokoko!");
    zapis(z);
    printf("%s", z->niz);
    return 0;*/
}

#endif


