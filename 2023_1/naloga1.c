

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>




int main(int argc, char *argv[]) {
    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen(argv[2], "wb");

     int c, prev;
     prev = fgetc(in);

     while (prev != EOF){
        c = fgetc(in);
        if (c != EOF) {
            if (!strcmp(prev, "1B")) {
                if (!strcmp(c, "C9")) fputc(c, out);
                else{
                    fputc(prev, out);
                }
            } else{
                fputc(prev, out);
                prev = c;
            }
        } else {
            fputc(prev, out);
            prev = c;
        }
    }
   fclose(out);
   fclose(in);
   return 0;
}

