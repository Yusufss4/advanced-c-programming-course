#include <stdio.h>
#include "sum.h"

int sum(int sum) {
  static int savedSum = 0;
  savedSum = savedSum + sum;
  return savedSum;
}