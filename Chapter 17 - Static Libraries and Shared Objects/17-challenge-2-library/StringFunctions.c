/*
CHALLENGE #2

The goal of this challenge is to create a shared object (dynamic library) and then write a program that uses this library. 

The library and the functions that should include all are the same as the static library challenge. 
So you need to create a StringFunctions.c and StringFunctions.h, after that write a driver program that uses the functions from that library.

gcc -g -fPIC -I../17-challenge-2-library StringFunctions.c -shared -o lib_StringFunctions.so
*/


#include <stdio.h>
#include <StringFunctions.h>
#include <stdlib.h>

/**
 * @brief Remove char.
 *
 * @param str
 * @param char_to_remove
 */
static void removeChar(char *str, char char_to_remove);

int numberOfCharactersInString(char *str, char searchCharacter)
{
  int frequency = 0;
  for (int i = 0; i < lengthOfString(str); i++)
  {
    if (str[i] == searchCharacter)
    {
      frequency++;
    }
  }
  return frequency;
}

int removeNonAlphaCharacters(char *source)
{
    int i = 0, j = 0;

    for(i = 0; source[i] != '\0'; ++i)
    {
        while (!( (source[i] >= 'a' && source[i] <= 'z') || (source[i] >= 'A' && source[i] <= 'Z') || source[i] == '\0') )
        {
            for(j = i; source[j] != '\0'; ++j)
            {
                source[j] = source[j+1];
            }
            source[j] = '\0';
        }
    }

    return 0;
}

static void removeChar(char *source, char char_to_remove)
{
  int i = 0, j = 0;

  for (i = 0; source[i] != '\0'; ++i)
  {
    if (source[i] == char_to_remove)
    {
      for (j = i; source[j] != '\0'; ++j)
      {
        source[j] = source[j + 1];
      }
      source[j] = '\0';
    }
  }
}


int lengthOfString(char *source)
{
  int length_of_string = 0;
  for (length_of_string = 0; source[length_of_string] != '\0'; length_of_string++)
    ;

  return length_of_string;
}

char *strConcat(char *str1, char *str2)
{
  int first_string_lenght = lengthOfString(str1);
  int second_string_lenght = lengthOfString(str2);
  
  size_t string_memory_size = first_string_lenght + second_string_lenght + 1;
  char *string_memory = (char*)malloc((string_memory_size * sizeof(char)));

  printf("sizeof(string_memory): %lu\n",sizeof(string_memory));
  snprintf(string_memory, string_memory_size, "%s%s", str1, str2);
  printf("%s", string_memory);

  return string_memory;
}

int strCopy(char **source, char **destination)
{
  int i = 0;
  for (i = 0; *source[i] != '\0'; ++i)
  {
    *destination[i] = *source[i];
  }

  *source[i] = '\0';
  return 0;
}

int substring(char *source, int from, int n, char *target)
{
  int i = 0;
  int j = 0;
  for (i = 0; source[i] != '\0'; ++i)
  {
    if (i >= from)
    {
      target[j] = source[i];
      j++;
      if (j == n)
      {
        break;
      }
    }
  }

  target[j + 1] = '\0';
  return 1;
}
