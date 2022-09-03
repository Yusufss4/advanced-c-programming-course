#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define N 50

int main() {
  int i = 0;
  char str = '\0';

  srand(time(NULL));
  
  printf("%d\n", N);
  
  for (i = 1; i <= N; i++) {
    printf("%0.4lf\n", (rand() % 2001 - 1000) / 2.e3);
  }

  return 0;
}