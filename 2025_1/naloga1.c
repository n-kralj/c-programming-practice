
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    int i = 1;
    while(argv[i]) {
       if(*argv[i] == '-' && *(argv[i]+1) != '-') {
            char zacasno[30];
            strcpy(zacasno, (argv[i]+1));
            int n = strlen(zacasno);
            zacasno[n] = '\0';
            printf("%s %s\n", zacasno, argv[i+1]);
            i++;
       } else {
            char zacasno[30];
            strcpy(zacasno, (argv[i]+2));
            int n = strlen(zacasno);
            zacasno[n] = '\0';
            printf("%s True\n", argv[i] + 2);
       }
       //printf("%c", *(argv[i]+1));
       i++;
    }
    return 0;
}
