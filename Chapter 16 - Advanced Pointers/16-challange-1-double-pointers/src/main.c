/*
CHALLANGE #1

1. create a normal integer variable (non pointer) and assign it a random value
2. create a single integer pointer variable
3. create a double integer pointer variable
4. assign the address of the normal integer variable (step 1) to the single pointer (step 2)
5. assign the address of the single pointer (step 2) to the double pointer (step 3)

Display the following output using all possible syntax
1. all possible ways to find value of the normal integer variable (step 1)
2. all possible ways to find address of the normal integer variable (step 1)
3. all possible ways to find the value of the single pointer variable (step 2)
4. all the possible ways to find the address of the single pointer variable (step 2)
5. all possible ways to print the double pointer value and address (step 3)
*/

#include <stdio.h>
int main ()
{

  int normal_int_value = 5;
  int *single_int_ptr = NULL;
  int **double_int_ptr = NULL;

  single_int_ptr = &normal_int_value;
  double_int_ptr = &single_int_ptr;

  // 1 
  printf ("\nAll possible ways to find value of the normal integer variable\n");
  printf ("Value of normal_int_value = %d\n", normal_int_value);
  printf ("Value of normal_int_value = %d\n", *single_int_ptr);
  printf ("Value of normal_int_value = %d\n", **double_int_ptr);

  // 2 
  printf ("\nAll possible ways to find address of the normal integer variable\n");
  printf ("Address of normal_int_value = %p\n", &normal_int_value);
  printf ("Address of normal_int_value = %p\n", single_int_ptr);
  printf ("Address of normal_int_value = %p\n", *double_int_ptr);

  // 3
  printf ("\nAll possible ways to find the value of the single pointer variable\n");
  printf ("Value of single_int_ptr = %p\n", single_int_ptr);
  printf ("Value of single_int_ptr = %p\n", *double_int_ptr);

  // 4
  printf ("\nAll the possible ways to find the address of the single pointer variable\n");
  printf ("Address of single_int_ptr = %p\n", &single_int_ptr);
  printf ("Address of single_int_ptr = %p\n", double_int_ptr);

  // 5
  printf ("\nAll possible ways to print the double pointer value and address\n");
  printf ("Value of double_int_ptr = %p\n", double_int_ptr);
  printf ("Address of double_int_ptr = %p\n", &double_int_ptr);

  return 0;
}
