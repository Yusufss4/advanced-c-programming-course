/* CHALLENGE 1
Write a C program that generates 50 random numbers betwen -0.5 and 0.5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER_OF_RANDS 50
#define MIN -0.5
#define MAX 0.5

/**
 * @brief Returns the random number in float between two float numbers.
 *
 * @param min
 * @param max
 * @return float
 */
float random_number_between_two_float(double min, double max)
{
  return (min + ((float)rand() / RAND_MAX) * (max - min));
}

int main(void)
{
  srand(time(0));
  for (int i = 0; i < 50; i++)
  {
    printf("%.4f", random_number_between_two_float(MIN, MAX)); // 1 to 10
    printf("\n");
  }
  return 0;
}
