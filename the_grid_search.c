#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *values;
  int rows;
  int columns;
} grid_t;

int at(grid_t g, int row, int column) {
  int width = g.columns;
  int n = width * row + column;
  return g.values[n];
}

int is_pattern(grid_t p, grid_t g, int row, int column) {
  int rg, cg;
  for (int rp = 0; rp < p.rows; rp++) {
    for (int cp = 0; cp < p.columns; cp++) {
      rg = rp + row;
      cg = cp + column;
      if (at(p, rp, cp) != at(g, rg, cg)) {
        return 0;
      }
    }
  }
  return 1;
}

int solve(grid_t p, grid_t g) {
  int max_row = g.rows - p.rows + 1;
  int max_column = g.columns - p.columns + 1;
  for (int rg = 0; rg < max_row; rg++) {
    for (int cg = 0; cg < max_column; cg++) {
      if (is_pattern(p, g, rg, cg)) {
        return 1;
      }
    }
  }
  return 0;
}

grid_t read_grid(int rows, int columns) {
  grid_t result;
  result.rows = rows;
  result.columns = columns;
  result.values = malloc(sizeof(int) * rows * columns);

  char buf[columns];
  for (int r = 0; r < rows; r++) {
    scanf("%s\n", buf);
    for (int c = 0; c < columns; c++) {
      result.values[r * columns + c] = buf[c];
    }
  }

  return result;
}

void parse_and_solve(void) {
  int r, c;
  scanf("%d %d\n", &r, &c);
  grid_t g = read_grid(r, c);
  scanf("%d %d\n", &r, &c);
  grid_t p = read_grid(r, c);

  int result = solve(p, g);
  char *message = result ? "YES" : "NO";
  printf("%s\n", message);

  free(p.values);
  free(g.values);
}

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 0; i < t; i++) {
    parse_and_solve();
  }

  return 0;
}
