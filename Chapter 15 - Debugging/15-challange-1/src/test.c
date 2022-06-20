#include <stdlib.h>
#include <stdio.h>

int Debug = 0;
#ifdef DEBON
#define DEBUG(level, fmt, ...) \
    if (Debug >= level)        \
        fprintf(stderr, fmt, __VA_ARGS__);
#else
#define DEBUG(level, fmt, ...) ;
#endif

int sum(int x, int y, int z)
{
    char c = 2;
    int *a = NULL;

    fprintf(stderr, "In Sum: x=%d\n", x);
    fprintf(stderr, "In Sum: y=%d\n", y);
    fprintf(stderr, "In Sum: z=%d\n", z);
    fprintf(stderr, "In Sum: a=%ld\n", (long)a);

    *a = 5;

    fprintf(stderr, "In Sum: *a=%d\n", *a);

    return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[])
{
    int i, j, k;
    int result;

    fprintf(stderr, "Number of parameters = %d\n", argc);

    if (argc == 1)
    {
        printf("Please specify three numbers as parameters.\n");
        exit(1);
    }

#ifdef DEBON
printf("DEBON defined.\n");
    Debug = atoi(argv[1]);

    DEBUG(1, "Debug=%d\n", Debug);

    i = atoi(argv[2]);

    DEBUG(1, "i=%d\n", i);

    j = atoi(argv[3]);

    DEBUG(1, "j=%d\n", j);

    k = atoi(argv[4]);

    DEBUG(1, "k=%d\n", k);

#else
printf("DEBON not defined.\n");
    i = atoi(argv[1]);

    DEBUG(1, "i=%d\n", i);

    j = atoi(argv[2]);

    DEBUG(1, "j=%d\n", j);

    k = atoi(argv[3]);

    DEBUG(1, "k=%d\n", k);
#endif

    result = sum(i, j, 12) + sum(j, k, 19) + sum(i, k, 13);

    printf("%d\n", result);

    return 0;
}
