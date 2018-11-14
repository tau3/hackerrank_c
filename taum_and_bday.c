#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long price_t;

int main() {
  int t;
  price_t b, w, bc, wc, z;
  scanf("%d\n", &t);

  while (t-- > 0) {
    scanf("%llu %llu\n", &b, &w);
    scanf("%llu %llu %llu\n", &bc, &wc, &z);

    bc = bc > wc ? ((bc - wc > z) ? wc + z : bc) : bc;
    wc = wc > bc ? ((wc - bc > z) ? bc + z : wc) : wc;

    printf("%llu\n", wc * w + bc * b);
  }

  return 0;
}
