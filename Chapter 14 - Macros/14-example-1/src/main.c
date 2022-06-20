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

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main(int argc, char **argv)
{

    printf("\n-------------- BEFORE SORTING ------------\n");
    int arrayNumbers[4] = {12, 8, 3, 15};
    int n = 4;
    int_printArray(arrayNumbers, n);

    printf("\n-------------- USING INT_SORT ------------\n");
    int_sort(arrayNumbers, n);
    int_printArray(arrayNumbers, n);

    int arrayNumbers2[4] = {12, 8, 3, 15};
    printf("\n-------------- USING Q_SORT ------------\n");
    qsort(arrayNumbers2, n, sizeof(int), _DeclareSort_int_Compare);
    int_printArray(arrayNumbers2, n);

    printf("\n-------------- BEFORE SORTING FLOAT------------\n");
    float arrayNumbersFloat[4] = {12.3, 8.4, 15.10, 15.12};
    float_printArray(arrayNumbersFloat, n);

    printf("\n-------------- USING INT_SORT ------------\n");
    float_sort(arrayNumbersFloat, n);
    float_printArray(arrayNumbersFloat, n);

    return 0;
}
