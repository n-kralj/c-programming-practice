

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long long memo [21][42];

long long rek(int tot, int rez){
 
    if (rez < 0) return 0;

    if (tot == 0) return 1;
 
    if (memo[tot][rez] != -1) return memo[tot][rez];

    long long st = 0;

    //bila je 1
    st+= rek(tot-1, rez+1);

    //bila je 2
    st+= rek(tot-1, rez-1);

    memo[tot][rez] = st;
 
    return st;
}


int main() {
    int n,k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i<21; i++) {
        for (int j= 0; j<42; j++) {
            memo[i][j] = -1;
        }
    }

    long long stev = rek(n, k);
    
    printf("%lld\n", stev);

    return 0;
}
