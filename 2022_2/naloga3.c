#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main() {
  int n, v0, s0, h, w;
  scanf("%d %d %d %d %d", &n, &v0, &s0, &h, &w);

  unsigned long long stPolnih = 1;
  unsigned long long dolzinaStranice = 1;
  for (int i = 0; i < n; i++) {
    dolzinaStranice*=2LLU;
    stPolnih*=3LLU;
  }
  printf("%llu\n", stPolnih);
  
  int left = dolzinaStranice-s0-1; // max = dolzinaStranice-1 
  int right = dolzinaStranice-w-s0; // min = 0
  int bottom = v0+h; // max = dolzinaStranice
  int top = v0; // min = 0

  for (int i = top; i < bottom; i++) {
    for (int j = left; j >= right; j--) {
      if (i&j) {
        printf("-");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
  return 0;
}