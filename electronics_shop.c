#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INITIAL_LENGTH;

void str_to_int_array(int *result, int n, char *str) {
  result[0] = atoi(strtok(str, " "));
  for (int i = 1; i < n; i++) {
    int val = atoi(strtok(NULL, " "));
    result[i] = val;
  }
}

char *get_line() {
  size_t current_size = INITIAL_LENGTH, pos = 0;
  char *result = malloc(INITIAL_LENGTH * sizeof(char)), *new_buffer;
  char c = fgetc(stdin);
  while ((c != '\n') && (c != EOF)) {
    result[pos++] = c;
    if (pos == (current_size - 1)) {
      current_size *= 2;
      new_buffer = realloc(result, current_size * sizeof(char));
      if (new_buffer) {
        result = new_buffer;
      } else {
        break;
      }
    }
    c = fgetc(stdin);
  }

  result[pos] = '\0';

  new_buffer = realloc(result, (pos + 1) * sizeof(char));
  if (new_buffer) {
    result = new_buffer;
  }

  return result;
}

int main() {
  int b, n, m;
  scanf("%d %d %d\n", &b, &n, &m);

  char *keyboards_raw = get_line();
  int *keyboards = malloc(n * sizeof(int));
  str_to_int_array(keyboards, n, keyboards_raw);
  free(keyboards_raw);

  char *drives_raw = get_line();
  int *drives = malloc(m * sizeof(int));
  str_to_int_array(drives, m, drives_raw);
  free(drives_raw);

  int result = -1, current;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      current = drives[j] + keyboards[i];
      if ((current <= b) && (current > result)) {
        result = current;
      }
    }
  }

  free(keyboards);
  free(drives);

  printf("%d\n", result);

  return 0;
}
