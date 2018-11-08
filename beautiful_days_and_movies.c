#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INT_LENGTH 6

char *itoa(int n) {
  char *result = malloc(sizeof(int) * (MAX_INT_LENGTH + 1));
  sprintf(result, "%d", n);
  return result;
}

char *reverse(const char *str) {
  int l = strlen(str);

  char *res = malloc(sizeof(char) * (l + 1));
  for (int i = 0; i < l; i++) {
    res[i] = str[l - 1 - i];
  }
  res[l] = '\0';

  return res;
}

int is_beautiful(int day, int k) {
  char *day_as_string = itoa(day);
  char *reversed = reverse(day_as_string);

  int reversed_day = atoi(reversed);
  int result = (abs(day - reversed_day) % k) == 0;

  free(reversed);
  free(day_as_string);

  return result;
}

int main() {
  int i, j, k;
  scanf("%d %d %d\n", &i, &j, &k);

  int res = 0;
  for (int p = i; p <= j; p++) {
    res += is_beautiful(p, k);
  }
  printf("%d\n", res);

  return 0;
}
