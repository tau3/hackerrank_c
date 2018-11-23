#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH (4 * 1000 + 999 + 1)

void swap(int *nums, int i, int j) {
  int temp = nums[i];
  nums[i] = nums[j];
  nums[j] = temp;
}

int count_insertion_sort(int *nums, int l) {
  int i = 1;
  int swaps = 0;
  while (i < l) {
    int j = i;
    while ((j > 0) && (nums[j - 1] > nums[j])) {
      swap(nums, j, j - 1);
      j--;
      swaps++;
    }
    i++;
  }
  return swaps;
}

int *str_to_ints(char *string, int n) {
  int *result = malloc(sizeof(int) * n);
  result[0] = atoi(strtok(string, " "));
  for (int i = 1; i < n; i++) {
    result[i] = atoi(strtok(NULL, " "));
  }

  return result;
}

int main() {
  int t;
  scanf("%d\n", &t);

  int n, swaps, *nums;
  char string[MAX_LENGTH], *result;
  for (int i = 0; i < t; i++) {
    scanf("%d\n", &n);
    gets(string);
    nums = str_to_ints(string, n);
    swaps = count_insertion_sort(nums, n);
    free(nums);
    result = (swaps % 2) == 0 ? "YES" : "NO";
    printf("%s\n", result);
  }
  return 0;
}
