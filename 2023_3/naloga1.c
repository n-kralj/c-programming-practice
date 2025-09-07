
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(int argc, char** argv) {
    

    FILE* f1 = fopen(argv[1], "rb");
    FILE* f2 = fopen(argv[2], "rb");
    FILE* fout = fopen(argv[3], "wb");
    int c1, c2;
    
    while((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF) {
        if ( c1 < c2) {
            fprintf(fout, "%c", c2);
        } else {
            fprintf(fout, "%c", c1);
        }
    }

    if (c1 == EOF) {
        while((c2 = fgetc(f2)) != EOF){
              fprintf(fout, "%c", c2);
        }   
    } else if (c2 == EOF) {
           fprintf(fout, "%c", c1);
         while((c1 = fgetc(f1)) != EOF){
              fprintf(fout, "%c", c1);
        }
    }

    
    fclose(f1);
    fclose(f2);
    fclose(fout);
    return 0;
}
