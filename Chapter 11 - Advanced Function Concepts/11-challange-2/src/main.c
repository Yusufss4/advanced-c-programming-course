#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

int sumOfRange(int n);
int findGDC(int num1,int num2);
char *reverse(char*str);

int main(void)
{
    printf("\nSum Of Range = %d",sumOfRange(5));
    printf("GCD = %d",findGDC(10,20));

    char str[100];
    char *rev = NULL;

    printf("Enter the string:");
    scanf("%s",str);

    printf("The original string is: %s\n",str);
    rev = reverse(str);


    return 0;
}


int sumOfRange(int n) {
    int result = 0;
    if(n == 1) {
        return 1;
    }
    else {
        result = n + sumOfRange(n-1);
    }

    return result;
}

int findGDC(int a,int b) {
    while(a != b) {
        if(a>b)
            return findGDC(a-b,b);
        else 
            return findGDC(a,b-a);
    }
    return a;
}

char *reverse(char*str){
    static int i = 0;
    static char rev[100];
    if(*str) {
        reverse(str+1);
        rev[i++] = *str;
    }
}