
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char** argv) {
    int sum = 0;

    FILE *fin = fopen(argv[1], "rb");
    int c;
    while((c=fgetc(fin)) != EOF) {
        for (int i = 0; i < 8; i++){
           int s = (c >> i) & 1;
           sum += s;
        }

    }

    printf("%d\n", sum);


    fclose(fin);
    return 0;
}
