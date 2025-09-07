
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>



int main(int argc, char** argv) {
  FILE* fin = fopen(argv[1], "rb");
  FILE* fout = fopen(argv[2], "wb");

  int prev, curr;
  prev = getc(fin);

  while ((curr = getc(fin)) != EOF) {
    if (curr != prev) {
      fputc(prev, fout);
      prev = curr;
      continue;
    } 
    prev = curr;
  }
    putc(prev, fout);
    return 0;
}

