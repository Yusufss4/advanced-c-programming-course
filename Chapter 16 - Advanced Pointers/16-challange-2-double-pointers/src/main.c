/*
# CHALLANGE #2

Write a program that includes a function that modifies a pointers value
- not the value that the pointer is pointing to
- the actual value of the pointer (the address that the pointer is pointing to)

Essentially this program will be simulating "pass by reference" in the C language
- you want to change the value of the pointer passed to a function as the function argument

## Part One:
First, create a function named allocateMemory that takes a single integer pointer as a function parameter
- void allocateMemory(int *ptr);
- this function should allocate memory for this pointer

Now create a main function that does the following:
- creates an integer pointer and initializes it to NULL
- Invokes the allocateMemory function, passing in the integer pointer just created
- assign a value to the integer pointer that it is pointing to (de-reference)
- print the value of what the pointer is pointing to (de-reference)
- free the pointer

## Part Two:
Now modify your program to use a double pointer

Modify the function named allocateMemory to take a double pointer of type int as a function
parameter
- void allocateMemory(int **ptr);
- this function should allocate memory for this pointer (use the correct syntax)

Now modify your main function that does the following:
- creates an integer pointer and initializes it to NULL
- Invokes the allocateMemory function, passing in the address of the integer pointer just created (double pointer)
- assign a value to the integer pointer that it is pointing to (de-reference)
- print the value of what the pointer is pointing to (de-reference
- free the pointer
*/
#include <stdio.h>
#include <stdlib.h>

#define PART_ONE 0

void allocateMemoryPartOne(int *ptr)
{
  ptr = (int *)malloc(sizeof(int)); // allocate memory
  printf("Allocating memory to value of ptr = %p\n", ptr);
  // memory leak created.
}

void allocateMemoryPartTwo(int **ptr)
{
  *ptr = (int *)malloc(sizeof(int)); // allocate memory
  printf("Allocating memory to value of ptr = %p\n", *ptr);
}

int main()
{

  if (PART_ONE)
  {
    int *single_int_ptr = NULL;
    allocateMemoryPartOne(single_int_ptr);
    printf("Adress of single_int_ptr = %p\n", &single_int_ptr);
    printf("Value of single_int_ptr = %p\n", single_int_ptr);

    printf("Before dump..\n");
    *single_int_ptr = 10; // dumps stack trace because memory is allocated on different adress.
    printf("Value of single_int_ptr = %p\n", single_int_ptr);
    printf("Adress of single_int_ptr = %p\n", single_int_ptr);
    printf("De-reference of single_int_ptr = %d\n", single_int_ptr);
    free(single_int_ptr);
  }
  else
  {
    int *double_int_ptr = NULL;
    allocateMemoryPartTwo(&double_int_ptr);
    printf("Adress of double_int_ptr = %p\n", &double_int_ptr);
    printf("Value of double_int_ptr = %p\n", double_int_ptr);

    *double_int_ptr = 10;
    printf("Value of double_int_ptr = %p\n", double_int_ptr);
    printf("Value of *double_int_ptr = %d\n", *double_int_ptr);
    free(double_int_ptr);

    printf("Freeing Memory\n");
    printf("Value of double_int_ptr = %p\n", double_int_ptr);
    printf("Value of *double_int_ptr = %d\n", *double_int_ptr);
  }

  return 0;
}
