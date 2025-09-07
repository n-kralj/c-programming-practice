
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main() {
    int vrste, stolpci;
    scanf("%d %d", &vrste, &stolpci);

    int el = vrste*stolpci;
    int zapA[el], zapB[vrste+1], zapC[el];
    zapB[0] = 0;

    int a = 0;
    int c = 0;
    int nenic = 0;
    int tab[vrste][stolpci];

    for (int i = 0; i<vrste; i++) {
         nenic = 0;
        for (int j= 0; j<stolpci; j++)  {
           
            scanf("%d", &tab[i][j]);
            int curr = tab[i][j];

            if (curr != 0) {
                zapA[a] = curr;
                a++;
                nenic++;

                zapC[c] = j;
                c++;
            }
        }

        if (i == 0) {
            zapB[i+1] = nenic;
        } else {
            zapB[i+1] = zapB[i] + nenic;
        }
    }

    zapB[vrste] = zapB[vrste-1] + nenic;

    if (a == 0) printf("\n");
   for (int i = 0; i<a; i++) {
        if (i == a- 1) printf("%d\n", zapA[i]);
        else printf("%d_", zapA[i]);
   }

   for (int i = 0; i<=vrste; i++) {
        if (i == vrste) printf("%d\n", zapB[i]);
        else printf("%d_", zapB[i]);
   }

   if (c == 0) printf("\n");
   for (int i = 0; i<c; i++) {
        if (i == c- 1) printf("%d\n", zapC[i]);
        else printf("%d_", zapC[i]);
   }

    return 0;
}
