
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int main() {
    int n; scanf("%d", &n);
    
    int niz[n];
    for (int i = 0; i <n; i++) {
        scanf("%d", &niz[i]);
    }

    int kon=0;
    int curr = 0;
    int len = 0;
    bool gor, dol;

    while (curr < n) {
        if (kon == curr){
            len = 1;
            gor = false; dol = false;
            curr++;
        }

        if (!gor && !dol) {
            if (niz[curr] > niz[kon]) {
                gor = true;
                len = 2;
            } else {
                dol = true;
                len = 2;
            }
        } else {
            if (gor) {
                if (niz[curr] > niz[kon]) {
                    len++;
                    kon = curr;
                    curr++;
                } else {
                    printf("%d", len);
                    curr = kon;
                }
            } else {
                 if (niz[curr] < niz[kon]) {
                    len++;
                    kon = curr;
                    curr++;
                } else {
                    printf("%d\n", len);
                    curr = kon;
                }

            }
        }
    }

    printf("%d\n", len);

    return 0;
}

