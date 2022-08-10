#include <stdio.h>

// Define macro to find square and cube
#define SQUARE(x) (x * x)
#define CUBE(x) (x * x * x)

int main() {
    int num;

    // Input a number from user
    printf("Enter any number to find square and cube: ");
    scanf("%d", &num);

    // Calculate and print square
    printf("SQUARE(%d) = %d\n", num, SQUARE(num));

    // Calculate and print cube
    printf("CUBE(%d) = %d\n", num, CUBE(num));

    return 0;
}
