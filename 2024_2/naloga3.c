

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int n, k;
int izpis[512];

int tot = 0;

void rek(int nivo, int node, unsigned char* data) {
    if (nivo == k) {
        izpis[tot] = node;
        tot++;
        return;
    }
    if (node != 0) {
         int levo = 2*node -2;
        int desno = 2*node-1;

        if (data[levo]  != 0) rek(nivo+1, data[levo], data);
        if (data[desno]  != 0) rek(nivo+1, data[desno], data);

    }
   return;

}

int main() {
   char ime[20];
   
   scanf("%s %d %d", ime, &n, &k);

  unsigned char* data = calloc(520, sizeof(int));
   FILE* fin = fopen(ime, "rb");
   //fgets(data, 512, fin);
    size_t prebrano = fread(data, 1, 2 * n, fin);


   rek(0, 1, data);

   for (int i= 0; i<tot; i++) {
        if (izpis[i] != 0) printf("%d\n", izpis[i]);
   }


    return 0;
}
