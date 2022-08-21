#include <math.h>
#include <assert.h>
#include <stdio.h>


int main()
{
  double x, y, z;
  // Scanf:: On success, the function returns the number of items
  // of the argument list successfully read.
  puts("Enter a pair of numbers (0 0 to quit): ");
  while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0))
  {
    z = x * x - y * y; /* The answer should be + or fail */
    assert(z >= 0);
    printf("Answer is %f\n", sqrt(z));
    puts("Next pair of numbers: ");
  }
  puts("Done");
  return 0;
}