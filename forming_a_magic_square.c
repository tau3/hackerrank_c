#include <stdio.h>
#include <stdlib.h>

#define LENGTH 9
#define MAGIC_SQUARES_COUNT 8

// yep, it's stollen
const int magic_squares[MAGIC_SQUARES_COUNT][LENGTH] = {
    {8, 1, 6, 3, 5, 7, 4, 9, 2}, {8, 3, 4, 1, 5, 9, 6, 7, 2},
    {2, 7, 6, 9, 5, 1, 4, 3, 8}, {2, 9, 4, 7, 5, 3, 6, 1, 8},
    {6, 1, 8, 7, 5, 3, 2, 9, 4}, {6, 7, 2, 1, 5, 9, 8, 3, 4},
    {4, 3, 8, 9, 5, 1, 2, 7, 6}, {4, 9, 2, 3, 5, 7, 8, 1, 6}};

int *read_2d_array(void) {
  int *res = malloc(LENGTH * sizeof(int));
  for (int i = 0; i < 3; i++) {
    scanf("%d %d %d\n", res + (3 * i), res + (3 * i) + 1, res + (3 * i) + 2);
  }

  return res;
}

int main() {
  int *square = read_2d_array();

  int result = 999, current = 0;
  for (int i = 0; i < MAGIC_SQUARES_COUNT; i++) {
    current = 0;
    const int *magic_square = magic_squares[i];
    for (int j = 0; j < LENGTH; j++) {
      current += abs(magic_square[j] - square[j]);
    }
    if (current < result) {
      result = current;
    }
  }

  printf("%d\n", result);

  free(square);
  return 0;
}
