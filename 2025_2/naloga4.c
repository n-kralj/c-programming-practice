

#include <stdio.h>
#include <string.h>

static long long memo[101][101][201]; // [b][c][diff + k]
int k;

long long rek(int b, int c, int diff) {
    if (diff < -k || diff >  k) return 0;       
    if (b == 0 && c == 0) return 1;   

    int idx = diff + k; 
    if (memo[b][c][idx] != -1) return memo[b][c][idx];               // že izračunano

    long long res = 0;
    if (b > 0) res += rek(b - 1, c, diff + 1);   // dodamo belo
    if (c > 0) res += rek(b, c - 1, diff - 1);   // dodamo črno
    
    memo[b][c][idx] = res;
    return res;
}

int main(void) {
    int m, n;
    scanf("%d %d %d", &m, &n, &k);

    memset(memo, 0xFF, sizeof memo);

    printf("%lld\n", rek(m, n, 0));
    return 0;
}

