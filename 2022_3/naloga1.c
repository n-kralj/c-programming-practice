
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char** argv) {
    FILE *in = fopen(argv[1], "rb");
    FILE *out = fopen(argv[3], "wb");
    int prag = atoi(argv[2]);

    int w, h;
    fscanf(in, "%*s %d %d %*d", &w, &h);
    // printf(" ok\n");
     fprintf(out, "P5\n%d %d\n255\n", w, h);

     fgetc(in); // preberi en \n po max vrednosti

     for (int i = 0; i < w*h; i++) {
         int pixel = fgetc(in);
         if (pixel >= prag)
            fputc(255, out);
        else
            fputc(0, out);

     }

    fclose(in);
    fclose(out);

    return 0;
}
