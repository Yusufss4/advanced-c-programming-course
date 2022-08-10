#include <stdlib.h>
#include <stdio.h>

int sum(int x, int y, int z) {
  char c = 2;
  int *a;

  *a = 5;

  return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  i = atoi(argv[1]);
  j = atoi(argv[2]);
  k = atoi(argv[3]);

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}
