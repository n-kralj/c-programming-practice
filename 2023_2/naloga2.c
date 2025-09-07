#include <stdio.h>
#include <string.h>

char niz[20];
int a, b;

char rez[20];
int len;


void generiraj(int ostanek, int kos){

    if (ostanek == 0) {
        if (kos >= a && kos <=b) {
            int k = 0;
            for (int i = 0; i<kos; i++) {
                int c = rez[i];
                for (int j = 0; j <c; j++) {
                    printf("%c", niz[k]);
                    k++;
                }
                if (i < (kos-1)) printf("|");
            }
            printf("\n");
        } 
        return;
    }

    if (kos == b) return;             
    if (kos + ostanek < a) return;


    int maxlen = ostanek;
    int preostaliKosi = b - (kos + 1);
    if (preostaliKosi > 0) {
        int max = ostanek - preostaliKosi;
        if (max < maxlen) maxlen = max;
    }

    for (int L = 1; L <= maxlen; ++L) {
        rez[kos] = L;
        generiraj(ostanek - L, kos + 1);
    }
}



int main(){
    scanf("%s %d %d", niz, &a, &b);
    
    len = strlen(niz);

    generiraj(len, 0);

}













































/*
char niz[21];
int n, min, max;

void izpis(char parts[][21], int k) {
    for (int i = 0; i < k; i++) {
        printf("%s", parts[i]);
        if (i < k - 1) {
            printf("|");
        }
    }
}


void razbij(int start, int stDelov, char parts[][21]) {
   if (start == n) {
        if (stDelov >= min && stDelov <= max) {
            izpis(parts, stDelov);
            printf("\n");  
        }
        return;
    }
    if (stDelov == max) return;

    for (int len = 1; len <= n - start; len++) {
        strncpy(parts[stDelov], niz + start, len);
        parts[stDelov][len] = '\0'; // dodamo zaključek

        razbij(start + len, stDelov + 1, parts);
    }
}

int main() {
    scanf("%s %d %d", niz, &min, &max);
    n = strlen(niz);

    char parts[20][21]; // 20 delov po max 20 znakov
    razbij(0, 0, parts);

    return 0;
}
*/