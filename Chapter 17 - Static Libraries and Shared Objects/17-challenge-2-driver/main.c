/*
CHALLENGE #2

The goal of this challenge is to create a shared object (dynamic library) and then write a program that uses this library. 

The library and the functions that should include all are the same as the static library challenge. 
So you need to create a StringFunctions.c and StringFunctions.h, after that write a driver program that uses the functions from that library.
*/

#include <stdio.h>
#include <StringFunctions.h>

int main()
{
    char *name = "Yusuf Savas";
    int lenght_of_string = 11;
    printf("Lenght of String: %d\n", lengthOfString(name));

    char *name2 = "Yusuf Savas";
    char search_character = 'a';
    int freq_of_char = 2;

    printf("Frequency of a char %c: %d\n",search_character,numberOfCharactersInString(name2, search_character));

    char name3[] = "!!!Yusuf11Savas&&?";
    removeNonAlphaCharacters(name3);
    printf("New Name: %s\n",name3);

    #include <string.h>
    char name4[] = "Yusuf";
    char name5[] = "Savas";
    char concat_string[50];
    char copied_char[50];
   // concat_string = strConcat(name4, name5);
    printf("Concat: %s\n",strConcat(name4, name5));


    char name6[] = "Yusuf Savas";
    substring(name6, 6, 5, name6);
    printf("Substring: %s\n",name6);
}