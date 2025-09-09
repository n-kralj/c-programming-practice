
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* fin = fopen(argv[1], "rb");
    FILE* fout = fopen(argv[2], "wb");
    int k = atoi(argv[3]);

    long long bit = 0;   
    int ch;

    while ((ch = fgetc(fin)) != EOF) {
        int b = ch ;        

        // z leve proti desni: 7 -> 0
        for (int i = 7; i >= 0; i--) {
            bit++;
            if (bit % k == 0) {
                b ^= (1 << i);        // negiraj k-ti bit
            }
        }
        fputc(b, fout);
    }


    fclose(fin);
    fclose(fout);
    return 0;
}

