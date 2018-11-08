#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH (3 * 100 + 99)

int *parse_int_array(char *str, size_t size) {
  int *result = malloc(sizeof(int) * size);

  char *token = strtok(str, " ");
  int i = 0;

  while (token) {
    result[i++] = atoi(token);
    token = strtok(NULL, " ");
  }

  return result;
}

int main() {
  int n;
  int k;
  scanf("%d %d\n", &n, &k);
  char s_raw[MAX_LENGTH];
  fgets(s_raw, MAX_LENGTH + 1, stdin);
  int *s = parse_int_array(s_raw, n);

  int sum;
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      sum = s[i] + s[j];
      if ((sum >= k) && ((sum % k) == 0)) {
        // printf("(%d, %d) -> ar[%d] + ar[%d] = %d + %d = %d\n", i, j, i, j, s[i],
        //        s[j], sum);
        result++;
      }
    }
  }

  printf("%d\n", result);

  free(s);
  return 0;
}
