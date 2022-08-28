/* CHALLENGE 2
  Write a program that will sort an array of doubles from lowest to highest using the qsort function.

  void fill_array(double ar[], int n); → Fill the the array with the random values.

  void show_array(const double ar[], int n); → Display the array.

  Output should show the Random List and the Sorted List.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

#define NUMBER_OF_RANDS 50
#define RANDOM_MIN -10
#define RANDOM_MAX 10

typedef enum
{
  ASCENDING,
  DESCENDING,
} sort_order_t;

double random_number_between_two_float(double min, double max)
{
  return (min + ((float)rand() / RAND_MAX) * (max - min));
}

void fill_array(double ar[], int n)
{
  for (int i = 0; i < n; i++)
  {
    ar[i] = random_number_between_two_float(RANDOM_MIN, RANDOM_MAX);
  }
}

void show_array(const double ar[], int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%.2f ", ar[i]);
  }
}

static int comp_double_ascending(const void *p1, const void *p2)
{
  const double i1 = *(const double *)p1; // void to double casting
  const double i2 = *(const double *)p2;
  return i1 - i2;
}

static int comp_double_descending(const void *p1, const void *p2)
{
  const double i1 = *(const double *)p1; // void to double casting
  const double i2 = *(const double *)p2;
  return i2 - i1;
}


void sort_array(double ar[], int n, sort_order_t sort_order)
{
  if (sort_order == ASCENDING)
  {
    qsort(ar, n, sizeof(double), comp_double_ascending);
  }
  else if (sort_order == DESCENDING)
  {
    qsort(ar, n, sizeof(double), comp_double_descending);
  }
}

int main(void)
{
  srand(time(NULL));

  double array[ARRAY_SIZE];
  fill_array(array, ARRAY_SIZE);
  printf("\nRandom Array: ");
  show_array(array, ARRAY_SIZE);
  
  sort_array(array, ARRAY_SIZE, ASCENDING);
  printf("\nSorted Array Ascending: ");
  show_array(array, ARRAY_SIZE);

  sort_array(array, ARRAY_SIZE, DESCENDING);
  printf("\nSorted Array Descending: ");
  show_array(array, ARRAY_SIZE);

}
