
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char** argv) {
    FILE* fin = fopen(argv[1], "rb");
    FILE* fout = fopen(argv[2], "wb");

    int ch;
    while((ch = getc(fin)) != EOF){
        int bajt = ch;
        if (bajt &(1<<7)) {
            ch = getc(fin);
            char c = '?';
            c = (int)c;
            fputc(c, fout);
        } else{
            fputc(ch, fout);
        }

    }


    fclose(fin);
    fclose(fout);

    return 0;
}
