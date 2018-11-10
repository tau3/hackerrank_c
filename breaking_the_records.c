#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LENGTH = 9 * 1000 + 999 + 1;

void str_to_int_array(int *s, int n, char *str) {
  s[0] = atoi(strtok(str, " "));
  for (int i = 1; i < n; i++) {
    int val = atoi(strtok(NULL, " "));
    s[i]=val;
  }
}

int main() {
  int n;
  scanf("%d\n", &n);

  char str[MAX_LENGTH];
  fgets(str, MAX_LENGTH, stdin);

  int s[n];
  str_to_int_array(s, n, str);

  int best = s[0], worst = s[0], breaks_best = 0, breaks_worst = 0;

  for (int i = 1; i < n; i++) {
    if (s[i] > best) {
      best = s[i];
      breaks_best++;
    } else if (s[i] < worst) {
      worst = s[i];
      breaks_worst++;
    }
  }

  printf("%d %d\n", breaks_best, breaks_worst);

  return 0;
}
