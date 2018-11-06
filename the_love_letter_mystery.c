#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 10000

void reverse(char *str) {
  int l = strlen(str);
  for (int i = 0; i < l / 2; i++) {
    char buf = str[i];
    int swap = l - 1 - i;
    str[i] = str[swap];
    str[swap] = buf;
  }
}

int permutations(char *str) {
  int l = strlen(str);

  char *reversed = malloc(sizeof(char) * (l + 1));
  strcpy(reversed, str);
  reverse(reversed);

  int result = 0;
  for (int i = 0; i < l / 2; i++) {
    result += abs(reversed[i] - str[i]);
  }
  free(reversed);

  return result;
}

int main() {
  char str[MAX_LENGTH];
  gets(str);
  int q = atoi(str);
  int res[q];
  for (int i = 0; i < q; i++) {
    gets(str);
    res[i] = permutations(str);
  }
  for (int i = 0; i < q; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}
