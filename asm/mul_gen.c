#include <stdio.h>
#include <stdlib.h>

#include "mul.h"

#define N 128

signed int sa[N];
signed int sb[N];
signed int sr[N];

unsigned int ua[N];
unsigned int ub[N];
unsigned int ur[N];

void init(void)
{
  int i;

  // signed values
  i = 0;

  sa[i] = 0; sb[i] = 0; i++;
  sa[i] = 1; sb[i] = 0; i++;
  sa[i] = 0; sb[i] = 1; i++;
  sa[i] = 1; sb[i] = 1; i++;
  sa[i] =-1; sb[i] = 1; i++;
  sa[i] = 1; sb[i] =-1; i++;
  sa[i] =-1; sb[i] =-1; i++;

  sa[i] =0x7fffffff; sb[i] = 1; i++;
  sa[i] =0x7fffffff; sb[i] =-1; i++;
  sa[i] =0x80000000; sb[i] = 1; i++;
  sa[i] =0x80000000; sb[i] =-1; i++;
  sa[i] =0x10000000; sb[i] = 1; i++;
  sa[i] =0x10000000; sb[i] = 2; i++;
  sa[i] =0x10000000; sb[i] = 3; i++;
  sa[i] =0x10000000; sb[i] = 4; i++;
  sa[i] =0x10000000; sb[i] = 5; i++;
  sa[i] =0x10000000; sb[i] = 6; i++;
  sa[i] =0x10000000; sb[i] = 7; i++;
  sa[i] =0x10000000; sb[i] = 8; i++;
  sa[i] =0x10000000; sb[i] = 9; i++;
  sa[i] =0x10000000; sb[i] =10; i++;
  sa[i] =0x10000000; sb[i] =11; i++;
  sa[i] =0x10000000; sb[i] =12; i++;
  sa[i] =0x10000000; sb[i] =13; i++;
  sa[i] =0x10000000; sb[i] =14; i++;
  sa[i] =0x10000000; sb[i] =15; i++;
  sa[i] =0x10000000; sb[i] =16; i++;

  while (i < N) {
    sa[i] = random(); sb[i] = random(); i++;
  }

  // unsigned values
  i = 0;

  ua[i] = 0; ub[i] = 0; i++;
  ua[i] = 1; ub[i] = 0; i++;
  ua[i] = 0; ub[i] = 1; i++;
  ua[i] = 1; ub[i] = 1; i++;
  ua[i] =-1; ub[i] = 1; i++;
  ua[i] = 1; ub[i] =-1; i++;
  ua[i] =-1; ub[i] =-1; i++;

  ua[i] =0x7fffffff; ub[i] = 1; i++;
  ua[i] =0x7fffffff; ub[i] =-1; i++;
  ua[i] =0x80000000; ub[i] = 1; i++;
  ua[i] =0x80000000; ub[i] =-1; i++;
  ua[i] =0x10000000; ub[i] = 1; i++;
  ua[i] =0x10000000; ub[i] = 2; i++;
  ua[i] =0x10000000; ub[i] = 3; i++;
  ua[i] =0x10000000; ub[i] = 4; i++;
  ua[i] =0x10000000; ub[i] = 5; i++;
  ua[i] =0x10000000; ub[i] = 6; i++;
  ua[i] =0x10000000; ub[i] = 7; i++;
  ua[i] =0x10000000; ub[i] = 8; i++;
  ua[i] =0x10000000; ub[i] = 9; i++;
  ua[i] =0x10000000; ub[i] =10; i++;
  ua[i] =0x10000000; ub[i] =11; i++;
  ua[i] =0x10000000; ub[i] =12; i++;
  ua[i] =0x10000000; ub[i] =13; i++;
  ua[i] =0x10000000; ub[i] =14; i++;
  ua[i] =0x10000000; ub[i] =15; i++;
  ua[i] =0x10000000; ub[i] =16; i++;

  while (i < N) {
    ua[i] = random(); ub[i] = random(); i++;
  }
}


void compute(void)
{
  int i;

  // signed values
  i = 0;
  while (i < N) {
    sr[i] = sa[i] * sb[i]; i++;
  }

  // unsigned values
  i = 0;
  while (i < N) {
    ur[i] = ua[i] * ub[i]; i++;
  }
}


void dump(void)
{
  int i;

  printf("#define N %d\n\n", N);

  printf("int sa[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%d, ", sa[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");

  printf("int sb[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%d, ", sb[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");

  printf("int sr[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%d, ", sr[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");

  printf("unsigned int ua[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%u, ", ua[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");

  printf("unsigned int ub[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%u, ", ub[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");

  printf("unsigned int ur[N] = {\n  ");
  i = 0;
  while (i < N) {
    printf("%u, ", ur[i]);
    i++;
    if (i % 16 == 0) printf("\n  ");
  }
  printf("};\n\n");
}

int main(int argc, char *argv[])
{
  srand(0);

  init();
  compute();
  dump();

  return EXIT_SUCCESS;
}
