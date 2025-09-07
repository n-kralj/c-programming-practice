
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(int argc, char** argv) {
    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    char polja[512];      
    int v[8][2];
    v[0][0] = 1;   v[0][1] = 2;
    v[1][0] = -1;   v[1][1] = -2;
    v[2][0] = 1;   v[2][1] = -2;
    v[3][0] = -1;   v[3][1] = 2;
    v[4][0] = 2;   v[4][1] = 1;
    v[5][0] = -2;   v[5][1] = -1;
    v[6][0] = 2;   v[6][1] = -1;
    v[7][0] = -2;   v[7][1] = 1; 
    /*int v[8][2] = {
        { 1,  2}, {-1, -2}, { 1, -2}, {-1,  2},
        { 2,  1}, {-2, -1}, { 2, -1}, {-2,  1}
    };*/
   


    int n, p;
    fscanf(fin, "%d %d\n", &n, &p);

   

    for (int i = 0; i<p; i++) {

        bool izpis = false;
        int* prisoten = calloc(8, sizeof(int));

        fgets(polja, 360, fin);

        int j = 0;
        int korak = 3;
        int x = 0;
        while (j < strlen(polja)) {
           x++;
            int s1 = polja[j] -'a';
            int v1 = polja[j+1]  -'0';

            if (polja[j+2] == '\n' || polja[j+2] == '\0') break;
            int s2 = polja[j+3] -'a';
            int v2 = polja[j+4] -'0';

            int s = s1-s2;
            int vk = v1-v2;
           
            if (s*vk != 2 && s*vk != - 2)  {
                //fprintf(fout, "ni skok 0, pri %d polje %d \n", x, j ); 
                fprintf(fout, "0\n");
                izpis = true;
                break;
            }

            for (int k = 0; k < 8; k++) {
                if (v[k][0] == s && v[k][1] == vk) prisoten[k] = 1;
            }
             // printf("ok4\n");

            j += korak;

        }

        if (izpis) continue;
        for (int i = 0; i<8; i++) {
            if (prisoten[i] == 0) {
               // fprintf(fout, "niso vsi v 0\n");
               fprintf(fout, "0\n");
                izpis = true;
                break; 

            }
        }
        if (izpis) continue;

        fprintf(fout, "1\n");

        free(prisoten);
    }
  

    fclose(fin);
    fclose(fout);
    return 0;
}
