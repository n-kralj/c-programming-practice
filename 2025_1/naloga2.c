
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
    char ime[100];
    int h, w,n;
    scanf("%s %d %d %d", ime, &h, &w, &n);
    FILE* fin = fopen(ime, "rb");

    for (int i = 0; i<n; i++) {
        int v, s;
        scanf("%d %d", &v, &s);

        fseek(fin, (v*w + s)/8, SEEK_SET);
        int x = fgetc(fin);
        int zamik = 7 - (v*w + s)%8;
        int y = (x >> zamik) &1;
        printf("%d\n", y);
    }

    return 0;
}
