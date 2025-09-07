
#include "naloga2.h"

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element) {

    if (zacetek == NULL) {
        Vozlisce* curr = malloc(sizeof(Vozlisce));
        curr->podatek = element;
        curr->n = NULL;
        curr->nn = NULL;
        return curr;
    }


    Vozlisce* start = zacetek;
    Vozlisce* p = zacetek;


    if (start->podatek > element){
        Vozlisce* curr = malloc(sizeof(Vozlisce));
        curr->podatek = element;
        curr->n = zacetek;
        curr->nn = zacetek->n;
        return curr;
    } else {
        if (start->n->podatek > element) {
            Vozlisce* curr = malloc(sizeof(Vozlisce));
            curr->podatek = element;
            curr->n = start->n;
            curr->nn = start->nn;
            start->n = curr;
            start->nn = curr->n;
            return zacetek;
        }
        start = start->n;
    }



    while (start->n != NULL && start->n->podatek < element) {
        p = p->n;
        start = start->n;
    }

     Vozlisce* curr = malloc(sizeof(Vozlisce));
     curr->podatek = element;
     curr->n = start->n;
     curr->nn = start->nn;
     start->n = curr;
     start->nn = curr->n;
     p->nn = curr;



    return zacetek;

}

int main() {

    return 0;
}

