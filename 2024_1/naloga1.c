
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(int argc, char** argv) {
  

    char* line = calloc(350, sizeof(char));
  

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");

    int n, p;
    fscanf(fin, "%d %d/n", &n, &p);

    char polja[n][n];
    for(int i = 0; i < n; i++) {
         for(int j = 0; j < n; j++) polja[i][j] = 0;
    }


    while(fgets(line, 350, fin)) {
        int korak = 3;
        int i = 0;
        bool sprehod = true;
        bool prvi = true;
         memset(polja, 0, sizeof(polja));


        while(line[i] != '\n' && line[i] != '\0') {

            //prvo polje
            int stolp1, stolp2, vrsta1, vrsta2;
            stolp1 = (int)line[i];
            vrsta1 = line[i+1];
            if(prvi) {
                prvi = false;
                polja[stolp1 - 'a'][vrsta1 - '1'] = 1;
            }

            //drugo polje
           if (line[i+4] == '\n' || line[i+4] == '\0') break; 
            stolp2 = (int)line[i+3];
            vrsta2 = line[i+4];

            if(polja[stolp2 - 'a'][vrsta2- '1'] == 1) {
                 fprintf(fout, "0\n");
                 sprehod = false;
                 break;

            } else {
                polja[stolp2 - 'a'][vrsta2 - '1'] = 1;
            }

            int rez = (stolp1 - stolp2)*(vrsta1-vrsta2);
            if (rez < 0) rez *= -1;

            if(rez != 2) {
                fprintf(fout, "0\n");
                sprehod = false;
                break;
            }
            i += korak;
        }

        if (sprehod) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(polja[i][j] == 0)  {
                        fprintf(fout, "0\n");
                        sprehod = false;
                        break;
                    }
                }
            }
        }

       
        if (sprehod) fprintf(fout, "1\n");
        
    }
    free(line);
    return 0;
}