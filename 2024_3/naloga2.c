

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// po potrebi dopolnite ...

typedef struct {
        char ime[105];
        int starost;
        int pojavitve;
    } Entiteta;


int main(int argc, char **argv) {

    char *C   = argv[3];   

    FILE *fin  = fopen(argv[1], "r");
    FILE *fout = fopen(argv[2], "w");
    if (!fin || !fout) return 1;


    char line[20000];

    char curr[110];
    int idx = 0;
    int s1 = -1, st = -1;

   while (1) {
    int ch = fgetc(fin);
    if (ch == '\n' || ch == EOF) {
        break; } 
    ungetc(ch, fin);
    fscanf(fin, "%s", curr);
    if (strcmp(curr, C) == 0) s1 = idx;
    if (strcmp(curr, "starost") == 0) st = idx;
    idx++;  
    }


    Entiteta **entitete = malloc(100 * sizeof *entitete);
    int e = 0;


    while (fgets(line, sizeof line, fin)) {
        // razbij vrstico na tokene
        int col = 0;
        char ime[101] = {0};
        int starost = -1;

  
        for (char *tok = strtok(line, " \n");  
            tok != NULL;                       
            tok = strtok(NULL, " \n"), col++)  
        {
            if (col == s1) {
                strncpy(ime, tok, 100);
                ime[100] = '\0';
            } else if (col == st) {
                starost = atoi(tok);
            }
        }

    

        // poišči ali obstaja
        bool je = false;
        for (int i = 0; i < e; i++) {
            if (strcmp(entitete[i]->ime, ime) == 0) {
                entitete[i]->pojavitve++;
                entitete[i]->starost += starost;  // seštejemo
                je = true;
                break;
            }
        }
        if (!je) {
            Entiteta *en = malloc(sizeof *en);
            strcpy(en->ime, ime);
            en->starost = starost;  // začnemo z vsoto
            en->pojavitve = 1;
            entitete[e++] = en;
        }
    }

    // izračun navzdol zaokroženega povprečja in izpis
    for (int i = 0; i < e; i++) {
        int avg = entitete[i]->starost / entitete[i]->pojavitve; // floor
        fprintf(fout, "%s,%d\n", entitete[i]->ime, avg);
        free(entitete[i]);
    }
    free(entitete);
    fclose(fin);
    fclose(fout);
    return 0;
}