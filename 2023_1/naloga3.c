

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga3.h"



Vozlisce* vstaviStolpec(Vozlisce* start, int mesto, int vsebina) {
    Vozlisce* temp = start;
    
   
    if (mesto == 0){
       
        Vozlisce* new = malloc(sizeof(Vozlisce));
        new->desno = start;
        new->dol = NULL;
        new->vsebina = vsebina;
        vsebina++;
        Vozlisce* pos = new;
    
        temp = temp->dol;
        while (temp != NULL) {
            Vozlisce* curr = malloc(sizeof(Vozlisce));
            pos->dol = curr;
            curr->desno = temp;
            curr->dol = NULL;
            curr->vsebina = vsebina;
            vsebina++;
            pos = curr;
            temp = temp->dol;
        }

        return new;
       
    } else {
        for (int i=1; i< mesto; i++) {
            temp = temp->desno;
        }
        if (temp->desno == NULL) {
            if (temp != NULL) {
                Vozlisce* new = malloc(sizeof(Vozlisce));
                new->vsebina = vsebina;
                vsebina++;
                new->desno = NULL;
                new->dol = NULL;
                temp->desno = new;
                temp = temp->dol;
            
                while(temp != NULL) {
                    Vozlisce* curr = malloc(sizeof(Vozlisce));
                    new->dol = curr;
                    curr->vsebina = vsebina;
                    vsebina++;
                    curr->desno = NULL;
                    curr->dol = NULL;
                    temp->desno = curr;
                    temp = temp->dol;
                    new = curr;
                }
            }
            
        }
        if (temp != NULL) {
           
             Vozlisce* new = malloc(sizeof(Vozlisce));
          
            new->dol = NULL;
            new->desno = temp->desno;
            new->vsebina = vsebina;
            vsebina++;
            temp->desno = new;
            temp = temp->dol;


            while(temp != NULL) {
                 Vozlisce* curr = malloc(sizeof(Vozlisce));
                new->dol = curr;
                curr->vsebina = vsebina;
                vsebina++;
                curr->dol = NULL;
                curr->desno = temp->desno;
                temp->desno = curr;
                new = curr;
                temp = temp->dol;
            }

        }
       

        return start;
    }

}

//=============================================================================

#ifndef test

int main() {
    // "Ce "zelite funkcijo <vstaviStolpec> testirati brez testnih primerov,
    // dopolnite to funkcijo in prevedite datoteko na obi"cajen na"cin
    // (gcc naloga3.c).
    return 0;
}

#endif
