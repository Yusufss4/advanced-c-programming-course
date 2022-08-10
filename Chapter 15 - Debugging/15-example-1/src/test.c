//test.c
#include <stdio.h>
void new_func1(void);

void func1(void) {
    printf("\n Inside func1()\n");
    int i = 0;

    for(;i<10000000000;i++);
    new_func1();
    return;
}

static void func2(void) {
    printf("\n Inside func2()\n");
    int i = 0;

    for(;i<10000000000;i++);
    return;
}

int main(void)
{
    printf("\n Inside main()\n");
    int i =0;
    for(;i<10000000000;i++);
    func1();
    func2();
    return 0;
}