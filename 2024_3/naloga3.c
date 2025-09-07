


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int n, k;
int max;

//1 ... ovira, 0 ... napadanje, 2 ... konj

bool outOfBound(int v, int s, int vc, int sc) {
    if ((v+vc) >= 0 && (v+vc) <n && (s+sc) >= 0 && (s+sc) <n) return true;
    return false;
}

int vektor[][2] = {
    {1, 2}, {2, 1}, {-1, -2}, {-2, -1}, 
    {1, -2}, {-2, 1}, {-1, 2}, {2, -1}
};

void rek(int st, int currV, int currS,  int poz[n][n]) {
    if (currV == n)  {
        if (st > max) max = st;
        return;
    }

    int nextV = currV, nextS = currS + 1;
    if (nextS == n) { nextS = 0; nextV++; }

    rek(st, nextV, nextS, poz); //prva veja
   
    // 2) veja: postavi skakača, če je polje dovoljeno (-1 = prosto, 1 = ovira, 0 = napadeno, 2 = skakač)
    if (poz[currV][currS] != 1 && poz[currV][currS] != 0 && poz[currV][currS] != 2) {
        int cp[n][n];
        for (int r = 0; r < n; r++)
            for (int c = 0; c < n; c++)
                cp[r][c] = poz[r][c];

        cp[currV][currS] = 2;


        for (int x = 0; x < 8; x++) {
            int dv = vektor[x][0], ds = vektor[x][1];   
            if (outOfBound(currV, currS, dv, ds)) {
                int nv = currV + dv, ns = currS + ds;
                if (cp[nv][ns] != 1 && cp[nv][ns] != 2)   
                    cp[nv][ns] = 0;                      
            }
        }

 
        rek(st + 1, nextV, nextS, cp);
    }
    
   return;
}


int main() {
    scanf("%d %d", &n, &k);
    int poz[n][n];
    max = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) poz[i][j] = -1;
    }

    for (int i = 0; i < k; i++) {
        int v, s;
        scanf("%d %d", &v, &s);
        poz[v][s] = 1;
    }

    rek(0, 0, 0, poz);
    printf("%d\n", max);
    
    return 0;
}
