
#include "naloga.h" 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


void obdelaj(Vozlisce* zacetek, int k) {
    int sum = 0;
    Vozlisce* start = zacetek;
    Vozlisce* curr = zacetek;
    Vozlisce* prev = zacetek;

    for (int i = 0; i < k; i++) {
        sum += curr->podatek;
        curr = curr->next;
        if (i != (k-1)) prev = prev->next;
    }

    while(curr != NULL) {
        
        while (sum == curr->podatek) {
            prev->next = curr->next;
            curr=curr->next;
        }
        sum -= start->podatek;
        sum += curr->podatek;

        start = start->next;
        prev = prev->next;
        curr = curr->next;
    }
}

int main() {


    return 0;
}
