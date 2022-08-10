#include <stdlib.h>
#include <stdio.h>

int sum(int x, int y, int z) {
  char c = 2;
  int *a = NULL;

  fprintf(stderr, "x=%d\n", x);
  fprintf(stderr, "y=%d\n", y);
  fprintf(stderr, "z=%d\n", z);
  fprintf(stderr, "a=%ld\n", (long)a);
  
  *a = 5;

  fprintf(stderr, "*a=%d\n", *a);

  return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[]) {
  int i, j, k;
  int result;

  fprintf(stderr, "Number of parameters = %d\n", argc);

  if (argc == 1) {
     printf("Please specify three numbers as parameters.\n");
     exit(1);
  }

  i = atoi(argv[1]);

  fprintf(stderr, "i=%d\n", i);

  j = atoi(argv[2]);

  fprintf(stderr, "j=%d\n", j);

  k = atoi(argv[3]);

  fprintf(stderr, "k=%d\n", k);

  result = sum(i,j,12) + sum(j,k,19) + sum(i,k,13);

  printf("%d\n", result);

  return 0;
}
