#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10

char *read_line() {
  size_t pos = 0;
  size_t current_size = INITIAL_SIZE;
  char *line = malloc(current_size * sizeof(char));

  char c = fgetc(stdin);
  while ((c != '\n') && (c != EOF)) {
    line[pos++] = c;
    if (pos == (current_size - 1)) {
      current_size *= 2;
      char *new_line = realloc(line, sizeof(char) * current_size);
      if (new_line) {
        line = new_line;
      } else {
        break;
      }
    }
    c = fgetc(stdin);
  }

  return line;
}

int main() {
  char *line = read_line();
  printf("%s\n", line);
  free(line);
  return 0;
}
