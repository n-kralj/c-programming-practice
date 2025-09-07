
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n, a, b;
int sol[64];


void dfs(int remain, int start, int k) {
    if (k > b) return;                
    if (remain == 0) {               
        if (k >= a && k <= b) {
            for (int i = 0; i < k; i++) {
                printf("%d", sol[i]);       
                if (i < k - 1) {  // če ni zadnji člen, dodamo '+'
                    putchar('+');
                }
            }
            putchar('\n');
        }
        return;
    }

    for (int i = start; i <= remain; i++) { 
        sol[k] = i;
        dfs(remain - i, i, k + 1);
    }
}
int main(){
    scanf("%d %d %d", &n, &a, &b);
    dfs(n, 1, 0);
    return 0;
}































/*
int n, a, b;
int result[100];

void find_sums(int sum, int length, int last) {
    if (length > b) return;
    if (sum > n) return;

    if (sum == n && length >= a && length <= b) {
        for (int i = 0; i < length; i++) {
            if (i > 0) printf("+");
            printf("%d", result[i]);
        }
        printf("\n");
        return;
    }

    for (int i = last; i <= n; i++) {
        result[length] = i;
        find_sums(sum + i, length + 1, i);
    }
}

int main() {
    scanf("%d %d %d", &n, &a, &b);
    find_sums(0, 0, 1);
    return 0;
}
*/