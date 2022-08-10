/* 
# CHALLANGE #3

Based on user input, the program will perform the specified operation on two arrays and then display the result, array of function pointers will be used to perform the correct operation. 

- Create an array of function pointers that point to each arithmetic function (add, sub, mult, div)
- Add a fourth parameter to the performOp function so that it takes a function pointer with the signature of the arithmetic functions.
- Pass in the correct function pointer (array index) to the performOp function.
- performOp function should invoke the function pointer and perform the operation on elements of the two arrays passed in and store the result in a third array.
- Display function should display elements of the given array. 
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

// some random numbers
int array1[] = {5, 10, 20, 30, 40, 50, 60, 70, 80, 90,100};
int array2[] = {38, 27, 87, 63, 59, 223, 132, 1, 19, 7,1};

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mult(int a, int b) { return a * b; }
int div(int a, int b) { return a / b; }

/// Array of pointers to functions
int (*calculation[4])(int a, int b) = {&add, &sub, &mult, &div};

// performs the given operation on elements of the arrays
int *performOp(int *a, int *b, int size, int (*calculation_ptr)(int a, int b));

// displays the elements of an array
void display(int *result_array_ptr, int size);

// main method
int main()
{

	int choice = 0;

	// size of the array
	unsigned int size = 0;

	int *result = NULL;

	// set size to minimum size of the two arrays
	size = sizeof(array1);

	if (sizeof(array2) < size)
		size = sizeof(array2);

	size = size / sizeof(int);

	while (choice != 5)
	{
		printf("\n\nWhich operation do you want to perform? \n");
		printf("1.Add \n");
		printf("2.Subtract \n");
		printf("3.Multiply \n");
		printf("4.Divide \n");
		printf("5.None ... \n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		if (choice == 5)
			break;
		if (choice < 1 || choice > 5)
			continue;

		int j = choice - 1;

		result = performOp(array1, array2, size, calculation[j]);

		printf("\n\nThe Results are ...\n");
		display(result, size);

		if (result != NULL)
			free(result);
	}

	return 0;
}

// performs the given operation on all elements of the arrays A and B
int *performOp(int *a, int *b, int size, int (*calculation_ptr)(int a, int b))
{
	int *result_array_ptr = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++)
	{
		result_array_ptr[i] = calculation_ptr(a[i], b[i]);
	}

	return result_array_ptr;
}

// function for displaying the results stored in array result_array_ptr
void display(int *result_array_ptr, int size)
{
	printf("Displaying: ");
	for (int i = 0; i < size; i++)
	{
		printf(" %d ", result_array_ptr[i]);
	}
	printf("\n");
}
