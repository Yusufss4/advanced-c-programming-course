#include <stdio.h>
#include <stdlib.h>

#define DeclareSort(prefix, type)                                     \
    static int                                                        \
        _DeclareSort_##prefix##_Compare(const void *a, const void *b) \
    {                                                                 \
        return (*(type *)a - *(type *)b);                             \
    }                                                                 \
    void                                                              \
        prefix##_sort(type *a, int n)                                 \
    {                                                                 \
        qsort(a, n, sizeof(type), _DeclareSort_##prefix##_Compare);   \
    }

#define DeclarePrintArray(prefix, type, ...) \
    void                                     \
        prefix##_printArray(type *a, int n)  \
    {                                        \
        for (int i = 0; i < n; i++)          \
        {                                    \
            printf(__VA_ARGS__, a[i]);       \
        }                                    \
    }

DeclareSort(int, int);
DeclarePrintArray(int, int, "%d - ");

DeclareSort(float, float);
DeclarePrintArray(float, float, "%.2f - ");

//CHALLENGE #2
#define SUM(a, b) ((a) + (b))

//CHALLENGE #3
#define SQUARE(num) ((num) * (num))
#define CUBE(num) ((num) * (num) * (num))

//CHALLENGE #4
#define IS_UPPER(ch) ( \
    {   if((ch) >= 65 && (ch) <= 90) 1; \
    else 0; \
    } \
);   

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char **argv)
{
    /* CHALLENGE 2 

    int number1 = 0, number2 = 0;
    printf("\nPlease enter two number.");
    printf("\nNumber 1: ");
    scanf("%d", &number1);
    printf("Number 2: ");
    scanf("%d", &number2);
    printf("Sum of number is %d", SUM(number1, number2)); */

    /* CHALLENGE 3

    printf("\nSquare of %d is %d", number1, SQUARE(number1));
    printf("\nCube of %d is %d", number1, CUBE(number1)); */

    /* CHALLENGE 4 */

    char ch;
    printf("\nPlease enter a char: ");
    scanf(" %c", &ch);
    printf("IsUpper %d",IS_UPPER(ch));
    return 0;
}
