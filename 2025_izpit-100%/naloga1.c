
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include <ctype.h>

#include "naloga1.h"

void pretvori(char** nizi) {
    int i = 0;
    while(nizi[i] != NULL){
        
        char c = *nizi[i];
        c = toupper(c);
        *nizi[i] = c; 

        int j = 1;
        while(*(nizi[i]+j) != '\0') {
           
            
            if (*(nizi[i]+j) == ' ') {
                j++;
                // printf("niz %c\n", *(nizi[i]+j));

                if (*(nizi[i]+j) != '\0'){
                    char ch = *(nizi[i]+j);
                    ch = toupper(ch);
                    *(nizi[i]+j) = ch;
                }
            }
            j++;
        }
        
       i++;
    }
}
#ifndef test

int main() {
    return 0;
}

#endif
