#define MAX_LENGTH 7

#include <stdio.h>

int main() {
  int n;
  scanf("%d\n", &n);
  char s[n];
  scanf("%s\n", s);

  int h = 0;
  int res = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'D') {
      h--;
    } else {
      h++;
      if (h == 0) {
        res++;
      }
    }
  }

  printf("%d\n", res);

  return 0;
}
