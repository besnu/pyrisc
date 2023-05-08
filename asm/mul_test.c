#include "mul_data.h"

#include "mul.h"

int main(int argc, char *argv[])
{
  int i;
  int res;
  unsigned int ures;

  // signed test
  i = 0;
  while (i < N) {
    res = mul(sa[i], sb[i]);
    if (res != sr[i]) return -i;
    i++;
  }

  // unsigned test
  i = 0;
  while (i < N) {
    ures = umul(ua[i], ub[i]);
    if (ures != ur[i]) return i;
    i++;
  }

  return 0;
}
