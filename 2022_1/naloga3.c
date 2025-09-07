

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int  stZnakov[50];
char znaki[50];
int dolzina;
int n;

void generate(int len, char curr[]) {

  if (len == dolzina) {
     curr[len] = '\0'; 
      printf("%s\n", curr);
      return;
  }
  for (int i = 0; i < n; i++) {
      if (stZnakov[i] < 3){
          stZnakov[i]++;

          curr[len] = znaki[i];  
          generate(len+1, curr);
          stZnakov[i]--; 
      }
    
  }  
}

int main() {
   
    scanf("%d %s %d", &n, znaki, &dolzina);
    char curr[25];
     for (int i = 0; i < n; i++) stZnakov[i] = 0;
    generate(0, curr); 

  // printf("%d %s %d", n, znaki, dolzina);
   
}