

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

#include "naloga2.h"


int exists (Vozlisce* current, int* numbers, int counter){

    for (int i=0; i<counter; i++){
        if (current->podatek == numbers[i]){
            return 1;
        }
    }
    return 0;
}

void izlociSkupne(Vozlisce* a, Vozlisce* b, Vozlisce** noviA, Vozlisce** noviB) {
    

    int* numbersA=malloc(1000*sizeof(int));
    int* numbersB=malloc(1000*sizeof(int));

    Vozlisce* temp = a;

    int counterA=0;
    while (temp!=NULL){
        numbersA[counterA]=temp->podatek;
        counterA++;
        temp=temp->naslednje;
    }

    temp = b;
    int counterB=0;
    while (temp!=NULL){
        numbersB[counterB]=temp->podatek;
        counterB++;
        temp=temp->naslednje;
    }

    Vozlisce** seznamA = calloc(1001,sizeof(Vozlisce));
    int stevecA=0;
    Vozlisce** seznamB = calloc(1001,sizeof(Vozlisce));
    int stevecB=0;


    temp = a;
    while (temp!=NULL){
        int obstaja = exists(temp, numbersB, counterB);
        if (obstaja==1){
            temp->podatek= -1;
        }
        else{
            seznamA[stevecA]=temp;
            stevecA++;
        }
        temp=temp->naslednje;
    }

    temp = b;
    while (temp!=NULL){
        int obstaja = exists(temp, numbersA, counterA);
        if (obstaja==1){
            temp->podatek= -1;
        }
        else{
            seznamB[stevecB]=temp;
            stevecB++;
        }
        temp=temp->naslednje;
    }

    for (int i=0; i<stevecA; i++){
        seznamA[i]->naslednje=seznamA[i+1];
    }

    for (int i=0; i<stevecB; i++){
        seznamB[i]->naslednje=seznamB[i+1];
    }


    *noviA=seznamA[0];
    *noviB=seznamB[0];

}



#ifndef test

int main() {

    return 0;
}

#endif
