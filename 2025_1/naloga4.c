
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
long long st = 0;

int len;
long long memo[101][101][3][4]; 
char seen[101][101][3][4];


long long rek(int b, int c, int last, int run) {
    if (b == 0 && c == 0) return 1;
    if (seen[b][c][last][run]) return memo[b][c][last][run];
    seen[b][c][last][run] = 1;

    long long res = 0; 
     if (b > 0) {
        if (last != 1 || run < 2) {
            int nlast = 1;
            int nrun  = (last == 1) ? run + 1 : 1;
            res += rek(b - 1, c, nlast, nrun);
        }
    }
    // dodamo črno (max 3 zapored)
    if (c > 0) {
        if (last != 2 || run < 3) {
            int nlast = 2;
            int nrun  = (last == 2) ? run + 1 : 1;
            res += rek(b, c - 1, nlast, nrun);
        }
    }

    return memo[b][c][last][run] = res;

}



int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    len = m+n;

    printf("%lld\n",  rek(m, n, 0, 0));


    return 0;
}
