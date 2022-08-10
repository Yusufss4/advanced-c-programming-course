#include<stdio.h>

char * reverse(char * str);

int main()
{
    char str[100];
    char *rev = NULL;

    printf("Enter the string: ");
    scanf("%s", str);

    printf("The original string is: %s\n", str);

    rev = reverse(str);

    printf("The reversed string is: %s\n", rev);

    return 0;
}

char * reverse(char *str) {
    static int i = 0;
    static char rev[100];

    if (*str) {
        reverse(str + 1);
        rev[i++] = *str;
    }

    return rev;
}

