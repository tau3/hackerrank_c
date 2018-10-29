#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int has_mineral(char *rock, char mineral) {
  int result = 0;
  for (int i = 0; i < strlen(rock); i++) {
    if (rock[i] == mineral) {
      result = 1;
      break;
    }
  }
  return result;
}

int is_gemstone(char **rocks, int n, char mineral) {
  int result = 1;
  for (int i = 0; i < n; i++) {
    char *rock = rocks[i];
    if (!has_mineral(rock, mineral)) {
      result = 0;
      break;
    }
  }
  return result;
}

int calculate_gemstones(char **rocks, int n) {
  char *minerals = "abcdefghijklmnopqrstuvwxyz";

  int result = 0;
  for (int i = 0; i < strlen(minerals); i++) {
    char mineral = minerals[i];
    if (is_gemstone(rocks, n, mineral)) {
      result++;
    }
  }
  return result;
}

void read_rocks(char ***rocks, int *n) {
  scanf("%d\n", n);
  *rocks = (char **)malloc((*n) * sizeof(char *));

  for (int i = 0; i < (*n); i++) {
    (*rocks)[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
    scanf("%s\n", (*rocks)[i]);
  }
}

void free_rocks(char ***rocks, int n) {
  for (int i = 0; i < n; i++) {
    free((*rocks)[i]);
  }
  free(*rocks);
}

int main() {
  int n;
  char **rocks;
  read_rocks(&rocks, &n);

  int result = calculate_gemstones(rocks, n);
  printf("%d\n", result);

  free_rocks(&rocks, n);

  return 0;
}
