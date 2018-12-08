#include <stdio.h>
#include <stdlib.h>

int* zero_array(int n){
  int* result = malloc(sizeof(int) * n);
  while(--n >= 0) {
    result[n] = 0;
  }
  return result;
}

int main() {
  int n, k;
  scanf("%d %d\n", &n, &k);

  int* occ = zero_array(k);
  int i;
  while(--n >= 0) {
    scanf("%d", &i);
    occ[i % k]++;
  }

  int res = 0;
  for (i = 1; i < (k + 1) / 2; i++) {
    res += occ[i] > occ[k - i] ? occ[i] : occ[k - i];
  }
  res += (occ[0] >= 1) + (k % 2 == 0 && occ[k / 2]);

  printf("%d\n", res);

  free(occ);
  return 0;
}

