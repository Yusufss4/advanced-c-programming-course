/*
CHALLANGE #1

The goal of this challeng to create a static library and then write a program that uses that library.
Create a C source file named “StringFunctions.c” that impelements the string functions, and proper header file that contains the function prototypes.

- Find the frequency of characters in a string
- Remove all the characters in a String except Alphabets
- Calculate the length of a string without using strlen
- Concatenate two strings with using strcat
- Copy a string manually without using strcpy
- Find the substring of a given string

**Function prototoypes:**

- int numberOfCharactersInString(char *str, char searchCharacter);
- int removeNonAlphaCharacters(char *source);
- int lengthOfString(char *source);
- int strConcat(char *str1, char *str2);
- int strCopy(char **source, char* *destination);
- int substring(char *source, int from, int n, char *target);

Create a static library (.a) containing the string manipulation functions.

- lib_stringfunctions.a

Create a program that acts as a driver for your string functions.

- link this program to the static library.
- test all the functions in the library.
*/

#include <stdio.h>
#include <StringFunctions.h>

int main()
{
    char *name = "Yusuf Savas";
    int lenght_of_string = 11;
    printf("Lenght of String: %d\n", lengthOfString(name));
    if (lengthOfString(name) == lenght_of_string)
    {
        printf("Test 1: Passed");
    }
    else
    {
        printf("Test 1: Failed\n");
    }

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