#include <stdio.h>
void new_func1(void)
{
    printf("\n Inside new_func1()\n");
    int i = 0;
    for(;i<10000000000;i++);
    return;
}