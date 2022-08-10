#include <stdio.h>

// Define macro to find sum of two numbers
#define SUM(x, y) (x + y)

int main()
{
    int num1, num2;

    // Input two numbers from user
    printf("Enter any two numbers: ");
    scanf("%d%d", &num1, &num2);

    // Calculate and print sum using macro
    printf("Sum(%d, %d) = %d\n", num1, num2, SUM(num1, num2));

    return 0;
}
